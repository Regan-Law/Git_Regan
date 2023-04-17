package com.reganlaw.pomodorotimer.di

import com.reganlaw.pomodorotimer.data.TimerRepositoryImpl
import com.reganlaw.pomodorotimer.domain.TimerRepository
import com.reganlaw.pomodorotimer.view.MainViewModel
import org.koin.androidx.viewmodel.dsl.viewModel
import org.koin.dsl.module

val appModule = module {
	single<TimerRepository> { TimerRepositoryImpl }
	
	viewModel { MainViewModel(get()) }
}