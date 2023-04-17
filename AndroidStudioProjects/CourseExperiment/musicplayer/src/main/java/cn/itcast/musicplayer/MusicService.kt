package cn.itcast.musicplayer

import android.app.Service
import android.content.Intent
import android.media.MediaPlayer
import android.os.Binder
import android.os.Bundle
import android.os.IBinder
import android.os.Message
import java.util.*

class MusicService : Service() {
	var player: MediaPlayer? = null
	private var timer: Timer? = null
	override fun onBind(intent: Intent): IBinder {
		return MusicControl()
	}
	
	override fun onCreate() {
		super.onCreate()
		player = MediaPlayer()
	}
	
	fun addTimer() {
		timer = Timer()
		timer?.schedule(object : TimerTask() {
			override fun run() {
				val duration = player!!.duration
				val currentPosition = player!!.currentPosition
				val msg: Message = MainActivity.obtainMessage()
				val bundle = Bundle()
				bundle.putInt("duration", duration)
				bundle.putInt("currentPosition", currentPosition)
				msg.data = bundle
				MainActivity.handler?.sendMessage(msg)
			}
		}, 5, 500)
	}
	
	inner class MusicControl : Binder() {
		fun play() {
			try {
				player!!.reset()
				player = MediaPlayer.create(this@MusicService, R.raw.music)
				player!!.start()
				addTimer()
			} catch (e: Exception) {
				e.printStackTrace()
			}
		}
		
		fun pausePlay() {
			player!!.pause()
		}
		
		fun continuePlay() {
			player!!.start()
		}
		
		fun seekTo(progress: Int) {
			player!!.seekTo(progress)
		}
	}
	
	override fun onDestroy() {
		super.onDestroy()
		if (player?.isPlaying == true) {
			player!!.stop()
		}
		player!!.release()
		player = null
	}
}