<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 5/15/2023
  Time: 19:17
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
	<title>Title</title>
</head>
<body>
<form action="exam_ans.jsp" method="post">
	<label>
		考号：
		<input type="text" name="id"/>
	</label>
	<p>
		一、单项选择题（每题2分）
		<br/><br/>
		1.下列哪个方法是获取session中关键字是key的对象（ ）。
		<br/>
		<label>
			<input type="radio" name="one" value="A"/>
			A．public void setAttribute(String key, Object obj)
		</label>
		<br/>
		<label>
			<input type="radio" name="one" value="B"/>
			B．public void removeAttribute(String key)
		</label>
		<br/>
		<label>
			<input type="radio" name="one" value="C"/>
			C．public Enumeration getAttributeNames()
		</label>
		<br/>
		<label>
			<input type="radio" name="one" value="D"/>
			D．public Object getAttribute(String key)
		</label>
		<br/>
	</p>
	<p>
		二、判断题（每题2分）
		<br/><br/>
		1.同一客户在多个Web服务目录中，所对应的session对象是互不相同的。
		<br/>
		<label>
			<input type="radio" name="two" value="True"/>
			True
		</label>
		<label>
			<input type="radio" name="two" value="False"/>
			False
		</label>
	</p><br/>
	<input type="submit" value="提交" name=submit>
	<input type="reset" value="重置" name=reset>
</form>

</body>
</html>