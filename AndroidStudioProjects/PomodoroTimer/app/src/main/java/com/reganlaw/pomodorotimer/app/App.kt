package com.reganlaw.pomodorotimer.app

import android.app.Application
import com.reganlaw.pomodorotimer.di.appModule
import org.koin.android.ext.koin.androidContext
import org.koin.core.context.startKoin

class App: Application() {
	
	override fun onCreate() {
		super.onCreate()
		
		// start Koin
		startKoin{
			androidContext(this@App)
			modules(appModule)
		}
	}
}