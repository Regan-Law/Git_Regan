package com.itcast.pickpeach;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class PeachActivity extends AppCompatActivity implements View.OnClickListener {
    private Button btn_one, btn_two, btn_three, btn_four, btn_five, btn_six, btn_exit;
    private int count = 0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_peach);
        init();
    }
    private void init() {
        btn_one = findViewById(R.id.btn_one);
        btn_two = findViewById(R.id.btn_two);
        btn_three = findViewById(R.id.btn_three);
        btn_four = findViewById(R.id.btn_four);
        btn_five = findViewById(R.id.btn_five);
        btn_six = findViewById(R.id.btn_six);
        btn_exit = findViewById(R.id.btn_exit);
        btn_one.setOnClickListener(this);
        btn_two.setOnClickListener(this);
        btn_three.setOnClickListener(this);
        btn_four.setOnClickListener(this);
        btn_five.setOnClickListener(this);
        btn_six.setOnClickListener(this);
        btn_exit.setOnClickListener(this);
    }
    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_one:
                info(btn_one);
                break;
            case R.id.btn_two:
                info(btn_two);
                break;
            case R.id.btn_three:
                info(btn_three);
                break;
            case R.id.btn_four:
                info(btn_four);
                break;
            case R.id.btn_five:
                info(btn_five);
                break;
            case R.id.btn_six:
                info(btn_six);
                break;
            case R.id.btn_exit:
                returnData();
                break;
        }
    }
    private void info(Button btn) {
        btn.setVisibility(View.INVISIBLE);
        count++;
        Toast.makeText(PeachActivity.this, "摘到" + count + "个桃子", Toast.LENGTH_SHORT).show();
    }
    private void returnData() {
        Intent intent = new Intent();
        intent.putExtra("count", count);
        setResult(1, intent);
        PeachActivity.this.finish();
    }
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == KeyEvent.KEYCODE_BACK&&event.getRepeatCount()==0) {
            returnData();
        }
        return false;
    }
}