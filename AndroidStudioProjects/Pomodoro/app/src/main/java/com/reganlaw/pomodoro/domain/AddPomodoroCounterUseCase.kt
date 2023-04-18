package com.reganlaw.pomodoro.domain

class AddPomodoroCounterUseCase (private val timerRepository: TimerRepository) {
    fun addCounter(pomodoroTimer:PomodoroTimer){
        timerRepository.addPomodoro(pomodoroTimer)
    }
}