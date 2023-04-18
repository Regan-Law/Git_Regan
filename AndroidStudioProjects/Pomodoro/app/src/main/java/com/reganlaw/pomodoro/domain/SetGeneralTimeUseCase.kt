package com.reganlaw.pomodoro.domain

class SetGeneralTimeUseCase(private val timerRepository: TimerRepository) {
    fun getGeneralTime(pomodoroTimer:PomodoroTimer): Int{
        return timerRepository.setGeneralTime(pomodoroTimer)
    }
}
