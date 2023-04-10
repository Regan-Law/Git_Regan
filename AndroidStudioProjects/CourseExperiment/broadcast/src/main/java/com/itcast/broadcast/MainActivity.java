package com.itcast.broadcast;

import android.Manifest;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

public class MainActivity extends AppCompatActivity{

    private static final String SMS_ACTION="android.provider.Telephony.SMS_RECEIVED";
    private final String RCV_SMS_PERM=Manifest.permission.RECEIVE_SMS;
    private final int PERMISSION_DENIED_DONT_ASK=1;
    private boolean register_flag=false;
    private int perm_flag=2;
    private SMSReceiver smsReceiver=null;
    private Button btRegister=null;

    protected void onCreate(Bundle saveInstanceState){
        super.onCreate(saveInstanceState);
        setContentView(R.layout.activity_main);
        SMSReceiver smsReceiver=new SMSReceiver();
        IntentFilter filter=new IntentFilter(SMS_ACTION);
        registerReceiver(smsReceiver,filter);
        unregisterReceiver(smsReceiver);
    }

    public void registerReceiverListener(View v){
        perm_flag=ActivityCompat.checkSelfPermission(this,RCV_SMS_PERM);
        if(!register_flag){
            btRegister=(Button)v;
            if(perm_flag!=PERMISSION_DENIED_DONT_ASK&&perm_flag==PackageManager.PERMISSION_DENIED){
                ActivityCompat.requestPermissions(this,new
                        String[]{RCV_SMS_PERM},0X123);
            }
            if(perm_flag==PERMISSION_DENIED_DONT_ASK){
                Toast.makeText(this,
                        getResources().getString(R.string.smsforbid),
                        Toast.LENGTH_SHORT).show();
            }else if(perm_flag==PackageManager.PERMISSION_GRANTED){
                registerReceiver();
            }
        }else{
            unregisterReceiver();
        }
    }

    private void registerReceiver(){
        smsReceiver=new SMSReceiver();
        IntentFilter filter=new IntentFilter(SMS_ACTION);
        registerReceiver(smsReceiver,filter);
        btRegister.setText(getResources().getString(R.string.unregisterButton));
        register_flag=true;
        Toast.makeText(this,getResources().getString(R.string.registered),Toast.LENGTH_SHORT).show();
    }

    private void unregisterReceiver(){
        register_flag=false;
        unregisterReceiver(smsReceiver);
        btRegister.setText(getResources().getString(R.string.registerButton));
        Toast.makeText(this,getResources().getString(R.string.unregistered),Toast.LENGTH_SHORT).show();
    }

    public void onRequestPermissionsResult(int requestCode,String[] permissions,int[] grantResults){
        super.onRequestPermissionsResult(requestCode,permissions,grantResults);
        if(requestCode==0X123){
            if(grantResults[0]==PackageManager.PERMISSION_GRANTED){
                registerReceiver();
            }else{
                Toast.makeText(this,getResources().getString(R.string.smsforbid),Toast.LENGTH_SHORT).show();
            }
        }
    }
}