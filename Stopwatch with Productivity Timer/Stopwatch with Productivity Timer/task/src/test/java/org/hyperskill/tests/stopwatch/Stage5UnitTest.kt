package org.hyperskill.tests.stopwatch

import android.app.AlertDialog
import android.app.Notification
import android.app.NotificationChannel
import android.app.NotificationManager
import android.content.Context
import android.graphics.drawable.Icon
import android.os.Handler
import android.widget.Button
import android.widget.EditText
import org.hyperskill.stopwatch.MainActivity
import org.hyperskill.tests.stopwatch.internals.CustomShadowCountDownTimer
import org.hyperskill.tests.stopwatch.internals.StopwatchUnitTest
import org.junit.Assert.*
import org.junit.Before
import org.junit.FixMethodOrder
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.MethodSorters
import org.robolectric.RobolectricTestRunner
import org.robolectric.Shadows
import org.robolectric.annotation.Config
import org.robolectric.shadows.ShadowAlertDialog
import java.util.concurrent.TimeUnit

// Version 2.0.1
@FixMethodOrder(MethodSorters.NAME_ASCENDING)
@Config(
    instrumentedPackages = ["org.hyperskill.stopwatch"],
    shadows = [CustomShadowCountDownTimer::class]
)
@RunWith(RobolectricTestRunner::class)
class Stage5UnitTest : StopwatchUnitTest<MainActivity>(MainActivity::class.java) {

    companion object {
        const val CHANNEL_ID = "org.hyperskill"
        const val NOTIFICATION_ID = 393939
    }

    private val startButton: Button by lazy {
        val view = activity.findViewByString<Button>("startButton")

        val message = "For view with id \"startButton\", in property \"text\""
        assertEquals(message, "start", view.text.toString().lowercase())

        view
    }

    private val settingsButton: Button by lazy {
        val view = activity.findViewByString<Button>("settingsButton")

        val message = "For view with id \"settingsButton\", in property \"text\""
        assertEquals(message, "settings", view.text.toString().lowercase())

        view
    }

    private val resetButton: Button by lazy {
        val view = activity.findViewByString<Button>("resetButton")

        val message = "For view with id \"resetButton\", in property \"text\""
        assertEquals(message, "reset", view.text.toString().lowercase())

        view
    }

    private val notificationManager by lazy {
        Shadows.shadowOf(
            activity.getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager
        )
    }

    @Before
    fun setup() {
        CustomShadowCountDownTimer.handler = Handler(activity.mainLooper)
    }

    @Test
    fun test01_CheckNotificationIsNotSentBeforeTimeLimit() {
        testActivity {
            val timeLimit = 15

            settingsButton.clickAndRun()
            val dialog = ShadowAlertDialog.getLatestAlertDialog()
            dialog.findViewByString<EditText>("upperLimitEditText").setText("$timeLimit")
            dialog.getButton(AlertDialog.BUTTON_POSITIVE).clickAndRun()

            val timeToSleep = timeLimit * 1000L - 600
            startButton.clickAndRun(timeToSleep)

            supportForAlarmManager()
            shadowLooper.idleFor(300, TimeUnit.MILLISECONDS)

            val notification: Notification? = notificationManager.getNotification(NOTIFICATION_ID)

            val messageBeforeTimeLimit =
                "There should be no notification sent before the time limit is exceeded"
            assertNull(messageBeforeTimeLimit, notification)
        }
    }

    @Test
    fun test02_CheckNotificationIsNotSentWithTimeLimitSetToZero() {
        testActivity {
            val timeLimit = 0

            settingsButton.clickAndRun()
            val dialog = ShadowAlertDialog.getLatestAlertDialog()
            dialog.findViewByString<EditText>("upperLimitEditText").setText("$timeLimit")
            dialog.getButton(AlertDialog.BUTTON_POSITIVE).clickAndRun()

            val timeToSleep = 20_000L
            startButton.clickAndRun(timeToSleep)

            supportForAlarmManager()
            shadowLooper.idleFor(300, TimeUnit.MILLISECONDS)

            val notification: Notification? = notificationManager.getNotification(NOTIFICATION_ID)

            val messageTimeLimitZero =
                "There should be no notification sent if time limit is zero"
            assertNull(messageTimeLimitZero, notification)
        }
    }

