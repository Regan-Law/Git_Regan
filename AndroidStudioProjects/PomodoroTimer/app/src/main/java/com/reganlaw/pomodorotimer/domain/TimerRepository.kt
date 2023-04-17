package com.reganlaw.pomodorotimer.domain

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
	class AddPomodoroCounterUseCase (private val timerRepository: TimerRepository) {
		fun addCounter(pomodoroTimer: PomodoroTimer) {
			timerRepository.addPomodoro(pomodoroTimer)
		}
	}
	class ChangeTimerModeUseCase(private val timerRepository: TimerRepository) {
		fun changeTimerMode(pomodoroTimer:PomodoroTimer){
			timerRepository.changeTimerMode(pomodoroTimer)
		}
	}
	class ChangeTimerModeWhenTimerFinishedUseCase(private val timerRepository: TimerRepository) {
		fun changeTimerModeWhenTimerFinished(pomodoroTimer: PomodoroTimer){
			timerRepository.changeTimerModeWhenTimerFinished(pomodoroTimer)
		}
	}
	class GetCurrentTimeUseCase(private val timerRepository: TimerRepository) {
		fun getCurrentTime():Int{
			return timerRepository.getCurrentTime()
		}
	}
	class GetTimerModeUseCase (private val timerRepository: TimerRepository) {
		fun getTimerMode(pomodoroTimer: PomodoroTimer): String{
			return timerRepository.getTimerMode(pomodoroTimer)
		}
	}
	class GetTimerUseCase(private val timerRepository: TimerRepository) {
		fun getTimer(): PomodoroTimer{
			return timerRepository.getTimer()
		}
	}
	data class PomodoroTimer(
		
		var pomodoroTime: Int,
		var breakTime: Int,
		var longBreakTime: Int,
		
		var time: Int = 0,
		var timerMode: Int = 0,
		var pomodoroCounter: Int = 0
	
	)
	class ResetTimeUseCase(private val timerRepository: TimerRepository) {
		fun resetTime(pomodoroTimer:PomodoroTimer){
			timerRepository.resetTime(pomodoroTimer)
		}
	}
	class SetGeneralTimeUseCase(private val timerRepository: TimerRepository) {
		fun getGeneralTime(pomodoroTimer: PomodoroTimer): Int{
			return timerRepository.setGeneralTime(pomodoroTimer)
		}
	}
	class SetTimeUseCase(private val timerRepository: TimerRepository) {
		fun setTime(pomodoroTimer: PomodoroTimer, time: Int) {
			timerRepository.setTime(pomodoroTimer, time)
		}
	}