package com.reganlaw.pomodoro.domain

interface TimerRepository {

    fun getTimer(): PomodoroTimer
    fun setGeneralTime(pomodoroTimer: PomodoroTimer): Int
    fun getCurrentTime():Int
    fun setTime(pomodoroTimer: PomodoroTimer, time: Int)
    fun resetTime(pomodoroTimer:PomodoroTimer)
    fun changeTimerMode(pomodoroTimer:PomodoroTimer)
    fun changeTimerModeWhenTimerFinished(pomodoroTimer: PomodoroTimer)
    fun getTimerMode(pomodoroTimer: PomodoroTimer): String
    fun addPomodoro(pomodoroTimer:PomodoroTimer)

}