package org.hyperskill.tests.stopwatch

import android.os.Handler
import android.view.View
import android.widget.Button
import android.widget.ProgressBar
import android.widget.TextView
import org.hyperskill.stopwatch.MainActivity
import org.hyperskill.tests.stopwatch.internals.CustomShadowCountDownTimer
import org.hyperskill.tests.stopwatch.internals.StopwatchUnitTest
import org.junit.Assert.*
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.robolectric.RobolectricTestRunner
import org.robolectric.annotation.Config
import java.util.concurrent.TimeUnit

// Version 2.0
@Config(
    instrumentedPackages = ["org.hyperskill.stopwatch"],
    shadows = [CustomShadowCountDownTimer::class]
)
@RunWith(RobolectricTestRunner::class)
class Stage3UnitTest : StopwatchUnitTest<MainActivity>(MainActivity::class.java) {


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

    private val progressBar: ProgressBar by lazy {
        activity.findViewByString("progressBar")
    }

    private val messageInvalidVisibility =
        "invalid progress bar visibility (VISIBLE = 0, INVISIBLE = 4, GONE = 8)"

    private val messageInvalidColor = "invalid progress bar color. LastColor: %d"

    @Before
    fun setup() {
        CustomShadowCountDownTimer.handler = Handler(activity.mainLooper)
    }

    @Test
    fun checkProgressBarExists() {
        testActivity {
            progressBar
        }
    }

    @Test
    fun checkProgressBarInvisibilityOnInit() {
        testActivity {
            val unexpected = View.VISIBLE
            val actual = progressBar.visibility
            assertNotEquals(messageInvalidVisibility, unexpected, actual)
        }
    }

    @Test
    fun checkProgressBarVisibilityOnStart() {
        testActivity {
            val expected = View.VISIBLE

            startButton.clickAndRun()

            val actual = progressBar.visibility
            assertEquals(messageInvalidVisibility, expected, actual)
        }

    }

    @Test
    fun checkProgressBarInvisibilityOnReset() {
        testActivity {
            val expectAfterStart = View.VISIBLE
            val unexpectedAfterReset = View.VISIBLE

            startButton.clickAndRun()

            val actualAfterStart = progressBar.visibility
            assertEquals(messageInvalidVisibility, expectAfterStart, actualAfterStart)

            resetButton.clickAndRun()

            val actualAfterReset = progressBar.visibility
            assertNotEquals(messageInvalidVisibility, unexpectedAfterReset, actualAfterReset)
        }

    }

    @Test
    fun checkMultipleClicks() {
        testActivity {
            val expectedAfterStart = View.VISIBLE
            val unexpectedAfterReset = View.VISIBLE

            startButton.clickAndRun()
            startButton.clickAndRun()

            val actualAfterStart = progressBar.visibility
            assertEquals(messageInvalidVisibility, expectedAfterStart, actualAfterStart)

            resetButton.clickAndRun()
            resetButton.clickAndRun()


            val actualAfterReset = progressBar.visibility
            assertNotEquals(messageInvalidVisibility, unexpectedAfterReset, actualAfterReset)
        }

    }

    @Test
    fun checkProgressBarColorEachSecond() {
        testActivity {
            startButton.clickAndRun(100)

            var lastColor: Int? = progressBar.indeterminateTintList?.defaultColor

            for (i in 0 until 10) {
                shadowLooper.idleFor(1_000, TimeUnit.MILLISECONDS)

                val actualColor = progressBar.indeterminateTintList?.defaultColor

                if (lastColor == actualColor) {
                    shadowLooper.runToEndOfTasks() // to prevent this misleading message since this in not the cause of test failure: java.lang.Exception: Main looper has queued unexecuted runnables. This might be the cause of the test failure. You might need a shadowOf(getMainLooper()).idle() call.
                    fail("$messageInvalidColor\nLastColor: $lastColor\nCurrentColor: $actualColor")
                }

                lastColor = actualColor
            }
        }
    }
}