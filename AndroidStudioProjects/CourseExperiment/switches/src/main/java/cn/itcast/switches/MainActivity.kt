package cn.itcast.switches

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.ImageView
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
	private var btn_switch: Button? = null
	private var iv_open: ImageView? = null
	private var iv_close: ImageView? = null
	private var isOpen: Boolean = false
	override fun onCreate(savedInstanceState: Bundle?) {
		super.onCreate(savedInstanceState)
		setContentView(R.layout.activity_main)
		init()
	}
	
	private fun init() {
		btn_switch = findViewById(R.id.btn_switch)
		iv_open = findViewById(R.id.iv_open)
		iv_close = findViewById(R.id.iv_close)
		btn_switch?.setOnClickListener {
			if (isOpen) {
				btn_switch?.text = "开灯"
				btn_switch?.setBackgroundResource(R.mipmap.btn_close)
				iv_open?.visibility = ImageView.INVISIBLE
				iv_close?.visibility = ImageView.VISIBLE
				isOpen = false
				val intent = Intent(this, MyService::class.java)
				stopService(intent)
			} else {
				btn_switch?.text = "关灯"
				btn_switch?.setBackgroundResource(R.mipmap.btn_open)
				iv_open?.visibility = ImageView.VISIBLE
				iv_close?.visibility = ImageView.INVISIBLE
				isOpen = true
				val intent = Intent(this, MyService::class.java)
				startService(intent)
			}
		}
	}
}