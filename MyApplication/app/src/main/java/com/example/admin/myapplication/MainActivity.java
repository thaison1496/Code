package com.example.admin.myapplication;

import android.content.Intent;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;


public class MainActivity extends ActionBarActivity {

    public final static String EXTRA_MESSAGE = "com.mycompany.myfirstapp.MESSAGE";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main_activity_actions, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        switch (id){
            case R.id.action_search:
                openSearch();
                return true;
            case R.id.action_settings:
                openSetings();
                return true;
            case R.id.action_calculateLCD:
                openLCD();
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }


    }

    public void openLCD(){
        Intent intent = new Intent(this, LCD.class);
        startActivity(intent);
    }
    /** Called when the user clicks the Send button */
    public void sendMessage(View view) {
        Intent intent = new Intent(this, DisplayMessageActivity.class);
        EditText editText = (EditText) findViewById(R.id.edit_message);
        String message = editText.getText().toString();
        intent.putExtra(EXTRA_MESSAGE, message);
        startActivity(intent);
    }
    public void openSearch() {
        TextView textView = new TextView(this);
        textView.setTextSize(40);
        textView.setText("This's search bitch");

        //getLayoutInflater().inflate(R.layout.activity_display_message,);

        // Set the text view as the activity layout
        setContentView(textView);
    }
    public void openSetings() {
        TextView textView = new TextView(this);
        textView.setTextSize(40);
        textView.setText("Lol no settings poop");

        // Set the text view as the activity layout
        setContentView(textView);
    }
}
