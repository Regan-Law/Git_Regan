<div class="step-text">
<h5 id="description" style="text-align: center;">Description</h5>
<p>In this stage, you should add a simple stopwatch logic to your app. The stopwatch should start on the <code class="java">Start</code> button press and resets on the <code class="java">Reset</code> button. The elapsed time is shown in the <code class="java">TextView</code> component. Also, the timer should start from 00:00 and the first change should be after a second passed: 00:01.</p>
<p>The simplest way to implement this functionality is to use <a href="https://developer.android.com/reference/android/os/Handler" rel="noopener noreferrer nofollow" target="_blank">android.os.Handler</a> and its methods, <code class="java">postDelayed</code> or <code class="java">postAtTime</code>.</p>
<h5 id="objectives" style="text-align: center;">Objectives</h5>
<p>Add functionality for the <code class="java">Start</code> and <code class="java">Reset</code> buttons. <code class="java">TextView</code> should display the elapsed time in the format <code class="java">"mm:ss"</code> and behave the following way:</p>
<ol>
<li>The initial <code class="java">TextView</code> state is <code class="java">"00:00"</code>.</li>
<li>After pressing the <code class="java">Start</code> button, the time in <code class="java">TextView</code> starts counting from <code class="java">"00:00"</code>.</li>
<li>After pressing the <code class="java">Reset</code> button, the time in <code class="java">TextView</code> is set to <code class="java">"00:00"</code> and should not increase until the <code class="java">Start</code> button is pressed again.</li>
<li>Pressing the <code class="java">Start</code> button while the time is going does not affect the stopwatch: it simply continues without resetting to <code class="java">"00:00"</code>.</li>
<li>Don’t use <code class="java">startButton.isEnabled = false </code> to implement item 4. For this requirement test will ignore this parameter and click the button anyway. There is a more interesting lesson to be learned here. Hint: take care of your thread management, specially threads involved in the logic for updating the counter</li>
</ol>
<p>
	Obs: Tests are relying on time emulation since version 2.0 of tests. Although it is possible to implement the counter feature
	using thread schedulers coming from <code class="java">java.util</code>, they probably won't work with tests time emulation,
	like for example <code class="java">java.util.Timer</code> is proven to be incompatible.
	Prefer to use solutions coming from android package. Using <code class="java">android.os.Handler</code> is guaranteed to work and
	<code class="java">android.os.CountDownTimer</code> should work as well.
	Some apis for retrieving time cues coming from <code class="java">java.util</code> might also be affected, but for this project calling
	<code class="java">System.currentTimeMillis()</code> directly should work as expected.
</p>
<h5 id="example" style="text-align: center;">Example</h5>
<p>Below you can see an example of how your application should work at this stage.</p>
<p style="text-align: center;"><img alt="" height="400" src="https://ucarecdn.com/778c4cd4-4f2a-4744-8567-ba8379ec1df7/" width="189"/></p>
</div>