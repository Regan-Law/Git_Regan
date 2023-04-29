<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 4/28/2023
  Time: 9:06
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
	<title>平均数</title>
</head>
<body>
<label>平均数：</label>
<% int num1=request.getIntHeader("num1");
	int num2=request.getIntHeader("num2");
	float avg=(num1+num2);
	out.println(avg);
%>
</body>
</html>