package com.android.server;

import android.app.ActivityManager;
import android.app.AlertDialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.ContentValues;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.content.pm.PermissionInfo;
import android.database.Cursor;
import android.net.Uri;
import android.os.Binder;
import android.os.Build;
import android.os.CountDownTimer;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.IBinder;
import android.os.Parcel;
import android.os.Process;
import android.os.RemoteException;
import android.util.Log;
import android.view.ContextThemeWrapper;
import android.view.WindowManager;
import android.widget.CheckBox;
import android.widget.LinearLayout;
import android.widget.TextView;

import java.lang.SecurityException;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;

import com.asus.cta.CtaChecker;
import com.asus.cta.ICtaService;

import com.android.internal.content.PackageMonitor;
import com.android.internal.R;

import java.io.PrintWriter;
import java.io.FileDescriptor;

import android.app.AppOpsManager;
import android.os.UserHandle;
/**
 * this service will :
 *  <ul> implement the backend of CtaChecker.checkPermission() interface
 *  <ul> use CtaProvider to store android packages's CTA permission(action)
 * state: deny/grant/inquiry
 *  <ul> listen package change(add/remove/update) and update package's
 * CTA permission(action) state to CtaProvider
 *  <ul> listen package's android permission change and update package's
 * CTA permission(action) state to CtaProvider
 *  <ul> access CtaProvider or popup prompt box to query should aurhorize
 * CTA permission(action) accessing of the given package
 *  <ul> support dumsys command to debug
 *
 * @author archie_huang/archie_huang@asus.com
 * @author sven_li/sven_li@asus.com
 * @version 2016.05.30
 */
public class CtaService extends ICtaService.Stub {
    public static final String SERVICE_NAME = "CtaService";
    public static final String TAG = "[CTA]" + "[" + SERVICE_NAME + "]";

    // CTA Provider
    private static final String AUTHORITY = "com.asus.CTA_PROVIDER";
    private static final String TABLE_PERMISSION = "permissions";
    private static final String COL_ACTION = "action";
    private static final String COL_CALLER = "caller";
    private static final String COL_ACCEPT = "accept";
    private static final Uri URI_PERMISSION = Uri.parse("content://" + AUTHORITY + "/" + TABLE_PERMISSION);

    // record the untrusted system apps, always inquiry
    private List<String> BLACKLIST_APPS = new ArrayList<String>();
    // record the trusted third party apps, always grant
    private List<String> WHITELIST_APPS = new ArrayList<String>();

    // CTA record valids in 4 seconds
    private static final long CACHE_PERIOD = 4 * 1000;

    private static final boolean IS_USER_BUILD = "user".equals(Build.TYPE);

    // caller's CTA permission(action) authoriziton state
    private static final int PERMISSION_UNKNOWN = -1;
    private static final int PERMISSION_DENY = 0;
    private static final int PERMISSION_GRANT = 1;
    private static final int PERMISSION_INQUIRY = 2;

    // for user image, cache the inquiry result for a moment, for example :4s
    private static class InquiryCache {
        String caller;
        int action;
        int accept;
        long timeStamp;
    }

    private HashMap<String, HashMap<Integer, InquiryCache>> mInquiryCache = new
                HashMap<String, HashMap<Integer, InquiryCache>>();

    private Handler mHandler;
    private Context mContext;

    //for check app operations
    private AppOpsManager mAppOps;

    /*
     * listen package add/remove/update and then update package's
     * cta permission(action) record in CtaProvider
    */
    private PackageMonitor mPackageMonitor = new PackageMonitor() {

        @Override
        public void onPackageRemoved(String packageName, int uid) {
            logw("onPackageRemoved(): package " + packageName + " removed");
            deletePermission(packageName);
        }

        @Override
        public void onPackageAdded(String packageName, int uid) {
            logw("onPackageAdded(): package " + packageName + " added");

            if (isSystemApp(packageName)) {
                logd("onPackageAdded(): " + packageName + " is trusted system app, ignore");
                return;
            }

            try {
                PackageInfo info = mContext.getPackageManager().getPackageInfo(packageName, PackageManager.GET_PERMISSIONS);

                if (info.requestedPermissions != null) {
                    for (int i = 0; i < info.requestedPermissions.length; i++) {

                        String permission = info.requestedPermissions[i];
                        logd("onPackageAdded(): " + packageName + " , " + permission);
                        for (int action : CtaChecker.androidPermissionToCtaActions(permission)) {
                            if (findPermission(packageName, action)) {
                                continue;
                            } else {
                                insertPermission(packageName, action, PERMISSION_INQUIRY);
                            }
                        }
                    }
                } else {
                    logd("onPackageAdded(): " + packageName + " use no android permission");
                }

            } catch (NameNotFoundException e) {
                loge("onPackageAdded(): get PackageInfo of " + packageName + " exception : " + e.getMessage());
            }
        }

        @Override
        public void onPackageUpdateFinished(String packageName, int uid) {
            logw("onPackageUpdateFinished(): package " + packageName + " updated");

            if (isSystemApp(packageName)) {
                logd("onPackageUpdateFinished(): " + packageName + " is system app, ignore");
                return;
            }

            //todo  delete the not used  cta action after update app
            try {
                PackageInfo info = mContext.getPackageManager().getPackageInfo(packageName, PackageManager.GET_PERMISSIONS);

                if ( (info.requestedPermissions != null) ) {
                    for (int i = 0; i < info.requestedPermissions.length; i++) {

                        String permission = info.requestedPermissions[i];
                        logd("onPackageUpdateFinished(): " + packageName + " use android permission " + permission);
                        for (int action : CtaChecker.androidPermissionToCtaActions(permission)) {
                            if (findPermission(packageName, action)) {
                                continue;
                            } else {
                                insertPermission(packageName, action, PERMISSION_INQUIRY);
                            }
                        }
                    }
                }else{
                    logd("onPackageUpdateFinished(): " + packageName + " use no android permission");
                }
            } catch (NameNotFoundException e) {
                loge("onPackageUpdateFinished(): get PackageInfo of " + packageName + " exception : " + e.getMessage());
            }
        }

    };

