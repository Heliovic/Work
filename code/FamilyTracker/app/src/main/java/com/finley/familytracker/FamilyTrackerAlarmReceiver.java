package com.finley.familytracker;

import android.content.Context;
import android.content.Intent;
import android.support.v4.content.WakefulBroadcastReceiver;
import android.util.Log;

// make sure we use a WakefulBroadcastReceiver so that we acquire a partial wakelock
public class FamilyTrackerAlarmReceiver extends WakefulBroadcastReceiver {
    private static final String TAG = "FamilyTracker";
    @Override
    public void onReceive(Context context, Intent intent) {
        Log.d(TAG,"FamilyTrackerAlarmReceiver onReceive ");
        context.startService(new Intent(context, LocationService.class));
    }
}
