package com.example.databasesapp;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class DatabaseHelper extends SQLiteOpenHelper {

    public static final String DATABASE_NAME = "Customer.db";
    public static final String TABLE_NAME = "Customer_table";
    public static final String CUSTOMER_ID = "Customer_ID"; //Column names
    public static final String CUSTOMER_NAME = "Customer_Name";
    public static final String CUSTOMER_AGE = "Customer_Age";
    public static final String CUSTOMER_ACTIVITY = "Customer_Activity_Status";


    public DatabaseHelper(@Nullable Context context) {
        super(context, DATABASE_NAME, null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        String createTableStatement = "CREATE TABLE " + TABLE_NAME
                + "(" + CUSTOMER_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, "
                + CUSTOMER_NAME +" TEXT," + CUSTOMER_AGE + " INTEGER," + CUSTOMER_ACTIVITY+ " BOOL)";

        db.execSQL(createTableStatement);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS "+ TABLE_NAME);
        onCreate(db);
    }

    public boolean insertData(String name, int age, boolean activityStatus)
    {
        SQLiteDatabase db = this.getWritableDatabase();

        ContentValues cv = new ContentValues();

        cv.put(CUSTOMER_NAME, name);
        cv.put(CUSTOMER_AGE, age);
        cv.put(CUSTOMER_ACTIVITY, activityStatus);

        long result = db.insert(TABLE_NAME,null,cv);

        if(result == -1)
            return false;
        else
            return true;
    }

    public Cursor getAllData()
    {
        SQLiteDatabase db = this.getReadableDatabase();

        Cursor result = db.rawQuery("SELECT * FROM "+TABLE_NAME,null);

        return result;
    }

    public boolean updateData(String id, String name, String age, boolean activityStatus)
    {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();

        contentValues.put(CUSTOMER_ID,id);
        contentValues.put(CUSTOMER_NAME,name);
        contentValues.put(CUSTOMER_AGE,age);
        contentValues.put(CUSTOMER_ACTIVITY,activityStatus);

        db.update(TABLE_NAME, contentValues, "ID=?", new String[]{id});
        return true;
    }

    public Integer deleteData(String id)
    {
        SQLiteDatabase db = this.getWritableDatabase();
        return db.delete(TABLE_NAME,"ID=?",new String[]{id});
    }
}
