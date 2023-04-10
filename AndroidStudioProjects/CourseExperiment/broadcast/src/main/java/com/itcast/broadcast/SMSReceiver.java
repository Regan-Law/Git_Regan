package com.itcast.broadcast;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.telephony.SmsMessage;
import android.widget.Toast;

public class SMSReceiver extends BroadcastReceiver{
    @Override
    public void onReceive(Context context,Intent intent){
        Bundle bundle=intent.getExtras();
        String format=bundle.getString("format");
        Object[] objPdus=(Object[])bundle.get("pdus");
        SmsMessage[] messages=new SmsMessage[objPdus.length];
        StringBuffer sbSms=new StringBuffer();
        for(int i=0;i<objPdus.length;i++){
            messages[i]=SmsMessage.createFromPdu((byte[])objPdus[i],format);
            sbSms.append(messages[i].getDisplayMessageBody());
        }
        Toast.makeText(context,sbSms,Toast.LENGTH_SHORT).show();
    }
}