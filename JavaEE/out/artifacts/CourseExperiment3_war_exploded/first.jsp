<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 4/28/2023
  Time: 10:04
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
	<title>平均数</title>
</head>
<body>
<label>平均数：</label>
<% float num1=request.getParameter("num1")==null ? 0 : Integer.parseInt(request.getParameter("num1"));
	float num2=request.getParameter("num2")==null ? 0 : Integer.parseInt(request.getParameter("num2"));
	float avg=(num1+num2)/2;
	out.println(avg);
%>
</body>
</html>