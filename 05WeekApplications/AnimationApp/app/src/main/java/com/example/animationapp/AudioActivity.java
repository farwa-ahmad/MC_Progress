package com.example.animationapp;

import androidx.appcompat.app.AppCompatActivity;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class AudioActivity extends AppCompatActivity {

    Button btnPlay, btnPause;
    MediaPlayer mp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_audio);
    mp = MediaPlayer.create(this, R.raw.audio);
    btnPause = findViewById(R.id.btnPause);
    btnPlay = findViewById(R.id.btnPlay);

    btnPause.setOnClickListener(new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            mp.pause();
        }
    });

    btnPlay.setOnClickListener(new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            mp.start();
        }
    });

    }
}