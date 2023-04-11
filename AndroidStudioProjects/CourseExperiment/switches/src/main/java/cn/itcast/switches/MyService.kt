package cn.itcast.switches

import android.app.Service
import android.content.Intent
import android.os.IBinder
import android.util.Log

class MyService : Service() {
	override fun onCreate() {
		super.onCreate()
		// 1. 创建一个Notification对象
		Log.i("MyService", "创建服务，执行onCreate()方法")
	}
	
	override fun onStartCommand(intent: Intent?, flags: Int, startId: Int): Int {
		Log.i("MyService", "开启服务，执行onStartCommand()方法")
		return super.onStartCommand(intent, flags, startId)
	}
	
	override fun onBind(intent: Intent): IBinder? {
		return null
	}
	
	override fun onDestroy() {
		super.onDestroy()
		Log.i("MyService", "关闭服务，执行onDestroy()方法")
	}
}