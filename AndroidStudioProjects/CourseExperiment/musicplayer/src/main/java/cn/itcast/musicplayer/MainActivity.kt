package cn.itcast.musicplayer

import android.animation.ObjectAnimator
import android.annotation.SuppressLint
import android.content.ComponentName
import android.content.Intent
import android.content.ServiceConnection
import android.os.*
import android.view.View
import android.view.animation.LinearInterpolator
import android.widget.Button
import android.widget.SeekBar
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity(), View.OnClickListener {
	
	private lateinit var sb: SeekBar
	private lateinit var tv_progress: TextView
	private lateinit var tv_total: TextView
	lateinit var animator: ObjectAnimator
	lateinit var musicControl: MusicService.MusicControl
	private var isUnbind = false
	private var conn = MyServiceConn()
	override fun onCreate(savedInstanceState: Bundle?) {
		super.onCreate(savedInstanceState)
		setContentView(R.layout.activity_main)
		init()
	}
	
	private fun init() {
		tv_progress = findViewById(R.id.tv_progress)
		tv_total = findViewById(R.id.tv_total)
		sb = findViewById(R.id.sb)
		findViewById<Button>(R.id.btn_play).setOnClickListener(this)
		findViewById<Button>(R.id.btn_pause).setOnClickListener(this)
		findViewById<Button>(R.id.btn_continue_play).setOnClickListener(this)
		findViewById<Button>(R.id.btn_exit).setOnClickListener(this)
		intent = Intent(this, MusicService::class.java)
		conn = MyServiceConn()
		bindService(intent, conn, BIND_AUTO_CREATE)
		sb.setOnSeekBarChangeListener(object : SeekBar.OnSeekBarChangeListener {
			override fun onProgressChanged(p0: SeekBar?, p1: Int, p2: Boolean) {
				if (p1 == p0?.max) {
					animator.pause()
				}
			}
			
			override fun onStartTrackingTouch(p0: SeekBar?) {
			}
			
			override fun onStopTrackingTouch(p0: SeekBar?) {
				val progress = p0?.progress
				musicControl.seekTo(progress!!)
			}
		})
		val iv_music = findViewById<View>(R.id.iv_music)
		animator = ObjectAnimator.ofFloat(iv_music, "rotation", 0f, 360.0f)
		animator.duration = 10000
		animator.interpolator = LinearInterpolator()
		animator.repeatCount = -1
	}
	
	companion object handler : Handler(Looper.getMainLooper()) {
		@SuppressLint("StaticFieldLeak")
		lateinit var sb: SeekBar
		
		@SuppressLint("StaticFieldLeak")
		lateinit var tv_progress: TextView
		
		@SuppressLint("StaticFieldLeak")
		lateinit var tv_total: TextView
		lateinit var animator: ObjectAnimator
		
		@SuppressLint("SetTextI18n")
		override fun handleMessage(msg: Message) {
			super.handleMessage(msg)
			val bundle = msg.data
			val duration = bundle.getInt("duration")
			val currentPosition = bundle.getInt("currentPosition")
			var minute = duration / 1000 / 60
			var second = duration / 1000 % 60
			var strMinute: String? = if (minute < 10) {
				"0$minute"
			} else {
				"$minute"
			}
			var strSecond: String? = if (second < 10) {
				"0$second"
			} else {
				"$second"
			}
			tv_total.text = "$strMinute:$strSecond"
			minute = currentPosition / 1000 / 60
			second = currentPosition / 1000 % 60
			strMinute = if (minute < 10) {
				"0$minute"
			} else {
				"$minute"
			}
			strSecond = if (second < 10) {
				"0$second"
			} else {
				"$second"
			}
			tv_progress.text = "$strMinute:$strSecond"
			sb.max = duration
			sb.progress = currentPosition
			if (currentPosition == duration) {
				animator.pause()
			}
		}
	}
	
	inner class MyServiceConn : ServiceConnection {
		override fun onServiceConnected(p0: ComponentName?, p1: IBinder?) {
			musicControl = p1 as MusicService.MusicControl
		}
		
		override fun onServiceDisconnected(p0: ComponentName?) {
		}
	}
	
	private fun unbind(isUnbind: Boolean) {
		if (!isUnbind) {
			musicControl.pausePlay()
			unbindService(conn)
			stopService(intent)
		}
	}
	
	override fun onClick(v: View?) {
		when (v?.id) {
			R.id.btn_play -> {
				musicControl.play()
				animator.start()
			}
			
			R.id.btn_pause -> {
				musicControl.pausePlay()
				animator.pause()
			}
			
			R.id.btn_continue_play -> {
				musicControl.continuePlay()
				animator.resume()
			}
			
			R.id.btn_exit -> {
				unbind(isUnbind)
				isUnbind = true
				finish()
			}
		}
	}
	
	override fun onDestroy() {
		super.onDestroy()
		unbind(isUnbind)
	}
}