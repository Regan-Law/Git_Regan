package cn.itcast.saveqq;

import android.content.Context;
import android.content.SharedPreferences;

import java.util.HashMap;
import java.util.Map;

public class SPSaveQQ{
    public static boolean saveUserInfo(Context context,String account,String password){
        SharedPreferences sp=context.getSharedPreferences("userinfo",Context.MODE_PRIVATE);
        SharedPreferences.Editor editor=sp.edit();
        editor.putString("userName",account);
        editor.putString("password",password);
        editor.apply();
        return true;
    }

    public static Map<String,String> getUserInfo(Context context){
        SharedPreferences sp=context.getSharedPreferences("data",Context.MODE_PRIVATE);
        String account=sp.getString("userName",null);
        String password=sp.getString("pwd",null);
        Map<String,String> usermap=new HashMap<>();
        usermap.put("account",account);
        usermap.put("password",password);
        return usermap;
    }
}