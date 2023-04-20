package com.reganlaw.pomodoro.data

import android.content.Context
import android.content.SharedPreferences
import com.reganlaw.pomodoro.domain.PomodoroTimer
import com.reganlaw.pomodoro.domain.TimerRepository



object TimerRepositoryImpl : TimerRepository {

    private val timer = PomodoroTimer(0, 0, 0)

    init {
        resetTime(timer)
    }

    override fun getTimer(): PomodoroTimer {
        return timer
    }


    override fun setGeneralTime(pomodoroTimer: PomodoroTimer): Int {
        return when (pomodoroTimer.timerMode) {
            POMODORO_TIME_ID -> pomodoroTimer.pomodoroTime
            BREAK_TIME_ID -> pomodoroTimer.breakTime
            LONG_BREAK_TIME_ID -> pomodoroTimer.longBreakTime
            else -> throw java.lang.RuntimeException("Element $this not found")
        }
    }

    override fun getCurrentTime(): Int {
        return timer.time
    }


    override fun resetTime(pomodoroTimer: PomodoroTimer) {
        pomodoroTimer.time = setGeneralTime(pomodoroTimer)
    }

    override fun setTime(pomodoroTimer: PomodoroTimer, time: Int) {
        pomodoroTimer.time = time
    }

    override fun changeTimerMode(pomodoroTimer: PomodoroTimer) {
        pomodoroTimer.timerMode++
        if (pomodoroTimer.timerMode > LONG_BREAK_TIME_ID)
            pomodoroTimer.timerMode = POMODORO_TIME_ID

        refreshTime(pomodoroTimer)
    }

    override fun changeTimerModeWhenTimerFinished(pomodoroTimer: PomodoroTimer){

        with(pomodoroTimer){
            if (timerMode == POMODORO_TIME_ID ||
                timerMode == LONG_BREAK_TIME_ID)
                addPomodoro(this)
            timerMode = if (pomodoroCounter == 4)
                LONG_BREAK_TIME_ID
            else if (timerMode == BREAK_TIME_ID ||
                timerMode == LONG_BREAK_TIME_ID)
                POMODORO_TIME_ID
            else
                BREAK_TIME_ID
            refreshTime(this)
        }




    }

    override fun getTimerMode(pomodoroTimer: PomodoroTimer): String {
        return when (pomodoroTimer.timerMode) {
            POMODORO_TIME_ID -> "一个番茄（工作/学习） ${pomodoroTimer.pomodoroTime / 60} 分钟"
            BREAK_TIME_ID -> "小憩 ${pomodoroTimer.breakTime / 60} 分钟"
            LONG_BREAK_TIME_ID -> "休息 ${pomodoroTimer.longBreakTime / 60} 分钟"
            else -> throw java.lang.RuntimeException("Element $this not found")
        }
    }

    override fun addPomodoro(pomodoroTimer: PomodoroTimer) {
        pomodoroTimer.pomodoroCounter++
        if (pomodoroTimer.pomodoroCounter > 4) {
            pomodoroTimer.pomodoroCounter = 0
        }
    }

    private fun refreshTime(pomodoroTimer: PomodoroTimer){
        pomodoroTimer.time =  when (pomodoroTimer.timerMode) {
            POMODORO_TIME_ID -> pomodoroTimer.pomodoroTime
            BREAK_TIME_ID -> pomodoroTimer.breakTime
            LONG_BREAK_TIME_ID -> pomodoroTimer.longBreakTime
            else -> throw java.lang.RuntimeException("Element $this not found")
        }
    }

    private const val POMODORO_TIME_ID = 0
    private const val BREAK_TIME_ID = 1
    private const val LONG_BREAK_TIME_ID = 2
}