    /*
     * receive BOOTCOMPLETED intent then register permission changed receiver
     */
    private class BootCompletedReceiver extends BroadcastReceiver {

        @Override
        public void onReceive(Context context, Intent intent) {

            logw("BootCompletedReceiver : receive boot completed");

            //monitor runtime permission change
            IntentFilter filter1 = new IntentFilter();
            filter1.addAction("android.intent.action.PACKAGE_PERMISSION_CHANGED_TO_CTASERVICE");
            mContext.registerReceiver(new PermissionChangedReceiver(), filter1);

            //monitor app ops change
            IntentFilter filter2 = new IntentFilter();
            filter2.addAction("android.intent.action.PACKAGE_APPOPS_CHANGED_TO_CTASERVICE");
            mContext.registerReceiver(new AppOpsChangedReceiver(), filter2);

            //monitor app data clear
            IntentFilter filter3 = new IntentFilter();
            filter3.addAction(Intent.ACTION_PACKAGE_DATA_CLEARED);
            filter3.addDataScheme("package");
            mContext.registerReceiver(new AppDataClearedReceiver(), filter3);

            //monitor runtime permission flags change
            IntentFilter filter4 = new IntentFilter();
            filter4.addAction("android.intent.action.PACKAGE_PERMISSION_FLAGS_CHANGED_TO_CTASERVICE");
            mContext.registerReceiver(new PermissionFlagsChangedReceiver(), filter4);

            logd("BootCompletedReceiver: now turn off debug log");
            DBGLOG = false;
        }
    }

    /*
     * deal android runtime permission changed in CtaService thread
     */
    private class PermissionChangedHandler implements Runnable {
        private Intent mIntent;

        public PermissionChangedHandler(Intent intent){
            mIntent = intent;
        }

        @Override
        public void run() {
            if ("android.intent.action.PACKAGE_PERMISSION_CHANGED_TO_CTASERVICE".equals(mIntent.getAction())) {
                int uid = mIntent.getIntExtra("uid", -1);
                String packageName = mIntent.getStringExtra("package");
                String permission = mIntent.getStringExtra("permission");
                boolean grant = mIntent.getBooleanExtra("grant", false);

                if (uid < 0 || packageName == null || permission == null) {
                    logd("PermissionChangedHandler: invalid intent");
                    return;
                }

                if (isSystemApp(packageName)) {
                    logd("PermissionChangedHandler: system app " + packageName + ", ignore");
                    return;
                }

                logd("PermissionChangedHandler: " + packageName + ", " + permission + ", " + (grant ? "grant" : "revoke") );

                if (! CtaChecker.isUsefullPermission(permission) ) {
                    return;
                }

                boolean triggeredByCtaAction = false;
                try {
                    int id = mContext.getPackageManager().getPackageUid("com.android.settings", UserHandle.myUserId());
                    triggeredByCtaAction = (id == uid);
                } catch (NameNotFoundException e) {
                    e.printStackTrace();
                }

                if (! grant ) {
                    if (!triggeredByCtaAction) {
                        for (int action : CtaChecker.androidPermissionToCtaActions(permission)) {
                            insertOrUpdatePermission(packageName, action, PERMISSION_INQUIRY);
                        }
                    } else {
                        logd("PermissionChangedHandler: android permission revokeded by cta action state change, ignore it");
                    }

                    return;
                }

                if (!triggeredByCtaAction) {
                    //android permission change by user directly
                    logd("PermissionChangedHandler: android permission granted by user, deal it");
                    for (int action : CtaChecker.androidPermissionToCtaActions(permission)) {
                        //insertOrUpdatePermission(packageName, action, PERMISSION_GRANT);
                        if (queryPermission(packageName, action) != PERMISSION_DENY) {
                            insertOrUpdatePermission(packageName, action, PERMISSION_GRANT);
                        }
                    }
                }
            }
        }
    }

    /*
     * receive android runtime permission changed intent
     */
    private class PermissionChangedReceiver extends BroadcastReceiver {

        @Override
        public void onReceive(Context context, Intent intent) {

            logd("PermissionChangedReceiver: receive " + intent);

            mHandler.post(new PermissionChangedHandler(intent));
        }
    }

    /*
     * deal android runtime permission flags changed in CtaService thread
     */
    private class PermissionFlagsChangedHandler implements Runnable {
        private Intent mIntent;

        public PermissionFlagsChangedHandler(Intent intent){
            mIntent = intent;
        }

