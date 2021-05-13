package com.example.animationapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {

    ImageView ivStar;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ivStar = findViewById(R.id.ivStar);

        ivStar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ivStar.animate().alpha(0).translationXBy(1000).rotation(720).scaleY(0.5f).setDuration(2000);
                Intent intent = new Intent(MainActivity.this, VideoActivity.class);
                startActivity(intent);
            }
        });
    }
}