package com.example.admin.myapplication;

import android.content.Intent;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;



public class LCD extends ActionBarActivity {

    public static String soA="numberA";
    public static String soB="numberB";

    public void calculate(View view) {




        EditText texta = (EditText) findViewById(R.id.numA);
        EditText textb = (EditText) findViewById(R.id.numB);

        String sb = textb.getText().toString();
        String sa = texta.getText().toString();



        try {

            int a = Integer.parseInt(sa);
            int b = Integer.parseInt(sb);

            Intent intent = new Intent(this, CalculateLCD.class);
            intent.putExtra(soA,a);
            intent.putExtra(soB,b);
            startActivity(intent);


        }
        catch(Exception e)
        {

        }


    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.activity_lcd_intro);
        setContentView(R.layout.activity_lcd);
    }
}
