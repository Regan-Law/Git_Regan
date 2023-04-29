<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 4/28/2023
  Time: 9:06
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
	<title>输入正整数</title>
</head>
<body>
<h2>输入两个正整数</h2>
<label for="num1">第一个正整数：</label><input type="number" name="num1" id="num1"/><br>
<label for="num2">第二个正整数：</label><input type="number" name="num2" id="num2"/><br>
<input type="button" value="求平均数" onclick="avg()"/>
<input type="button" value="求最大公约数" onclick="lcm()"/>
平均数：
<jsp:include page="first.jsp"/>
最大公约数：
<jsp:include page="second.jsp"/>
</body>
</html>