        @Override
        public void run() {
            if ("android.intent.action.PACKAGE_PERMISSION_FLAGS_CHANGED_TO_CTASERVICE".equals(mIntent.getAction())) {
                String packageName = mIntent.getStringExtra("package");
                String permission = mIntent.getStringExtra("permission");
                int flagMask = mIntent.getIntExtra("flagmask", -1);
                int flagValues = mIntent.getIntExtra("flagvalues", -1);

                int uid = mIntent.getIntExtra("uid", -1);

                if ( flagMask < 0 || flagValues < 0 || uid < 0 || packageName == null || permission == null ) {
                    logd("PermissionFlagsChangedHandler(): invalid intent");
                }

                if (isSystemApp(packageName)) {
                    logd("PermissionFlagsChangedHandler(): system app " + packageName + ", ignore");
                    return;
                }

                //logd("PermissionFlagsChangedHandler(): " + packageName + ", " + permission);
                logd("PermissionFlagsChangedHandler(): " + packageName + ", " + permission + " flagmask " + flagMask + " flag " + flagValues);
				
                if (! CtaChecker.isUsefullPermission(permission) ) {
                    return;
                }

                boolean triggeredByCtaAction = false;
                try {
                    int id = mContext.getPackageManager().getPackageUid("com.android.settings", UserHandle.myUserId());
                    triggeredByCtaAction = (id == uid);
                } catch (NameNotFoundException e) {
                    e.printStackTrace();
                }

                if (triggeredByCtaAction) {
                    logd("PermissionFlagsChangedHandler(): triggered by cta action state change, ignore");
                    return;
                }

                //only deal user fixed
                if ( (flagMask & flagValues & PackageManager.FLAG_PERMISSION_USER_FIXED) == 0) {
                    logd("PermissionFlagsChangedHandler(): not have flag FLAG_PERMISSION_USER_FIXED, ignore");
                    return;
                }

                if (mContext.getPackageManager().checkPermission(permission, packageName)
                        == PackageManager.PERMISSION_DENIED) {

                    for (int action : CtaChecker.androidPermissionToCtaActions(permission)) {
                       // if (queryPermission(packageName, action) != PERMISSION_INQUIRY ) {
                       //     return;
                        if (queryPermission(packageName, action) == PERMISSION_INQUIRY ) {
                            insertOrUpdatePermission(packageName, action, PERMISSION_DENY);
                        }
                    }

                    /*for (int action : CtaChecker.androidPermissionToCtaActions(permission)) {
                        insertOrUpdatePermission(packageName, action, PERMISSION_DENY);
                    }*/
                }
            }
        }
    }

    /*
     * receive android runtime permission flags changed intent
     */
    private class PermissionFlagsChangedReceiver extends BroadcastReceiver {

        @Override
        public void onReceive(Context context, Intent intent) {

            logd("PermissionFlagsChangedReceiver: receive " + intent);

            mHandler.post(new PermissionFlagsChangedHandler(intent));
        }
    }

    /*
     * deal app ops changed in CtaService thread
     */
    private class AppOpsChangedHandler implements Runnable {
        private Intent mIntent;

        public AppOpsChangedHandler(Intent intent){
            mIntent = intent;
        }

        public void run() {
            if ("android.intent.action.PACKAGE_APPOPS_CHANGED_TO_CTASERVICE".equals(mIntent.getAction())) {
                int pkgUid = mIntent.getIntExtra("pkguid", -1);
                int callerUid = mIntent.getIntExtra("calleruid", -1);
                int op = mIntent.getIntExtra("op", -1);
                String packageName = mIntent.getStringExtra("package");

                if (pkgUid < 0 || callerUid < 0 || op < 0) {
                    logd("AppOpsChangedHandler(): invalid intent");
                    return;
                }

                try {

                    String[] packages;
                    if (packageName == null) {
                        packages = mContext.getPackageManager().getPackagesForUid(pkgUid);
                    } else {
                        packages = new String[]{packageName};
                    }

                    for(String pkg : packages) {
                        if (isSystemApp(pkg)) {
                            logd("AppOpsChangedHandler(): system app " + pkg + ", ignore");
                            continue;
                        }

                        if (!CtaChecker.isUsefullPermission(AppOpsManager.opToPermission(op)) ) {
                            continue;
                        }

                        boolean triggeredByCtaAction = false;
                        int id = mContext.getPackageManager().getPackageUid("com.android.settings", UserHandle.myUserId());
                        triggeredByCtaAction = (id == callerUid);

                        int mode = mAppOps.checkOp(op, pkgUid, pkg);

                        loge("deal pkg : " + pkg + ", op : " + AppOpsManager.opToName(op) + ", mode : " + mode);


                        if (!triggeredByCtaAction) {
                            logd("AppOpsChangedHandler(): app ops granted by user, deal it");
                            if (mode != AppOpsManager.MODE_ALLOWED) {
                                for (int action : CtaChecker.androidPermissionToCtaActions(AppOpsManager.opToPermission(op))) {
                                    insertOrUpdatePermission(pkg, action, PERMISSION_DENY);
                                }
                            } else {
                                for (int action : CtaChecker.androidPermissionToCtaActions(AppOpsManager.opToPermission(op))) {
                                    insertOrUpdatePermission(pkg, action, PERMISSION_GRANT);
                                }
                            }
                        } else  {
                            logd("AppOpsChangedHandler(): app ops granted by cta action state change, ignore it");
                        }
                    }
                } catch(Exception e) {
                    logw("AppOpsChangedHandler(): exception: " + e.getMessage());
                    e.printStackTrace();
                }
            }
        }
    }

    /*
     * receive appops changed intent
     */
    private class AppOpsChangedReceiver extends BroadcastReceiver {

        @Override
        public void onReceive(Context context, Intent intent) {

            logd("AppOpsChangedReceiver : receive " + intent);

            mHandler.post(new AppOpsChangedHandler(intent));
        }
    }

    /*
     * deal app data cleared in CtaService thread
     */
    private class AppDataClearedHandler implements Runnable {
        private Intent mIntent;

        public AppDataClearedHandler(Intent intent){
            mIntent = intent;
        }

