package org.hyperskill.tests.stopwatch.internals

import android.os.CountDownTimer
import android.os.Handler
import org.robolectric.annotation.Implementation
import org.robolectric.annotation.Implements
import org.robolectric.annotation.RealObject
import org.robolectric.shadow.api.Shadow
import org.robolectric.util.ReflectionHelpers.ClassParameter

// adapted from ShadowCountDownTimer
// https://github.com/robolectric/robolectric/blob/master/shadows/framework/src/main/java/org/robolectric/shadows/ShadowCountDownTimer.java
@Implements(CountDownTimer::class)
class CustomShadowCountDownTimer {

    companion object {
        var handler: Handler? = null
    }

    private var started = false
    var countDownInterval: Long = 0
        private set
    var millisInFuture: Long = 0
        private set

    var millisUntilFinished: Long = 0

    val runnable: Runnable = Runnable {
        invokeTick(millisUntilFinished)
    }

    @RealObject
    var countDownTimer: CountDownTimer? = null

    @Implementation
    protected fun __constructor__(millisInFuture: Long, countDownInterval: Long) {
        this.countDownInterval = countDownInterval
        this.millisInFuture = millisInFuture
        this.millisUntilFinished = millisInFuture
        started = false
        Shadow.invokeConstructor(
            CountDownTimer::class.java,
            countDownTimer,
            ClassParameter.from(Long::class.javaPrimitiveType, millisInFuture),
            ClassParameter.from(Long::class.javaPrimitiveType, countDownInterval)
        )
    }

    @Implementation
    @Synchronized
    protected fun start(): CountDownTimer? {
        started = true
        handler?.post(runnable)
        return countDownTimer
    }

    @Implementation
    protected fun cancel() {
        started = false
        handler?.removeCallbacks(runnable)
    }

    fun invokeTick(millisUntilFinished: Long) {
        countDownTimer!!.onTick(millisUntilFinished)
        this.millisUntilFinished = this.millisUntilFinished - countDownInterval
        if (this.millisUntilFinished >= 0) {
            handler?.postDelayed(runnable, countDownInterval)
        } else {
            invokeFinish()
        }
    }

    fun invokeFinish() {
        countDownTimer!!.onFinish()
    }

    fun hasStarted(): Boolean {
        return started
    }
}