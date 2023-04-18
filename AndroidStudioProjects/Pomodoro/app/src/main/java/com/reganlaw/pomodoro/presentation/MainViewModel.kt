package com.reganlaw.pomodoro.presentation

import androidx.lifecycle.ViewModel

import com.reganlaw.pomodoro.domain.*


class MainViewModel(private val repository: TimerRepository) : ViewModel() {


    private val getTimerUseCase = GetTimerUseCase(repository)
    private val setGeneralTimeUseCase = SetGeneralTimeUseCase(repository)
    private val getTimerModeUseCase = GetTimerModeUseCase(repository)
    private val changeTimerModeUseCase = ChangeTimerModeUseCase(repository)
    private val changeTimerModeWhenTimerFinishedUseCase =
        ChangeTimerModeWhenTimerFinishedUseCase(repository)

    private val resetTimeUseCase = ResetTimeUseCase(repository)

    var pomodoroTimer = PomodoroTimer(0, 0, 0)

    fun getTimer(): PomodoroTimer {
        return getTimerUseCase.getTimer()
    }

    fun setGeneralTime(pomodoroTimer: PomodoroTimer) {
        pomodoroTimer.time = setGeneralTimeUseCase.getGeneralTime(pomodoroTimer)
    }

    fun getTimerMode(pomodoroTimer: PomodoroTimer): String {
        return getTimerModeUseCase.getTimerMode(pomodoroTimer)
    }

    fun resetTime(pomodoroTimer: PomodoroTimer) {
        resetTimeUseCase.resetTime(pomodoroTimer)
    }


    fun changeTimerMode(pomodoroTimer: PomodoroTimer) {
        changeTimerModeUseCase.changeTimerMode(pomodoroTimer)
    }

    fun changeTimerModeWhenTimerFinished(pomodoroTimer: PomodoroTimer) {
        changeTimerModeWhenTimerFinishedUseCase.changeTimerModeWhenTimerFinished(pomodoroTimer)
    }
}