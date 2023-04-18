package org.hyperskill.tests.stopwatch.internals

import android.app.Activity
import android.app.AlarmManager
import android.os.Handler
import android.os.SystemClock
import androidx.core.content.getSystemService
import org.robolectric.Shadows
import org.robolectric.shadows.ShadowAlarmManager

open class StopwatchUnitTest<T : Activity>(clazz: Class<T>) : AbstractUnitTest<T>(clazz) {
    fun supportForAlarmManager() {
        val alarmManager = activity.getSystemService<AlarmManager>()
        val shadowAlarmManager: ShadowAlarmManager = Shadows.shadowOf(alarmManager)
        shadowAlarmManager.scheduledAlarms.lastOrNull()?.also {
            if (it.operation != null) {
                val pendingIntent = Shadows.shadowOf(it.operation)
                if (it.triggerAtTime < SystemClock.currentGnssTimeClock().millis()) {
                    it.operation.intentSender.sendIntent(
                        pendingIntent.savedContext,
                        pendingIntent.requestCode,
                        pendingIntent.savedIntent,
                        null,
                        Handler(activity.mainLooper)
                    )
                }
            } else if (it.onAlarmListener != null) {
                if (it.triggerAtTime < SystemClock.currentGnssTimeClock().millis()) {
                    it.onAlarmListener.onAlarm()
                }
            }
        }
    }
}