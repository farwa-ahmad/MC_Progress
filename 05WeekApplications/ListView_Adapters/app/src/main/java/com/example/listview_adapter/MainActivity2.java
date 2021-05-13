package com.example.listview_adapter;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity2 extends AppCompatActivity {
    TextView tvDetail;
    Intent intent;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        intent = getIntent();
        tvDetail = findViewById(R.id.tvDetail);
        tvDetail.setText(intent.getStringExtra("Friend Name"));
    }
}