<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 4/28/2023
  Time: 12:58
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
	<title>RegisterSuccess</title>
</head>
<body>
<form action="Login.jsp" method="post">
	<%
		request.setCharacterEncoding("UTF-8");
		String username=request.getParameter("username");
		String password=request.getParameter("password");
		String name=request.getParameter("name");
		String sex=request.getParameter("sex");
		String hobby=request.getParameter("hobby");
		session.setAttribute("username",username);
		session.setAttribute("password",password);
	%>
	用户名：
	<%=username%><br>
	密码：<%=password%><br>
	姓名：<%=name%><br>
	性别：<%=sex%><br>
	爱好：<%=hobby%><br>
	<input type="submit" value="登录">
</form>
</body>
</html>