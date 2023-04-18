package com.reganlaw.pomodoro.domain

class GetTimerUseCase(private val timerRepository: TimerRepository) {
    fun getTimer(): PomodoroTimer{
        return timerRepository.getTimer()
    }
}