package com.finley.familytracker;

import android.app.AlarmManager;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.SystemClock;

public class FamilyTrackerBootReceiver extends BroadcastReceiver {
    private static final String TAG = "FamilyTracker";
    @Override
    public void onReceive(Context context, Intent intent) {
        AlarmManager alarmManager = (AlarmManager)context.getSystemService(Context.ALARM_SERVICE);
        Intent gpsTrackerIntent = new Intent(context, FamilyTrackerAlarmReceiver.class);
        PendingIntent pendingIntent = PendingIntent.getBroadcast(context, 0, gpsTrackerIntent, 0);

        SharedPreferences sharedPreferences = context.getSharedPreferences("com.finley.familytracker.prefs", Context.MODE_PRIVATE);
        int intervalInMinutes = sharedPreferences.getInt("intervalInMinutes", 1);
        Boolean currentlyTracking = sharedPreferences.getBoolean("currentlyTracking", false);

        if (currentlyTracking) {
            alarmManager.setRepeating(AlarmManager.ELAPSED_REALTIME_WAKEUP,
                    SystemClock.elapsedRealtime(),
                    intervalInMinutes * 60000, // 60000 = 1 minute,
                    pendingIntent);
        } else {
            alarmManager.cancel(pendingIntent);
        }
    }
}
