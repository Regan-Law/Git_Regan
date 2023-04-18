package com.reganlaw.pomodoro.domain

class ChangeTimerModeWhenTimerFinishedUseCase(private val timerRepository: TimerRepository) {
    fun changeTimerModeWhenTimerFinished(pomodoroTimer: PomodoroTimer){
        timerRepository.changeTimerModeWhenTimerFinished(pomodoroTimer)
    }
}