        public void run() {
            if (Intent.ACTION_PACKAGE_DATA_CLEARED.equals(mIntent.getAction())) {

                try {
                    Uri data = mIntent.getData();
                    if (data == null) {
                        loge("can't get intent data, ignore");
                        return;
                    }

                    String packageName = data.getSchemeSpecificPart();

                    PackageInfo packageInfo = mContext.getPackageManager().getPackageInfo(packageName, PackageManager.GET_PERMISSIONS);
                    if (packageInfo.applicationInfo.targetSdkVersion <= Build.VERSION_CODES.LOLLIPOP_MR1) {
                        logd(packageName + " don't support runtime permission, ignore");
                        return;
                    }

                    String[] requiredPermissions = packageInfo.requestedPermissions;

                    for (String permission : requiredPermissions) {
                        if (CtaChecker.isUsefullPermission(permission)) {
                            for (int action : CtaChecker.androidPermissionToCtaActions(permission)) {
                                insertOrUpdatePermission(packageName, action, PERMISSION_INQUIRY);
                            }
                        }
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }

    }


    /*
     * receive app data cleared intent
     */
    private class AppDataClearedReceiver extends BroadcastReceiver {

        @Override
        public void onReceive(Context context, Intent intent) {

            logd("AppDataClearedReceiver : receive " + intent);

            mHandler.post(new AppDataClearedHandler(intent));
        }
    }

    private String acceptToString(int accept)
    {
        if (accept == PERMISSION_DENY)
            return "deny";
        else if (accept == PERMISSION_GRANT)
            return "grant";
        else if (accept == PERMISSION_INQUIRY)
            return "inquiry";
        else
            return "unknown";
    }

    private class PermissionChecker extends BroadcastReceiver implements Runnable {
        Object checkLock = new Object();
        AlertDialog mCurrentDialog = null;
        int mAction;
        String mCaller;
        boolean mResult = false;

        PermissionChecker(int action, String caller) {
            mAction = action;
            mCaller = caller;
        }

        public boolean getResult() {
            return mResult;
        }

        @Override
        public void onReceive(Context context, Intent intent) {

            logd("onReceive(): receive " + intent);

            if (mCurrentDialog != null) {
                //mCurrentDialog.dismiss();
            }

            synchronized(checkLock) {
                checkLock.notifyAll();
            }
        }

        @Override
        public void run() {

            int accept = PERMISSION_INQUIRY;

            logw("run():  checke " + mCaller + ", " + (new CtaChecker(mContext)).getAction(mAction));

            synchronized (checkLock) {

                // always grant photograph and recording for user img
                if (IS_USER_BUILD) {
                    if ( mAction == CtaChecker.CTA_PHOTOGRAPH || mAction == CtaChecker.CTA_PICTURE_RECORDING ) {
                        mResult = true;
                        checkLock.notifyAll();
                        return;
                    }
                }

                // always grant whitelist third party app
                if (isWhiteListApp(mCaller)){
                    mResult = true;
                    logd("run(): whitelist third party app " + mCaller + ", always grant");
                    checkLock.notifyAll();
                    return;
                }

                // always grant the trusted system app
                if (isSystemApp(mCaller) && ! isBlackListApp(mCaller) ) {
                    mResult = true;
                    logd("run(): system app " + mCaller + ", always grant");
                    checkLock.notifyAll();
                    return;
                }

                if ( ! isBlackListApp(mCaller)) {
                    accept = queryPermission(mCaller, mAction);

                    if (IS_USER_BUILD) {
                        // if need to quiry user to choose, search inquiry cache first
                        if (accept == PERMISSION_INQUIRY || accept == PERMISSION_UNKNOWN ) {
                            accept = queryInquiryCache(mCaller, mAction);
                        }
                    }

                    if (accept == PERMISSION_DENY || accept == PERMISSION_GRANT ) {
                        mResult = (accept == PERMISSION_GRANT);
                        checkLock.notifyAll();
                        return;
                    }
                } else {
                    logd("run(): blacklist system app " + mCaller + ", always inquiry");
                }
                showDialog();
            }
        }

        private void showDialog() {

            logd("showDialog(): show CTA permission prompt dialog");
            CtaChecker checker = new CtaChecker(mContext);

            LinearLayout view = new LinearLayout(mContext);
            view.setOrientation(LinearLayout.VERTICAL);
            int padding = 30;
            view.setPadding(padding, padding, padding, padding);

            TextView message = new TextView(mContext);
            String msg = checker.getMessage(mAction, getAppName(mCaller));
            message.setText(msg);
            message.setTextSize(18);
            view.addView(message);

            TextView wizard = new TextView(mContext);
            wizard.setText(mContext.getResources().getString(R.string.cta_ckb_config_wizard));
            wizard.setTextSize(15);
            view.addView(wizard);

            final CheckBox checkBox = new CheckBox(mContext);
            checkBox.setText(mContext.getResources().getString(R.string.cta_ckb_no_next_time));
            checkBox.setTextSize(15);
            view.addView(checkBox);

            AlertDialog.Builder builder = new AlertDialog.Builder(mContext);
            builder.setTitle(checker.getAction(mAction));
            builder.setView(view);
            builder.setCancelable(false);

            DialogInterface.OnClickListener onClickListener = new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    int accept =  PERMISSION_UNKNOWN;

                    if (which == DialogInterface.BUTTON_POSITIVE) {
                        synchronized (checkLock) {
                            accept =  PERMISSION_GRANT;
                            mResult = true;

                            logd("showDialog(): user choose grant");

                            if (IS_USER_BUILD ) {
                                updateInquiryCache(mCaller, mAction, PERMISSION_GRANT);
                            }
                            checkLock.notifyAll();
                        }
                    }
                    else if (which == DialogInterface.BUTTON_NEGATIVE) {
                        synchronized (checkLock) {
                            accept =  PERMISSION_DENY;
                            mResult = false;

                            logd("showDialog(): user choose deny");

                            if (IS_USER_BUILD ) {
                                updateInquiryCache(mCaller, mAction, PERMISSION_DENY);
                            }
                            checkLock.notifyAll();
                        }
                    }

                    if (checkBox.isChecked() && ! isBlackListApp(mCaller)) {
                        mHandler.post(new PermissionUpdater(mCaller, mAction, accept));
                    }
                }
            };

            String allow = mContext.getResources().getString(R.string.cta_btn_allow);
            final String deny = mContext.getResources().getString(R.string.cta_btn_deny);

            builder.setPositiveButton(allow, onClickListener);
            builder.setNegativeButton(deny, onClickListener);
            builder.setOnDismissListener(new DialogInterface.OnDismissListener() {

                @Override
                public void onDismiss(DialogInterface dialog) {

                    logd("showDialog(): CTA permission prompt dialog dismiss");

                    mCurrentDialog = null;
                }
            });

            mCurrentDialog= builder.create();
            mCurrentDialog.getWindow().setType(WindowManager.LayoutParams.TYPE_SYSTEM_DIALOG);
            mCurrentDialog.show();

            new CountDownTimer(20000, 1000) {

                @Override
                public void onTick(long millisUntilfinished) {
                    if (mCurrentDialog != null) {
                        mCurrentDialog.getButton(DialogInterface.BUTTON_NEGATIVE).setText(deny + " (" + (millisUntilfinished / 1000) + ")");
                    }
                    else {
                        cancel();
                    }
                }

                @Override
                public void onFinish() {
                    if (mCurrentDialog != null) {
                        mCurrentDialog.dismiss();
                    }

                    synchronized(checkLock) {
                        checkLock.notifyAll();
                    }
                }
            }.start();
        }
    }

