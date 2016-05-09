package com.example.admin.myapplication;

import android.content.Intent;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;


public class CalculateLCD extends ActionBarActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // Get the message from the intent
        Bundle intent = getIntent().getExtras();

        int a = intent.getInt(LCD.soA);
        int b = intent.getInt(LCD.soB);

        int r;
      /*  try{

            while (b>0)
            {
                r=a/b;
                a=b;
                b=r;
            }
        }
        catch(Exception e){

        }
*/
        while (b>0)
        {
            r=a%b;
            a=b;
            b=r;
        }

        // Create the text view
        TextView textView = new TextView(this);
        textView.setTextSize(40);
        textView.setText(String.valueOf(a));

        // Set the text view as the activity layout
        setContentView(textView);
    }


}
