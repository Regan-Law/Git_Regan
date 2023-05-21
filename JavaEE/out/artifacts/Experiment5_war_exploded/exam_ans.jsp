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
<form action="exam_result.jsp">
	<%
		//考号
		String id=request.getParameter("id");
		//把考号id以“id”为关键字存储到session对象中
		session.setAttribute("id",id);
		//单项选择第一题
		String first=request.getParameter("one");
		//把答案first以“one”为关键字存储到session对象中
		session.setAttribute("one",first);
		//判断第一题
		String second=request.getParameter("two");
		//把答案second以“two”为关键字存储到session对象中
		session.setAttribute("two",second);
	%>
	您的考号：<%=id%><br/>
	一、单项选择题（每题2分）
	<br/>
	1.<%=first%>
	<br/>
	二、判断题（每题2分）
	<br/>
	1.<%=second%><br/>
	<input type="submit" value="确认完毕"/>
	<a href="exam.jsp">重新答题</a>
</form>
</body>
</html>