    private int queryInquiryCache(String caller, int action) {
        HashMap<Integer, InquiryCache> appRecords = mInquiryCache.get(caller);
        if (appRecords != null) {
            InquiryCache record = appRecords.get(action);
            if (record != null) {
                long curTime = System.currentTimeMillis();
                if ((curTime - record.timeStamp) <= CACHE_PERIOD) {
                    logd("quiryInquiryCache(): find valid permission cache : " + caller + ", "  + (new CtaChecker(mContext)).getAction(action) +
                        ", " + acceptToString(record.accept) );
                    return record.accept;
                }
            }
        }

        logd("quiryInquiryCache(): not find valid permission cache: " + caller + ", "  + (new CtaChecker(mContext)).getAction(action) );
        return PERMISSION_UNKNOWN;
    }

    private void updateInquiryCache(String caller, int action, int accept) {
        HashMap<Integer, InquiryCache> appRecords = mInquiryCache.get(caller);
        if (appRecords == null) {
            appRecords = new HashMap<Integer, InquiryCache>();
            mInquiryCache.put(caller, appRecords);
        }

        InquiryCache record = appRecords.get(action);
        if (record == null) {
            record = new InquiryCache();
            appRecords.put(action, record);
        }

        record.action = action;
        record.caller = caller;
        record.accept = accept;
        record.timeStamp = System.currentTimeMillis();

        logd("updateInquiryCache(): " + caller + ", "  + (new CtaChecker(mContext)).getAction(action) +
                        ", " + acceptToString(record.accept));
    }

    private boolean findPermission(String caller, int action) {
        Cursor c = null;
        String selection = COL_ACTION + "=? AND " + COL_CALLER + "=?";
        String[] selectionArgs = new String[] { Integer.toString(action), caller};

        try {
            c = mContext.getContentResolver().query(URI_PERMISSION, new String[] { COL_ACCEPT }, selection, selectionArgs, null);
            if (c != null && c.getCount() > 0) {
                logd("findPermission(): " + caller + ", " + (new CtaChecker(mContext)).getAction(action));
                return true;
            }
        } catch (Exception e) {
            loge("findPermission(): exception : " + e.getMessage());
        } finally {
            if (c != null) {
                c.close();
            }
        }

        return false;
    }

    private int queryPermission(String caller, int action) {

        int accept = PERMISSION_UNKNOWN;
        Cursor c = null;

        try {
            String selection = COL_ACTION + "=? AND " + COL_CALLER + "=?";
            String[] selectionArgs = new String[] { Integer.toString(action), caller};
            c = mContext.getContentResolver().query(URI_PERMISSION, new String[] { COL_ACCEPT }, selection, selectionArgs, null);
            if (c != null && c.getCount() > 0) {
                c.moveToFirst();
                accept = c.getInt(c.getColumnIndex(COL_ACCEPT));

                logd("queryPermission(): result : " + caller + ", "  + (new CtaChecker(mContext)).getAction(action) +
                        ", " + acceptToString(accept) );
            }
        } catch (Exception e) {
            logw("queryPermission() exception: " + e.getMessage());
        } finally {
            if (c != null) {
                c.close();
            }
        }

        if ( (accept != PERMISSION_GRANT)  && (accept != PERMISSION_DENY) && (accept != PERMISSION_INQUIRY) )
            accept = PERMISSION_UNKNOWN;

        return accept;
    }

    private void deletePermission(String caller) {
        try {
            String selection = COL_CALLER + "='" + caller + "'";
            mContext.getContentResolver().delete(URI_PERMISSION, selection, null);
            logd("deletePermission(): delete all permission record of " + caller + " from CtaProvider");
        }
        catch(Exception e) {
            logw("deletePermission(): exception: " + e.getMessage());
        }
    }

    private void deletePermission(String caller, int action) {
        try {
            String selection = COL_ACTION + "=? AND " + COL_CALLER + "=?";
            String[] selectionArgs = new String[] { Integer.toString(action), caller};
            mContext.getContentResolver().delete(URI_PERMISSION, selection, selectionArgs);
            logd("deletePermission(): delete " + caller + ", " + (new CtaChecker(mContext)).getAction(action) + " from CtaProvider");
        }
        catch(Exception e) {
            logw("deletePermission(): exception: " + e.getMessage());
        }
    }

    private void insertPermission(String caller, int action, int accept) {
        ContentValues values = new ContentValues();
        values.put("action", action);
        values.put("caller", caller);
        values.put("accept", accept);

        try {
            mContext.getContentResolver().insert(URI_PERMISSION, values);
            logd("insertPermission(): " + caller + ", " + (new CtaChecker(mContext)).getAction(action) + ", " + acceptToString(accept));
        } catch (Exception e) {
            logw("insertPermission(): exception: " + e.getMessage());
        }
    }

