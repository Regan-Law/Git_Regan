<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 4/28/2023
  Time: 9:06
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
	<title>最大公约数</title>
</head>
<body>
<label>最大公约数</label>
<% int num1=Integer.parseInt(request.getParameter("num1"));
	int num2=Integer.parseInt(request.getParameter("num2"));
	int max=0;
	for(int i=1;i<=num1;i++){
		if(num1%i==0&&num2%i==0){
			max=i;
		}
	}
	out.print(max);%>
</body>
</html>