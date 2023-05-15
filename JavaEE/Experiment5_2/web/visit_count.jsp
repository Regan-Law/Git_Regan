<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 5/15/2023
  Time: 19:51
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
	<title>Title</title>
</head>
<body>
<% Integer count=(Integer)application.getAttribute("count");
	if(count==null){
		application.setAttribute("count",1);
	}else{
		application.setAttribute("count",count+1);
	}%>
您是本系统的第<%=application.getAttribute("count")%>访问者!
</body>
</html>