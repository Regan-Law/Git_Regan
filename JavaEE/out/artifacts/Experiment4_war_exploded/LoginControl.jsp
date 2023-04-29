<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 4/28/2023
  Time: 12:59
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
	<title>LoginControl</title>
</head>
<body>
<form>
	<%
		request.setCharacterEncoding("UTF-8");
		String username=request.getParameter("username");
		String password=request.getParameter("password");
		String Username=session.getAttribute("username").toString();
		String Password=session.getAttribute("password").toString();
		if(username.equals(Username)&&password.equals(Password)){
			session.setAttribute("username",username);
			session.setAttribute("password",password);
			response.sendRedirect("LoginSuccess.jsp");
		}else{
			response.sendRedirect("Login.jsp");
		}
	%>
</form>
</body>
</html>