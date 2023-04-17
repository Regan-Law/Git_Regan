package com.reganlaw.pomodorotimer.activities

import android.annotation.SuppressLint
import android.content.Intent
import android.content.SharedPreferences
import android.net.Uri
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.reganlaw.pomodorotimer.databinding.SettingsActivityBinding

class SettingsActivity : AppCompatActivity() {
	private var pomodoroTime = 0
	private var breakTime = 0
	private var longBreakTime = 0
	
	private var soundIsOn = true
	private var vibrateIsOn = false
	private var autostartBreaksIsOn = false
	private var autostartPomodoroIsOn = false
	private var keepPhoneAwakeIsOn = true
	
	private lateinit var binding: SettingsActivityBinding
	private lateinit var prefs: SharedPreferences
	override fun onCreate(savedInstanceState: Bundle?) {
		super.onCreate(savedInstanceState)
		binding = SettingsActivityBinding.inflate(layoutInflater)
		val view = binding.root
		setContentView(view)
		prefs = getSharedPreferences("Settings", MODE_PRIVATE)
		pomodoroTime = intent.getIntExtra("pomodoroTime", 0)
		breakTime = intent.getIntExtra("breakTime", 0)
		longBreakTime = intent.getIntExtra("longBreakTime", 0)
		
		soundIsOn = prefs.getBoolean("soundIsOn", true)
		vibrateIsOn = prefs.getBoolean("vibrateIsOn", false)
		autostartBreaksIsOn = prefs.getBoolean("autostartBreaksIsOn", false)
		autostartPomodoroIsOn = prefs.getBoolean("autostartPomodoroIsOn", false)
		keepPhoneAwakeIsOn = prefs.getBoolean("keepPhoneAwakeIsOn", true)
		
		refreshValuesOnTextView()
		
		setAddAndReduceButtonsClickListeners()
		
		setSwitchClickListenersCheckedOn()
		
		binding.linkToGitHub.setOnClickListener {
			val uri = Uri.parse("https://github.com/Xek0mb1k/Pomodoro")
			val intent = Intent(Intent.ACTION_VIEW, uri)
			startActivity(intent)
		}
		
	}
	
	
	private fun setAddAndReduceButtonsClickListeners() {
		val reduceButtons = listOf(
			binding.reducePomodoroTimeButton,
			binding.reduceBreakTimeButton,
			binding.reduceLongBreakTimeButton
		)
		val addButtons = listOf(
			binding.addPomodoroTimeButton,
			binding.addBreakTimeButton,
			binding.addLongBreakTimeButton
		)
		
		for (i in 0..2) {
			reduceButtons[i].setOnClickListener {
				when (i) {
					0 ->
						if (pomodoroTime > 1)
							pomodoroTime--
					
					1 -> if (breakTime > 1)
						breakTime--
					
					2 -> if (longBreakTime > 1)
						longBreakTime--
					
				}
				refreshValuesOnTextView()
			}
			addButtons[i].setOnClickListener {
				when (i) {
					0 -> pomodoroTime++
					1 -> breakTime++
					2 -> longBreakTime++
				}
				refreshValuesOnTextView()
			}
		}
	}
	
	@SuppressLint("CommitPrefEdits")
	override fun onPause() {
		with(prefs.edit()) {
			putInt("pomodoroTime", pomodoroTime * 60)
			putInt("breakTime", breakTime * 60)
			putInt("longBreakTime", longBreakTime * 60)
			
			putBoolean("soundIsOn", binding.soundSwitch.isChecked)
			putBoolean("vibrateIsOn", binding.vibrateSwitch.isChecked)
			putBoolean("autostartBreaksIsOn", binding.autoStartBreaksSwitch.isChecked)
			putBoolean("autostartPomodoroIsOn", binding.autoStartPomodoroSwitch.isChecked)
			putBoolean("keepPhoneAwakeIsOn", binding.keepPhoneAwakeSwitch.isChecked)
			commit()
		}
		
		super.onPause()
	}
	
	private fun setSwitchClickListenersCheckedOn() {
		val switchValues = listOf(
			soundIsOn,
			vibrateIsOn,
			autostartBreaksIsOn,
			autostartPomodoroIsOn,
			keepPhoneAwakeIsOn
		)
		val switchers = listOf(
			binding.soundSwitch,
			binding.vibrateSwitch,
			binding.autoStartBreaksSwitch,
			binding.autoStartPomodoroSwitch,
			binding.keepPhoneAwakeSwitch
		)
		for (i in switchers.indices)
			switchers[i].isChecked = switchValues[i]
	}
	
	private fun refreshValuesOnTextView() {
		
		binding.pomodoroDurationTextView.text = pomodoroTime.toString()
		binding.breakDurationTextView.text = breakTime.toString()
		binding.longBreakDurationTextView.text = longBreakTime.toString()
		
	}
}