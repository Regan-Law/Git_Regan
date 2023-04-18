package org.hyperskill.tests.stopwatch

import android.os.Handler
import android.widget.Button
import android.widget.TextView
import org.hyperskill.stopwatch.MainActivity
import org.hyperskill.tests.stopwatch.internals.CustomShadowCountDownTimer
import org.hyperskill.tests.stopwatch.internals.StopwatchUnitTest
import org.junit.Assert.assertEquals
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.robolectric.RobolectricTestRunner
import org.robolectric.annotation.Config

// Version 2.0
@Config(
    instrumentedPackages = ["org.hyperskill.stopwatch"],
    shadows = [CustomShadowCountDownTimer::class]
)
@RunWith(RobolectricTestRunner::class)
class Stage2UnitTest : StopwatchUnitTest<MainActivity>(MainActivity::class.java) {


    private val startButton: Button by lazy {
        val view = activity.findViewByString<Button>("startButton")

        val message = "For view with id \"startButton\", in property \"text\""
        assertEquals(message, "start", view.text.toString().lowercase())

        view
    }

    private val resetButton: Button by lazy {
        val view = activity.findViewByString<Button>("resetButton")

        val message = "For view with id \"resetButton\", in property \"text\""
        assertEquals(message, "reset", view.text.toString().lowercase())

        view
    }

    private val textView: TextView by lazy {
        activity.findViewByString("textView")
    }

    private val messageTextViewAssertionError =
        "For view with id \"textView\", in property \"text\""

    @Before
    fun setup() {
        CustomShadowCountDownTimer.handler = Handler(activity.mainLooper)
    }

    @Test
    fun checkCheckTimerInitialValue() {
        testActivity {
            val expected = "00:00"
            val actual = textView.text
            val message = "Wrong initial value. $messageTextViewAssertionError"
            assertEquals(message, expected, actual)
        }
    }

    @Test
    fun checkTakeOneSecondToCountOneSecondOnStartButtonClick() {
        testActivity {
            val expected = "00:00"

            startButton.clickAndRun(300)

            val actual = textView.text
            val message =
                "It should take one second to count one second. $messageTextViewAssertionError"
            assertEquals(message, expected, actual)
        }
    }

    @Test
    fun checkCountOneSecondAfterOneSecondOnStartButtonClick() {
        testActivity {
            val expected = "00:01"

            startButton.clickAndRun(1100)

            val actual = textView.text
            val message =
                "After one second one second should be counted. $messageTextViewAssertionError"
            assertEquals(message, expected, actual)
        }
    }


    @Test
    fun checkStopTimerAndResetCountOnResetButtonClick() {
        testActivity {
            val expected = "00:00"

            startButton.clickAndRun(1100)
            resetButton.clickAndRun(200)

            val actual = textView.text
            val message = "After reset the counter should reset. $messageTextViewAssertionError"
            assertEquals(message, expected, actual)
        }
    }

    @Test
    fun checkContinueCountOnPressingStartButtonAgain() {
        testActivity {
            val expected = "00:11"
            startButton.clickAndRun(1100)

            startButton.performClick()
            startButton.performClick()
            startButton.clickAndRun(10_100)

            val actual = textView.text
            val message =
                "Clicking start multiple times should still count one second per second. " +
                        messageTextViewAssertionError
            assertEquals(message, expected, actual)
        }
    }

    @Test
    fun checkIgnorePressingResetButtonAgain() {
        testActivity {
            val expected = "00:00"

            startButton.clickAndRun(10_000)
            resetButton.clickAndRun(10_000)
            resetButton.clickAndRun(10_000)

            val actual = textView.text
            val message =
                "Clicking reset multiple times should still keep counter reset. " +
                        messageTextViewAssertionError
            assertEquals(message, expected, actual)
        }
    }

    @Test
    fun checkDisplayOneMinuteInsteadOf60Seconds() {
        testActivity {
            val expected = "01:00"

            startButton.clickAndRun(60_100)

            val actual = textView.text
            val message = "60 seconds should be one minute. $messageTextViewAssertionError"
            assertEquals(message, expected, actual)
        }
    }

    @Test
    fun checkMinuteIsNotEarly() {
        testActivity {
            val expected = "01:59"

            startButton.clickAndRun(119_700)

            val actual = textView.text
            assertEquals("Don't rush on counting. $messageTextViewAssertionError", expected, actual)
        }
    }
}