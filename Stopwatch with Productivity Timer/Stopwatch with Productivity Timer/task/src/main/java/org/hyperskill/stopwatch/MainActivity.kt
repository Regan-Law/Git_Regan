package org.hyperskill.stopwatch

import android.annotation.SuppressLint
import android.app.AlertDialog
import android.app.Notification
import android.app.NotificationChannel
import android.app.NotificationManager
import android.app.PendingIntent
import android.content.Intent
import android.content.res.ColorStateList
import android.graphics.Color
import android.os.Build
import android.os.Bundle
import android.os.Handler
import android.os.Looper
import android.view.LayoutInflater
import android.view.View
import android.widget.Button
import android.widget.ProgressBar
import android.widget.TextView
import android.widget.Toast
import androidx.annotation.RequiresApi
import androidx.appcompat.app.AppCompatActivity
import androidx.core.app.NotificationCompat
import androidx.core.text.isDigitsOnly

enum class ProgressBarColor(val rgb: Int) {
    RED(Color.RED), YELLOW(Color.YELLOW), GREEN(Color.GREEN), BLUE(Color.BLUE), PURPLE(Color.MAGENTA), INDIGO(
        Color.CYAN
    ),
    VIOLET(Color.DKGRAY)
}

const val CHANNEL_ID = "org.hyperskill"

class MainActivity : AppCompatActivity() {
    @SuppressLint("SetTextI18n")
    @RequiresApi(Build.VERSION_CODES.O)
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val handler = Handler(Looper.getMainLooper())
        var timeCount = 0
        var timeLimit = 0
        var started = false
        var timeUp = false
        var textView = findViewById<TextView>(R.id.textView)
        val resetButton = findViewById<Button>(R.id.resetButton)
        val startButton = findViewById<Button>(R.id.startButton)
        val settingsButton = findViewById<Button>(R.id.settingsButton)
        val progressBar = findViewById<ProgressBar>(R.id.progressBar)
        val channel = NotificationChannel(
            CHANNEL_ID, "org.hyperskill", NotificationManager.IMPORTANCE_HIGH
        )
        val notificationManager = getSystemService(NOTIFICATION_SERVICE) as NotificationManager
        notificationManager.createNotificationChannel(channel)
        val intent = Intent(this, MainActivity::class.java).apply {
            flags = Intent.FLAG_ACTIVITY_NEW_TASK or Intent.FLAG_ACTIVITY_CLEAR_TASK
        }
        val pendingIntent = PendingIntent.getActivity(
            this,
            0,
            intent,
            PendingIntent.FLAG_IMMUTABLE
        )
        val notificationBuilder = NotificationCompat.Builder(this, CHANNEL_ID)
            .setSmallIcon(R.drawable.ic_launcher_foreground)
            .setContentTitle("Time Up")
            .setContentText("Time exceeded")
            .setPriority(NotificationCompat.PRIORITY_HIGH)
            .setOnlyAlertOnce(true)
            .setAutoCancel(true)
            .setContentIntent(pendingIntent)
            .setDefaults(Notification.DEFAULT_ALL)
        val notification = notificationBuilder.build()
        notification.flags = Notification.FLAG_ONLY_ALERT_ONCE or Notification.FLAG_INSISTENT
        progressBar.visibility = View.INVISIBLE
        progressBar.isIndeterminate = true
        val timeRun = object : Runnable {
            override fun run() {
                val time = String.format("%02d:%02d", timeCount / 60, timeCount % 60)
                textView = findViewById(R.id.textView)
                textView.text = time
                progressBar.indeterminateTintList =
                    ColorStateList.valueOf(ProgressBarColor.values()[timeCount % 7].rgb)
                if (timeLimit <= timeCount && timeLimit != 0) {
                    textView.setTextColor(Color.RED)
                    timeUp = true
                }
                if (timeUp) {
                    notificationManager.notify(393939, notification)

                }
                timeCount++
                if (started) handler.postDelayed(this, 1000)
                if (timeUp) {
                    started = false
                    handler.removeCallbacks(this)
                }
            }
        }
        startButton.setOnClickListener {
            if (!started) {
                started = true
                progressBar.visibility = View.VISIBLE
                settingsButton.isEnabled = false
                handler.post(timeRun)
            }
        }
        resetButton.setOnClickListener {
            textView.text = "00:00"
            started = false
            handler.removeCallbacks(timeRun)
            timeCount = 0
            progressBar.visibility = View.INVISIBLE
            settingsButton.isEnabled = true
            textView.setTextColor(Color.GRAY)
        }
        settingsButton.setOnClickListener {
            val alertDialogView =
                LayoutInflater.from(this).inflate(R.layout.alertdialog, null, false)
            AlertDialog.Builder(this)
                .setTitle("Set upper limit in seconds")
                .setView(alertDialogView)
                .setPositiveButton(android.R.string.ok) { _, _ ->
                    val limit =
                        alertDialogView.findViewById<TextView>(R.id.upperLimitEditText).text.toString()
                    if (limit.toInt() > 0 && limit.isDigitsOnly()) {
                        timeLimit = limit.toInt()
                    } else {
                        Toast.makeText(this, "Please enter a positive number", Toast.LENGTH_SHORT)
                            .show()
                    }
                }
                .setNegativeButton(android.R.string.cancel, null)
                .show()
            progressBar.visibility = View.INVISIBLE
        }
    }
}