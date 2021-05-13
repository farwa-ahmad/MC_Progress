package com.example.databasesapp;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    TextView etName, etAge, etId;
    Button btnAddRec, btnViewAll, btnUpdate, btnDelete;
    Switch sActivityStatus;
    //ListView lvDetail;

    DatabaseHelper myDb;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        etName = findViewById(R.id.etName);
        etAge = findViewById(R.id.etAge);
        etId.findViewById(R.id.etId);
        btnAddRec = findViewById(R.id.btnAddRec);
        btnViewAll = findViewById(R.id.btnViewAll);
        sActivityStatus = findViewById(R.id.sActivityStatus);
        btnUpdate = findViewById(R.id.btnUpdate);
        btnDelete = findViewById(R.id.btnDelete);
        //lvDetail = findViewById(R.id.lvDetail);

        myDb = new DatabaseHelper(this);

        btnUpdate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                boolean isUpdated = myDb.updateData(etId.getText().toString(),
                        etName.getText().toString(),etName.getText().toString(),
                        sActivityStatus.isChecked());

                if(isUpdated==true)
                    Toast.makeText(MainActivity.this,"Data updated",Toast.LENGTH_LONG).show();
                else
                    Toast.makeText(MainActivity.this,"No data updated",Toast.LENGTH_LONG).show();

            }
        });

        btnDelete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Integer isDeleted = myDb.deleteData(etId.getText().toString());

                if(isDeleted>0)
                    Toast.makeText(MainActivity.this,"Data deleted",Toast.LENGTH_LONG).show();
                else
                    Toast.makeText(MainActivity.this,"No data deleted",Toast.LENGTH_LONG).show();
            }
        });

        btnAddRec.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v)
            {
                boolean isInserted = myDb.insertData(etName.getText().toString(),
                        Integer.parseInt(etAge.getText().toString()),
                        sActivityStatus.isChecked());
                if(isInserted == true)
                    Toast.makeText(MainActivity.this, "Data Inserted",Toast.LENGTH_SHORT).show();
                else
                    Toast.makeText(MainActivity.this, "Error", Toast.LENGTH_SHORT).show();

                /*try
                {
                    CustomerModel customerModel = new CustomerModel(etName.getText().toString(),
                        Integer.parseInt(etAge.getText().toString()),
                        sActivityStatus.isChecked(),1);
                    Toast.makeText(MainActivity.this, "Data Inserted",Toast.LENGTH_SHORT).show();
                }
                catch (Exception e)
                {
                    Toast.makeText(MainActivity.this, "Error", Toast.LENGTH_SHORT).show();
                }
                */
            }
        });

        btnViewAll.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(MainActivity.this, "View Record Clicked",Toast.LENGTH_SHORT).show();

                Cursor result = myDb.getAllData();

                if(result.getCount() == 0)
                {
                    showMessage("Error","Nothing Found");
                    return;
                }

                StringBuffer buffer = new StringBuffer();

                while(result.moveToNext())
                {
                    buffer.append("ID: "+result.getString(0)+"\n");
                    buffer.append("Name: "+result.getString(1)+"\n");
                    buffer.append("Age: "+result.getString(2)+"\n");
                    buffer.append("Activity Status: "+result.getString(3)+"\n\n");
                }
                result.close();
                myDb.close();

                showMessage("Data",buffer.toString());
            }

            public void showMessage(String title, String message)
            {
                AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);

                builder.setCancelable(true);
                builder.setTitle(title);
                builder.setMessage(message);
                builder.show();
            }
        });
    }
}