    private void updatePermission(String caller, int action, int accept) {
        String selection = COL_ACTION + "=? AND " + COL_CALLER + "=?";
        String[] selectionArgs = new String[] { Integer.toString(action), caller};

        ContentValues values = new ContentValues();
        values.put("accept", accept);

        try {
            mContext.getContentResolver().update(URI_PERMISSION, values, selection, selectionArgs);
            logd("updatePermission(): " + caller + ", " + (new CtaChecker(mContext)).getAction(action) + ", " + acceptToString(accept));
        } catch (Exception e) {
            logw("updatePermission() exception: " + e.getMessage());
        }
    }

    private void insertOrUpdatePermission(String caller, int action, int accept) {
        if (findPermission(caller, action)) {
            updatePermission(caller, action, accept);
        }else{
            insertPermission(caller, action, accept);
        }
    }

    private class PermissionUpdater implements Runnable {
        String mCaller;
        int mAction;
        int mAccept;

        public PermissionUpdater(String caller, int action, int accept) {
            mCaller = caller;
            mAction = action;
            mAccept = accept;
        }

        @Override
        public void run() {
            insertOrUpdatePermission(mCaller, mAction, mAccept);
            if (isSupportRuntimePermission(mCaller)) {
                syncAndroidRuntimePermission(mCaller, mAction, mAccept);
            } else {
                syncAndroidAppOps(mCaller, mAction, mAccept);
            }
        }
    }

    private boolean isSystemApp(String packageName){

        boolean isSystemApp = false;

        try {
            ApplicationInfo app = mContext.getPackageManager().getApplicationInfo(packageName, PackageManager.GET_ACTIVITIES);
            if ((app.flags & ApplicationInfo.FLAG_SYSTEM) != 0) {
                isSystemApp = true;
            } else if (app.uid == Process.SYSTEM_UID) {
                isSystemApp = true;
            }
        } catch (NameNotFoundException e) {
            logw("isSystemApp(): exception: " + e.getMessage());
        }

        return isSystemApp;
    }

    private boolean isSupportRuntimePermission(String packageName) {

        try {
            ApplicationInfo app = mContext.getPackageManager().getApplicationInfo(packageName, PackageManager.GET_ACTIVITIES);
            return app.targetSdkVersion > Build.VERSION_CODES.LOLLIPOP_MR1;

        } catch (Exception e) {
            logw("isSystemApp(): exception: " + e.getMessage());
        }

        return false;
    }	
	
	
    private boolean isBlackListApp(String packageName) {

        boolean isBlackListApp = false;

        for (String app : BLACKLIST_APPS) {
            if (app.equals(packageName)) {
                isBlackListApp = true;
                break;
            }
        }

        return isBlackListApp;
    }

    private boolean isWhiteListApp(String packageName) {

        boolean isWhiteListApp = false;

        for (String app : WHITELIST_APPS) {
            if (app.equals(packageName)) {
                isWhiteListApp = true;
                break;
            }
        }

        return isWhiteListApp;
    }

    private String getAppName(String packageName) {
        String appName = packageName;
        PackageManager pm = mContext.getPackageManager();
        try {
            ApplicationInfo appInfo = pm.getApplicationInfo(packageName, PackageManager.GET_ACTIVITIES);
            appName = appInfo.loadLabel(pm).toString();
        } catch (android.content.pm.PackageManager.NameNotFoundException ex) {
        }
        return appName;
    }

	
    private void syncAndroidRuntimePermission(String packageName, int action, int accept) {

        logd("syncAndroidRuntimePermission(): " + packageName + " " + action + " " + accept);

        PackageManager packageManager = null;
        PackageInfo packageInfo = null;
        List<String> requiredPermissions = null;

        try {
            packageManager = mContext.getPackageManager();
            packageInfo =  packageManager.getPackageInfo(packageName, PackageManager.GET_PERMISSIONS);
            requiredPermissions = Arrays.asList(packageInfo.requestedPermissions);

            for (String permission : CtaChecker.ctaActionToAndroidRuntimePermissions(action)) {
                if (!requiredPermissions.contains(permission)) {
                    continue;
                }

                PermissionInfo permissionInfo = packageManager.getPermissionInfo(permission, 0);
                String group = permissionInfo.group;
                List<PermissionInfo>  permInfos = packageManager.queryPermissionsByGroup(group, 0);

                int grantedCtaActionsCount = 0;
                int inquiriedCtaActionsCount = 0;
                int deniedCtaActionsCount = 0;

                Iterator<PermissionInfo> it = permInfos.iterator();

                while(it.hasNext()) {
                    String name = it.next().name;
                    if(!requiredPermissions.contains(name)) {
                        it.remove();
                    }
                }

               for(PermissionInfo pi : permInfos) {
                    for ( int act : CtaChecker.androidRuntimePermissionToCtaActions(pi.name) ) {
                        int state = queryPermission(packageName, act);

                        if (state == PERMISSION_INQUIRY )  {
                            inquiriedCtaActionsCount++;
                        } else if (state == PERMISSION_DENY ) {
                            deniedCtaActionsCount++;
                        } else if (state == PERMISSION_GRANT ) {
                            grantedCtaActionsCount++;
                        }
                    }
                }

                //temp add --
                if ( grantedCtaActionsCount == 0 ) {
                    if (inquiriedCtaActionsCount == 0 ) {
                        for(PermissionInfo pi : permInfos) {
                            logd("syncAndroidRuntimePermission():  revoke " + packageName + " " + pi.name);
                            packageManager.revokeRuntimePermission(packageName, pi.name, new UserHandle(UserHandle.myUserId() ));
                            packageManager.updatePermissionFlags(pi.name, packageName,
                                            PackageManager.FLAG_PERMISSION_USER_FIXED | PackageManager.FLAG_PERMISSION_USER_SET,
                                            PackageManager.FLAG_PERMISSION_USER_FIXED,
                                            new UserHandle(UserHandle.myUserId()));
                        }
                    } else {
                        for(PermissionInfo pi : permInfos) {
                            logd("syncAndroidRuntimePermission():  revoke " + packageName + " " + pi.name);
                            packageManager.revokeRuntimePermission(packageName, pi.name, new UserHandle(UserHandle.myUserId() ));
                            packageManager.updatePermissionFlags(pi.name, packageName,
                                            PackageManager.FLAG_PERMISSION_USER_FIXED | PackageManager.FLAG_PERMISSION_USER_SET,
                                            PackageManager.FLAG_PERMISSION_USER_SET,
                                            new UserHandle(UserHandle.myUserId()));
                        }

                    }
                } else {
                    for(PermissionInfo pi : permInfos) {
                        logd("syncAndroidRuntimePermission():  grant " + packageName + " " + pi.name);
                        packageManager.grantRuntimePermission(packageName, pi.name, new UserHandle(UserHandle.myUserId() ));
                        packageManager.updatePermissionFlags(pi.name, packageName,
                                        PackageManager.FLAG_PERMISSION_USER_FIXED | PackageManager.FLAG_PERMISSION_USER_SET,
                                        PackageManager.FLAG_PERMISSION_USER_SET,
                                        new UserHandle(UserHandle.myUserId()));
                    }
                }
            }

        } catch (Exception e) {
            logw("syncAndroidRuntimePermission(): exception");
            e.printStackTrace();
            return;
        }
    }

