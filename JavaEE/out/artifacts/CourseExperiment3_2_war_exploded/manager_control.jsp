<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 4/28/2023
  Time: 11:04
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
	<title>Title</title>
</head>
<body>
<%
	String name=request.getParameter("name");
	int age=Integer.parseInt(request.getParameter("age"));
	
	if(age>18){
%>
<jsp:forward page="welcome.jsp">
	<jsp:param value="<%=name %>" name="name"/>
</jsp:forward>
<%
}else{
%>
<jsp:forward page="forbid.jsp"/>
<%}%>

</body>
</html>