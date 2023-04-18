package com.reganlaw.pomodoro.domain

class ResetTimeUseCase(private val timerRepository: TimerRepository) {
    fun resetTime(pomodoroTimer:PomodoroTimer){
        timerRepository.resetTime(pomodoroTimer)
    }
}