    private void syncAndroidAppOps(String packageName, int action, int accept) {
        logd("syncAndroidAppOps(): " + packageName + " " + action + " " + accept);

        AppOpsManager appOpsManager = null;
        PackageManager packageManager = null;
        PackageInfo packageInfo = null;
        List<String> requiredPermissions = null;

        try {
            appOpsManager = (AppOpsManager)mContext.getSystemService(Context.APP_OPS_SERVICE);
            packageManager = mContext.getPackageManager();
            packageInfo =  packageManager.getPackageInfo(packageName, PackageManager.GET_PERMISSIONS);
            requiredPermissions = Arrays.asList(packageInfo.requestedPermissions);
            int uid = packageInfo.applicationInfo.uid;

            for (String permission : CtaChecker.ctaActionToAndroidRuntimePermissions(action)) {
                if (!requiredPermissions.contains(permission)) {
                    continue;
                }

                PermissionInfo permissionInfo = packageManager.getPermissionInfo(permission, 0);
                String group = permissionInfo.group;
                List<PermissionInfo>  permInfos = packageManager.queryPermissionsByGroup(group, 0);

                int grantedCtaActionsCount = 0;
                int inquiriedCtaActionsCount = 0;
                int deniedCtaActionsCount = 0;

                Iterator<PermissionInfo> it = permInfos.iterator();

                while(it.hasNext()) {
                    String name = it.next().name;
                    if(!requiredPermissions.contains(name)) {
                        it.remove();
                    }
                }

                for(PermissionInfo pi : permInfos) {
                    for ( int act : CtaChecker.androidRuntimePermissionToCtaActions(pi.name) ) {
                        int state = queryPermission(packageName, act);

                        if (state == PERMISSION_INQUIRY )  {
                            inquiriedCtaActionsCount++;
                        } else if (state == PERMISSION_DENY ) {
                            deniedCtaActionsCount++;
                        } else if (state == PERMISSION_GRANT ) {
                            grantedCtaActionsCount++;
                        }
                    }
                }

                if ( inquiriedCtaActionsCount == 0 && grantedCtaActionsCount == 0 ) {
                    for(PermissionInfo pi : permInfos) {
                        logd("syncAndroidAppOps():  IGNORE pkg: " + pi.name + ", AppOps :" + AppOpsManager.permissionToOp(pi.name));
                        appOpsManager.setUidMode(AppOpsManager.permissionToOpCode(pi.name), uid, AppOpsManager.MODE_IGNORED);
                    }
                } else {
                    for(PermissionInfo pi : permInfos) {
                        logd("syncAndroidAppOps():  ALLOW pkg: " + pi.name + ", AppOps : " + AppOpsManager.permissionToOp(pi.name));
                        appOpsManager.setUidMode(AppOpsManager.permissionToOpCode(pi.name), uid, AppOpsManager.MODE_ALLOWED);
                    }
                }
            }
        } catch (Exception e) {
            logw("syncAndroidRuntimePermission(): exception");
            e.printStackTrace();
            return;
        }
    }	

    public CtaService(Context context) {
        int deviceThemeRes = android.R.style.Theme_DeviceDefault_Light;
        mContext = new ContextThemeWrapper(context, deviceThemeRes);
        HandlerThread thread = new HandlerThread(SERVICE_NAME);
        thread.start();
        mHandler = new Handler(thread.getLooper());
    }

    public void systemReady() {

        mPackageMonitor.register(mContext, mHandler.getLooper(), true);

        IntentFilter filter = new IntentFilter();
        filter.addAction(Intent.ACTION_BOOT_COMPLETED);
        mContext.registerReceiver(new BootCompletedReceiver(), filter);
        logw("systemReady() : register boot completed receiver");

        mAppOps = (AppOpsManager)mContext.getSystemService(Context.APP_OPS_SERVICE);
    }

    @Override
    public boolean onTransact(int code, Parcel data, Parcel reply, int flags)
            throws RemoteException {
        switch(code) {
            case 1000: {
                data.enforceInterface("com.asus.cta.ICtaService");
                IBinder b = data.readStrongBinder();
                int action = data.readInt();
                String caller = data.readString();
                boolean result = checkPermission(action, caller);
                reply.writeNoException();
                reply.writeInt(result ? 1 : 0);
                return true;
            }
        }
        return super.onTransact(code, data, reply, flags);
    }

