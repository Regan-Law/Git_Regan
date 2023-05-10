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

    private val vm by viewModel<MainViewModel>() // 使用 activity-ktx 工件中的 by viewModels（） 委托初始化视图模型属性。这意味着视图模型的范围将限定为活动，并在活动完成时销毁该模型
    private lateinit var binding: ActivityMainBinding//使用 DataBindingUtil 初始化绑定变量
    private var timerIsWorking = false
    private lateinit var timer: CountDownTimer//创建一个 CountDownTimer 对象，并将其存储在名为 timer 的变量中
    private lateinit var prefs: SharedPreferences//创建一个 SharedPreferences 对象，并将其存储在名为 prefs 的变量中
    private lateinit var mediaPlayer: MediaPlayer//创建一个 MediaPlayer 对象，并将其存储在名为 mediaPlayer 的变量中

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

        prefs = getSharedPreferences("Settings", Context.MODE_PRIVATE)//创建名为Settings的共享首选项文件。将模式设置为私有


        binding.changeDurationButton.setOnClickListener {
            vm.changeTimerMode(vm.pomodoroTimer)//更改计时器模式

            refreshValuesOnTextViews()//刷新文本视图上的值

            timer = initTimer()//初始化计时器
        }

        binding.playPauseButton.setOnClickListener {
            if (timerIsWorking) {
                timer.cancel()//取消计时器
                timer = initTimer()//初始化计时器
                stopTimer()//停止计时器
            } else
                playTimer()//播放计时器
        }

        binding.resetButton.setOnClickListener {
            timer.cancel()
            vm.resetTime(vm.pomodoroTimer)//重置时间
            binding.timeTextView.text = formatTime(vm.pomodoroTimer.time)//格式化时间
            timerIsWorking = false//计时器未工作
            changeButtonsWhenTimerNotWorking()//更改按钮
            setInvisibleResetButton()//设置不可见的重置按钮
            timer = initTimer()//初始化计时器
        }

        binding.settingsButton.setOnClickListener {
            val intent = Intent(this, SettingsActivity::class.java)//创建一个 Intent 对象，该对象将从 MainActivity 跳转到 SettingsActivity
            intent.putExtra("一个番茄（工作/学习）", vm.pomodoroTimer.pomodoroTime / SECONDS_IN_MINUTES)//将工作时间作为额外的 Intent 数据传递
            intent.putExtra("小憩", vm.pomodoroTimer.breakTime / SECONDS_IN_MINUTES)//将休息时间作为额外的 Intent 数据传递
            intent.putExtra("休息", vm.pomodoroTimer.longBreakTime / SECONDS_IN_MINUTES)//将长时间休息作为额外的 Intent 数据传递
            startActivity(intent)//启动 SettingsActivity
        }

    }

    override fun onResume() {
        val pomodoroTime = prefs.getInt("一个番茄（工作/学习）", 25 * 60)
        val breakTime = prefs.getInt("小憩", 5 * 60)
        val longBreakTime = prefs.getInt("休息", 15 * 60)

        soundIsOn = prefs.getBoolean("soundIsOn", soundIsOn)//获取 soundIsOn 的值。如果没有值，则使用 soundIsOn 的默认值
        vibrateIsOn = prefs.getBoolean("vibrateIsOn", vibrateIsOn)//获取 vibrateIsOn 的值。如果没有值，则使用 vibrateIsOn 的默认值
        autostartBreaksIsOn = prefs.getBoolean("autostartBreaksIsOn", autostartBreaksIsOn)//获取 autostartBreaksIsOn 的值。如果没有值，则使用 autostartBreaksIsOn 的默认值
        autostartPomodoroIsOn = prefs.getBoolean("autostartPomodoroIsOn", autostartPomodoroIsOn)//获取 autostartPomodoroIsOn 的值。如果没有值，则使用 autostartPomodoroIsOn 的默认值
        keepPhoneAwakeIsOn = prefs.getBoolean("keepPhoneAwakeIsOn", keepPhoneAwakeIsOn)//获取 keepPhoneAwakeIsOn 的值。如果没有值，则使用 keepPhoneAwakeIsOn 的默认值

        if (keepPhoneAwakeIsOn)
            window.addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON)//保持屏幕常亮
        else
            window.clearFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON)//清除屏幕常亮

        vm.pomodoroTimer.pomodoroTime = pomodoroTime//设置工作时间
        vm.pomodoroTimer.breakTime = breakTime//设置休息时间
        vm.pomodoroTimer.longBreakTime = longBreakTime//设置长时间休息
        vm.setGeneralTime(vm.pomodoroTimer)//设置总时间

        refreshValuesOnTextViews()//刷新文本视图上的值
        super.onResume()//调用父类的 onResume 方法
    }

    private fun initTimer(): CountDownTimer {// 
        return object : CountDownTimer(//创建一个 CountDownTimer 对象，并将其存储在名为 timer 的变量中
            vm.pomodoroTimer.time * MILLISECONDS_IN_SECONDS.toLong(),//设置计时器的总时间
            MILLISECONDS_IN_SECONDS.toLong()//设置计时器的间隔
        ) {
            override fun onTick(millisUntilFinished: Long) {//每次计时器间隔时调用
                vm.pomodoroTimer.time = (millisUntilFinished / MILLISECONDS_IN_SECONDS).toInt()//将时间设置为剩余时间
                binding.timeTextView.text = formatTime(vm.pomodoroTimer.time)//格式化时间
            }


            override fun onFinish() {
                if (soundIsOn)//如果声音开启
                    playSong()//播放音乐


                if (vibrateIsOn)//如果震动开启
                    vibrate()//震动


                timerIsWorking = false
                changeButtonsWhenTimerNotWorking()//更改按钮
                setInvisibleResetButton()//设置不可见的重置按钮
                timer = initTimer()//初始化计时器
                vm.changeTimerModeWhenTimerFinished(vm.pomodoroTimer)//更改计时器模式
                refreshPomodoroProgress()//刷新番茄进度
                refreshValuesOnTextViews()//刷新文本视图上的值

                if (autostartBreaksIsOn &&
                    (vm.pomodoroTimer.timerMode == 1 || vm.pomodoroTimer.timerMode == 2)//如果休息自动启动开启
                )
                    playTimer()//播放计时器

                if (autostartPomodoroIsOn && vm.pomodoroTimer.timerMode == 0)//如果工作自动启动开启
                    playTimer()//播放计时器

            }
        }
    }

    private fun playTimer() {
        timer = initTimer()//初始化计时器
        timerIsWorking = true//计时器工作
        changeButtonsWhenTimerWorking() //更改按钮
        timer.start() //启动计时器
    }

    private fun stopTimer() {
        timerIsWorking = false //计时器不工作
        changeButtonsWhenTimerNotWorking() //更改按钮
        timer.cancel() //取消计时器
        binding.timeTextView.text = formatTime(vm.pomodoroTimer.time) //格式化时间
    }

    private fun refreshValuesOnTextViews() {
        binding.timeTextView.text = formatTime(vm.pomodoroTimer.time) //格式化时间
        val anim = AlphaAnimation(1.0f, 0.0f) //创建一个 AlphaAnimation 对象
        anim.duration = 100 //设置动画持续时间
        anim.repeatCount = 1 //设置动画重复次数
        anim.repeatMode = Animation.REVERSE //设置动画重复模式

        anim.setAnimationListener(object : Animation.AnimationListener { 
            override fun onAnimationEnd(animation: Animation?) {}
            override fun onAnimationStart(animation: Animation?) {} 
            override fun onAnimationRepeat(animation: Animation?) {
                binding.changeDurationButton.text = vm.getTimerMode(vm.pomodoroTimer)
            }
        })//设置动画监听器
        binding.changeDurationButton.startAnimation(anim) //启动动画


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
        } //设置番茄进度
    }

    private fun playSong() {
        mediaPlayer = MediaPlayer.create(applicationContext, R.raw.daydream) //创建一个 MediaPlayer 对象
        mediaPlayer.start() //播放音乐
    }

    private fun vibrate() {

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S) { //如果 API 版本大于等于 30(考虑兼容性问题)
            val vibratorManager =
                getSystemService(VIBRATOR_MANAGER_SERVICE) as VibratorManager //创建一个 VibratorManager 对象
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
                //设置震动效果
                override fun onFinish() {
                    vibrator.cancel()
                }
            }.start() //启动计时器

        } else {
            val vibrator = getSystemService(VIBRATOR_SERVICE) as Vibrator
            vibrator.vibrate(500)
        }//设置震动效果

    }

    private fun changeButtonsWhenTimerWorking() { //更改按钮
        binding.playPauseButton.setImageResource(R.drawable.baseline_pause_24) //设置播放暂停按钮的图片
        if(binding.resetButton.visibility != VISIBLE){ //如果重置按钮不可见
            binding.resetButton.startAnimation(   //设置重置按钮的动画
                AnimationUtils.loadAnimation(  //加载动画
                    applicationContext,
                    R.anim.button_animation_to_visible
                )
            )
            binding.resetButton.visibility = VISIBLE //设置重置按钮可见
        }

        binding.changeDurationButton.isClickable = false //设置更改持续时间按钮不可点击
    }

    private fun changeButtonsWhenTimerNotWorking() { //更改按钮
        binding.playPauseButton.setImageResource(R.drawable.baseline_play_arrow_24) //设置播放暂停按钮的图片
        binding.changeDurationButton.isClickable = true //设置更改持续时间按钮可点击
    }
    private fun setInvisibleResetButton(){ //设置不可见的重置按钮
        binding.resetButton.startAnimation( //设置重置按钮的动画
            AnimationUtils.loadAnimation(
                applicationContext,
                R.anim.button_animation_to_invisible
            ) //加载动画
        )
        binding.resetButton.visibility = INVISIBLE //设置重置按钮不可见
    }

    private fun formatTime(seconds: Int): String { //格式化时间
        val minutes = seconds / SECONDS_IN_MINUTES //分钟数
        val remainingSeconds = seconds % SECONDS_IN_MINUTES //剩余秒数
        return String.format("%02d:%02d", minutes, remainingSeconds) //返回格式化后的时间
    }

    companion object { //伴生对象
        private const val SECONDS_IN_MINUTES = 60 //一分钟的秒数
        private const val MILLISECONDS_IN_SECONDS = 1000 //一秒的毫秒数
    } 
}
