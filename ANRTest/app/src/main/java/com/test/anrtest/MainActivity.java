package com.test.anrtest;

import android.os.SystemClock;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Thread anrtestThread = new Thread(new Runnable() {
            @Override
            public void run() {
                testANR();
            }
        });
        anrtestThread.setName("AnrTest");
        anrtestThread.start();
        SystemClock.sleep(1000);
        initView();

    }

    private synchronized void initView() {
    }

    private synchronized void testANR() {
        SystemClock.sleep(30*1000);
    }
}
