package com.example.listview_adapter;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.Collections;

public class MainActivity extends AppCompatActivity {

    Button btnAdd;
    EditText etAdd;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ListView listView = findViewById(R.id.myListView);
        //String [] friendList = {"Farwa","Hannia","Bakhtawar"};
        ArrayList<String> friendArrayList = new ArrayList<String>();
        friendArrayList.add("Sarah");
        friendArrayList.add("Namjoon");
        friendArrayList.add("Jungkook");
        friendArrayList.add("Taehyung");
        friendArrayList.add("Yoongi");

        btnAdd = findViewById(R.id.btnAdd);
        etAdd = findViewById(R.id.etAdd);

        ArrayAdapter<String> arrayAdapter = new ArrayAdapter<String>(this,android.R.layout.simple_list_item_1,friendArrayList);
        listView.setAdapter(arrayAdapter);

        btnAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                friendArrayList.add(etAdd.getText().toString());
                listView.setAdapter(arrayAdapter); //or arrayAdaptor.notifyDataSetChanged();
                Collections.sort(friendArrayList); //to sort array data
            }
        });

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Log.d("You clicked",friendArrayList.get(position));
                Intent intent = new Intent(MainActivity.this, MainActivity2.class);
                intent.putExtra("Friend Name", friendArrayList.get(position));
                startActivity(intent);
            }
        });
    }
}