    @Test
    fun test03_CheckNotificationIsNotSentWithTimeLimitSetToNegative() {
        testActivity {
            val timeLimit = -10

            settingsButton.clickAndRun()
            val dialog = ShadowAlertDialog.getLatestAlertDialog()
            dialog.findViewByString<EditText>("upperLimitEditText").setText("$timeLimit")
            dialog.getButton(AlertDialog.BUTTON_POSITIVE).clickAndRun()

            val timeToSleep = 3_000L
            startButton.clickAndRun(timeToSleep)

            supportForAlarmManager()
            shadowLooper.idleFor(300, TimeUnit.MILLISECONDS)

            val notification: Notification? = notificationManager.getNotification(NOTIFICATION_ID)

            val messageTimeLimitNegative =
                "There should be no notification sent if time limit is negative"
            assertNull(messageTimeLimitNegative, notification)
        }
    }

    @Test
    fun test04_CheckNotificationIsNotSentClickingResetBeforeTimeExceeded() {
        testActivity {
            val timeLimit = 10

            settingsButton.clickAndRun()
            val dialog = ShadowAlertDialog.getLatestAlertDialog()
            dialog.findViewByString<EditText>("upperLimitEditText").setText("$timeLimit")
            dialog.getButton(AlertDialog.BUTTON_POSITIVE).clickAndRun()

            val timeToSleep = ((timeLimit * 1000) / 2) + 1100L
            startButton.clickAndRun(timeToSleep)
            resetButton.clickAndRun(timeToSleep)

            supportForAlarmManager()
            shadowLooper.idleFor(300, TimeUnit.MILLISECONDS)

            val notification: Notification? = notificationManager.getNotification(NOTIFICATION_ID)

            val messageTimeLimitNegative =
                "There should be no notification sent if reset button is clicked before time limit is exceeded"
            assertNull(messageTimeLimitNegative, notification)
        }
    }

    @Test
    fun test05_CheckNotificationIsSentOnTimeLimitExceeded() {
        testActivity {
            val timeLimit = 10

            settingsButton.clickAndRun()
            val dialog = ShadowAlertDialog.getLatestAlertDialog()
            dialog.findViewByString<EditText>("upperLimitEditText").setText("$timeLimit")
            dialog.getButton(AlertDialog.BUTTON_POSITIVE).clickAndRun()

            val timeToSleep = timeLimit * 1000 + 1100L
            startButton.clickAndRun(timeToSleep)

            val notificationChannel =
                notificationManager.notificationChannels.mapNotNull {
                    it as NotificationChannel?
                }.firstOrNull {
                    it.id == CHANNEL_ID
                }

            supportForAlarmManager()
            shadowLooper.idleFor(300, TimeUnit.MILLISECONDS)

            assertNotNull(
                "Could not find any NotificationChannel with id \"$CHANNEL_ID\"",
                notificationChannel
            )
            notificationChannel!!

            assertTrue(
                "Wrong importance for NotificationChannel, should be IMPORTANCE_HIGH",
                NotificationManager.IMPORTANCE_HIGH == notificationChannel.importance
            )

            val notification: Notification? = notificationManager.getNotification(NOTIFICATION_ID)

            val messageNotificationId =
                "Could not find notification with id 393939. Did you set the proper id?"
            assertNotNull(messageNotificationId, notification)
            notification!!

            val messageChannelId = "The notification channel id does not equals \"$CHANNEL_ID\""
            val actualChannelId = notification.channelId
            assertEquals(messageChannelId, CHANNEL_ID, actualChannelId)

            val messageIcon = "Have you set the notification smallIcon?"
            val actualIcon: Icon? = notification.smallIcon
            assertNotNull(messageIcon, actualIcon)

            val messageTitle = "Have you set the notification title?"
            val actualTitle =
                notification.extras.getCharSequence(Notification.EXTRA_TITLE)?.toString()
            assertNotNull(messageTitle, actualTitle)

            val messageContent = "Have you set the notification content?"
            val actualContent =
                notification.extras.getCharSequence(Notification.EXTRA_TEXT)?.toString()
            assertNotNull(messageContent, actualContent)

            val messageOnlyOnce = "Have you set the notification to only alert once?"
            val expectedOnlyOnceFlags = Notification.FLAG_ONLY_ALERT_ONCE
            val actualOnlyOnceFlags = notification.flags.and(Notification.FLAG_ONLY_ALERT_ONCE)
            assertTrue(messageOnlyOnce, expectedOnlyOnceFlags == actualOnlyOnceFlags)

            val messageInsistent = "Have you set the notification to be insistent?"
            val expectedInsistentFlags = Notification.FLAG_INSISTENT
            val actualInsistentFlags = notification.flags.and(Notification.FLAG_INSISTENT)
            assertTrue(messageInsistent, expectedInsistentFlags == actualInsistentFlags)
        }
    }
}

