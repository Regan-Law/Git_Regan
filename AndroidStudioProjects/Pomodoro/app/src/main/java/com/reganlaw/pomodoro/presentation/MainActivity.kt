package com.reganlaw.pomodoro.presentation


import android.content.Context
import android.content.Intent
import android.content.SharedPreferences
import android.media.MediaPlayer
import android.os.*
import android.view.View.INVISIBLE
import android.view.View.VISIBLE
import android.view.WindowManager
import android.view.animation.AlphaAnimation
import android.view.animation.Animation
import android.view.animation.AnimationUtils
import androidx.appcompat.app.AppCompatActivity
import com.reganlaw.pomodoro.R
import com.reganlaw.pomodoro.databinding.ActivityMainBinding
import org.koin.androidx.viewmodel.ext.android.viewModel


class MainActivity : AppCompatActivity() {

    private val vm by viewModel<MainViewModel>()
    private lateinit var binding: ActivityMainBinding
    private var timerIsWorking = false
    private lateinit var timer: CountDownTimer
    private lateinit var prefs: SharedPreferences

    private var soundIsOn = true
    private var vibrateIsOn = false
    private var autostartBreaksIsOn = false
    private var autostartPomodoroIsOn = false
    private var keepPhoneAwakeIsOn = true


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        val view = binding.root
        setContentView(view)

        prefs = getSharedPreferences("Settings", Context.MODE_PRIVATE)


        binding.changeDurationButton.setOnClickListener {
            vm.changeTimerMode(vm.pomodoroTimer)

            refreshValuesOnTextViews()

            timer = initTimer()
        }

        binding.playPauseButton.setOnClickListener {
            if (timerIsWorking) {
                timer.cancel()
                timer = initTimer()
                stopTimer()
            } else
                playTimer()
        }

        binding.resetButton.setOnClickListener {
            timer.cancel()
            vm.resetTime(vm.pomodoroTimer)
            binding.timeTextView.text = formatTime(vm.pomodoroTimer.time)
            timerIsWorking = false
            changeButtonsWhenTimerNotWorking()
            setInvisibleResetButton()
            timer = initTimer()

        }

