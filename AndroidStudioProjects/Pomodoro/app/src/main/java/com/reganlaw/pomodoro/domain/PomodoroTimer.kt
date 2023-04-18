package com.reganlaw.pomodoro.domain

data class PomodoroTimer(

    var pomodoroTime: Int,
    var breakTime: Int,
    var longBreakTime: Int,

    var time: Int = 0,
    var timerMode: Int = 0,
    var pomodoroCounter: Int = 0

)
