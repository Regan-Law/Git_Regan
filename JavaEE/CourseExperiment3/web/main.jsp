<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 4/28/2023
  Time: 10:04
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
	<title>计算</title>
</head>
<body>
<form action="main.jsp" method="post">
	<h2>请输入两个正整数</h2>
	<label for="num1">第一个正整数：</label><input type="number" name="num1" id="num1" autocomplete="off"/><br>
	<label for="num2">第二个正整数：</label><input type="number" name="num2" id="num2" autocomplete="off"/><br>
	<input type="submit" value="计算"/>
</form>
<jsp:include page="first.jsp"/>
<jsp:include page="second.jsp"/>
</body>
</html>