package com.reganlaw.pomodoro.di

import com.reganlaw.pomodoro.data.TimerRepositoryImpl
import com.reganlaw.pomodoro.domain.TimerRepository
import com.reganlaw.pomodoro.presentation.MainViewModel
import org.koin.androidx.viewmodel.dsl.viewModel
import org.koin.dsl.module

val appModule = module {
    single<TimerRepository> { TimerRepositoryImpl }

    viewModel { MainViewModel(get()) }
}