    @Override
    public boolean checkPermission(int action, String caller) throws RemoteException {
        boolean result = false;

        PermissionChecker permissionChecker = new PermissionChecker(action, caller);

        IntentFilter filter = new IntentFilter();
        filter.addAction(Intent.ACTION_CONFIGURATION_CHANGED);
        mContext.registerReceiver(permissionChecker, filter);

        synchronized (permissionChecker.checkLock) {
            mHandler.post(permissionChecker);
            try {
                permissionChecker.checkLock.wait();
                result =  permissionChecker.getResult();
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        mContext.unregisterReceiver(permissionChecker);

        return result;
    }

    /*
     * debug flag and function
     */
    private static boolean DBGLOG = ! IS_USER_BUILD;

    private static void logd(String msg) {
        if(DBGLOG)
            Log.d(TAG, msg);
    }

    private static void logw(String msg) {
        Log.w(TAG, msg);
    }

    private static void loge(String msg) {
        Log.e(TAG, msg);
    }

    @Override
    protected void dump(FileDescriptor fd, PrintWriter pw, String[] args){

        if (mContext.checkCallingOrSelfPermission(android.Manifest.permission.DUMP)
                != PackageManager.PERMISSION_GRANTED) {

            pw.println("Permission Denial: can't dump LocationManagerService from from pid="
                    + Binder.getCallingPid()
                    + ", uid=" + Binder.getCallingUid());
            return;
        }

        if (args.length > 1 ) {
            switch( args[0] ) {

                case "DBGLOG" :
                    DBGLOG = Boolean.parseBoolean(args[1]);
                    logw("dump(): set DBGLOG to " + DBGLOG);
                    return;

                case "ADDBLACK" :
                    if (! IS_USER_BUILD) {
                        //if (mContext.getPackageManager().isPackageAvailable(args[1])) {
                            if ( ! isSystemApp(args[1])) {
                                return;
                            }
                            for (String pkg : BLACKLIST_APPS) {
                                if (pkg.equals(args[1]) ) {
                                    return;
                                }
                            }
                            BLACKLIST_APPS.add(args[1]);
                            logw("dump(): add system app " + args[1] + " to blacklist");
                        //} else {
                        //    logw("dump(): unavaliable package " + args[1] + "ignore");
                        //}
                    }
                    return;

                case "DELBLACK" :
                    if (! IS_USER_BUILD) {
                        //if (mContext.getPackageManager().isPackageAvailable(args[1])) {
                            if ( ! isSystemApp(args[1])) {
                                return;
                            }
                            for (String pkg : BLACKLIST_APPS) {
                                if (pkg.equals(args[1]) ) {
                                    BLACKLIST_APPS.remove(args[1]);
                                    logw("dump(): delete system app " + args[1] + " from blacklist");
                                    return;
                                }
                            }
                        //} else {
                        //    logw("dump(): unavaliable package " + args[1] + "ignore");
                        //}
                    }
                    return;

                case "ADDWHITE" :
                    if (! IS_USER_BUILD) {
                        //if (mContext.getPackageManager().isPackageAvailable(args[1])) {
                            if (isSystemApp(args[1])) {
                                return;
                            }
                            for (String pkg : WHITELIST_APPS) {
                                if (pkg.equals(args[1]) ) {
                                    return;
                                }
                            }
                            WHITELIST_APPS.add(args[1]);
                            logw("dump(): add third party app " + args[1] + " to whitelist");
                        //} else {
                        //    logw("dump(): unavaliable package " + args[1] + ", ignore");
                        //}
                    }
                    return;

                case "DELWHITE" :
                    if (! IS_USER_BUILD) {
                        //if (mContext.getPackageManager().isPackageAvailable(args[1])) {
                            if (isSystemApp(args[1])) {
                                return;
                            }
                            for (String pkg : WHITELIST_APPS) {
                                if (pkg.equals(args[1]) ) {
                                    WHITELIST_APPS.remove(args[1]);
                                    logw("dump(): delete third party app " + args[1] + " from whitelist");
                                    return;
                                }
                            }
                        //} else {
                        //    logw("dump(): unavaliable package " + args[1] + ", ignore");
                        //}
                    }
                    return;

                case "-h" :
                case "help" :
                default :
                    return;
            }
        }

        if (args.length == 1 ) {
            pw.println("usage of 'dumpsys CTA_SERVICE' :");
            pw.println("    dumpsys CTA_SERVICE :                       dump state");
            pw.println("    dumpsys CTA_SERVICE <-h | help> :           print these usage info");
            pw.println("    dumpsys CTA_SERVICE DBGLOG <true | false> : enable/disable debug log");
            if (! IS_USER_BUILD ) {
                pw.println("    dumpsys CTA_SERVICE ADDBLACK <package> :    tag system app as untrusted");
                pw.println("    dumpsys CTA_SERVICE DELBLACK <package> :    revert tag system app as untrusted");
                pw.println("    dumpsys CTA_SERVICE ADDWHITE <package> :    tag third party app as untrusted");
                pw.println("    dumpsys CTA_SERVICE DELWHITE <package> :    revert tag third party app as untrusted");
            }
        } else {
            pw.println("CtaService State:");
            pw.println("    DBGLOG = " + DBGLOG + " (debug log)");
            pw.println("    PERIOD = " + CACHE_PERIOD + "ms (valid time for inquiry cache)");

            if (! IS_USER_BUILD ) {
                pw.println("");
                pw.println("BalckList: ");
                for (String pkg : BLACKLIST_APPS) {
                    pw.println("    " + pkg);
                }

                pw.println("");
                pw.println("WhiteList: ");
                for (String pkg : WHITELIST_APPS) {
                    pw.println("    " + pkg);
                }
                pw.println("");
            }
        }
    }

}