        binding.settingsButton.setOnClickListener {
            val intent = Intent(this, SettingsActivity::class.java)
            intent.putExtra("pomodoroTime", vm.pomodoroTimer.pomodoroTime / SECONDS_IN_MINUTES)
            intent.putExtra("breakTime", vm.pomodoroTimer.breakTime / SECONDS_IN_MINUTES)
            intent.putExtra("longBreakTime", vm.pomodoroTimer.longBreakTime / SECONDS_IN_MINUTES)
            startActivity(intent)
        }

    }

    override fun onResume() {
        val pomodoroTime = prefs.getInt("pomodoroTime", 25 * 60)
        val breakTime = prefs.getInt("breakTime", 5 * 60)
        val longBreakTime = prefs.getInt("longBreakTime", 15 * 60)

        soundIsOn = prefs.getBoolean("soundIsOn", soundIsOn)
        vibrateIsOn = prefs.getBoolean("vibrateIsOn", vibrateIsOn)
        autostartBreaksIsOn = prefs.getBoolean("autostartBreaksIsOn", autostartBreaksIsOn)
        autostartPomodoroIsOn = prefs.getBoolean("autostartPomodoroIsOn", autostartPomodoroIsOn)
        keepPhoneAwakeIsOn = prefs.getBoolean("keepPhoneAwakeIsOn", keepPhoneAwakeIsOn)

        if (keepPhoneAwakeIsOn)
            window.addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON)
        else
            window.clearFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON)

        vm.pomodoroTimer.pomodoroTime = pomodoroTime
        vm.pomodoroTimer.breakTime = breakTime
        vm.pomodoroTimer.longBreakTime = longBreakTime
        vm.setGeneralTime(vm.pomodoroTimer)


        refreshValuesOnTextViews()
        super.onResume()
    }

    private fun initTimer(): CountDownTimer {
        return object : CountDownTimer(
            vm.pomodoroTimer.time * MILLISECONDS_IN_SECONDS.toLong(),
            MILLISECONDS_IN_SECONDS.toLong()
        ) {
            override fun onTick(millisUntilFinished: Long) {
                vm.pomodoroTimer.time = (millisUntilFinished / MILLISECONDS_IN_SECONDS).toInt()
                binding.timeTextView.text = formatTime(vm.pomodoroTimer.time)

            }


            override fun onFinish() {
                if (soundIsOn)
                    playSong()


                if (vibrateIsOn)
                    vibrate()


                timerIsWorking = false
                changeButtonsWhenTimerNotWorking()
                setInvisibleResetButton()
                timer = initTimer()
                vm.changeTimerModeWhenTimerFinished(vm.pomodoroTimer)
                refreshPomodoroProgress()
                refreshValuesOnTextViews()

                if (autostartBreaksIsOn &&
                    (vm.pomodoroTimer.timerMode == 1 || vm.pomodoroTimer.timerMode == 2)
                )
                    playTimer()

                if (autostartPomodoroIsOn && vm.pomodoroTimer.timerMode == 0)
                    playTimer()

            }
        }
    }

    private fun playTimer() {
        timer = initTimer()
        timerIsWorking = true
        changeButtonsWhenTimerWorking()
        timer.start()
    }

    private fun stopTimer() {
        timerIsWorking = false
        changeButtonsWhenTimerNotWorking()
        timer.cancel()
        binding.timeTextView.text = formatTime(vm.pomodoroTimer.time)
    }

    private fun refreshValuesOnTextViews() {
        binding.timeTextView.text = formatTime(vm.pomodoroTimer.time)
        val anim = AlphaAnimation(1.0f, 0.0f)
        anim.duration = 100
        anim.repeatCount = 1
        anim.repeatMode = Animation.REVERSE

        anim.setAnimationListener(object : Animation.AnimationListener {
            override fun onAnimationEnd(animation: Animation?) {}
            override fun onAnimationStart(animation: Animation?) {}
            override fun onAnimationRepeat(animation: Animation?) {
                binding.changeDurationButton.text = vm.getTimerMode(vm.pomodoroTimer)
            }
        })
        binding.changeDurationButton.startAnimation(anim)


    }

    private fun refreshPomodoroProgress() {

        val pomodoroProgress = listOf(
            binding.pomodoroProgress1,
            binding.pomodoroProgress2,
            binding.pomodoroProgress3,
            binding.pomodoroProgress4
        )
        for (i in 0..3) {
            pomodoroProgress[i].setImageResource(
                if (i < vm.pomodoroTimer.pomodoroCounter) {
                    R.drawable.ellipse_enabled
                } else {
                    R.drawable.ellipse_disabled
                }
            )
        }
    }

    private fun playSong() {
        val mediaPlayer = MediaPlayer.create(applicationContext, R.raw.daydream)
        mediaPlayer.start()
    }


    private fun vibrate() {

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S) {
            val vibratorManager =
                getSystemService(VIBRATOR_MANAGER_SERVICE) as VibratorManager
            val vibrator = vibratorManager.defaultVibrator

            object : CountDownTimer(500, 500) {

                override fun onTick(millisUntilFinished: Long) {
                    vibrator.vibrate(
                        VibrationEffect.createOneShot(
                            10000,
                            VibrationEffect.DEFAULT_AMPLITUDE
                        )
                    )
                }

                override fun onFinish() {
                    vibrator.cancel()
                }
            }.start()

        } else {
            val vibrator = getSystemService(VIBRATOR_SERVICE) as Vibrator
            vibrator.vibrate(500)
        }

    }

    private fun changeButtonsWhenTimerWorking() {
        binding.playPauseButton.setImageResource(R.drawable.baseline_pause_24)
        if(binding.resetButton.visibility != VISIBLE){
            binding.resetButton.startAnimation(
                AnimationUtils.loadAnimation(
                    applicationContext,
                    R.anim.button_animation_to_visible
                )
            )
            binding.resetButton.visibility = VISIBLE
        }

        binding.changeDurationButton.isClickable = false
    }

    private fun changeButtonsWhenTimerNotWorking() {
        binding.playPauseButton.setImageResource(R.drawable.baseline_play_arrow_24)
        binding.changeDurationButton.isClickable = true
    }
    private fun setInvisibleResetButton(){
        binding.resetButton.startAnimation(
            AnimationUtils.loadAnimation(
                applicationContext,
                R.anim.button_animation_to_invisible
            )
        )
        binding.resetButton.visibility = INVISIBLE
    }

    private fun formatTime(seconds: Int): String {
        val minutes = seconds / SECONDS_IN_MINUTES
        val remainingSeconds = seconds % SECONDS_IN_MINUTES
        return String.format("%02d:%02d", minutes, remainingSeconds)
    }

    companion object {
        private const val SECONDS_IN_MINUTES = 60
        private const val MILLISECONDS_IN_SECONDS = 1000
    }
}
