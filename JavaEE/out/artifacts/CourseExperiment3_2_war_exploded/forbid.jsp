<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 4/28/2023
  Time: 11:06
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
	<title>Title</title>
</head>
<body>
<%
	String name=request.getParameter("name");
	if(name.length()==0){
%>
<jsp:forward page="errorhandle.jsp"></jsp:forward>
<%
	}
%>
尊敬的<%=name%>你好,您未满18岁禁止进入游戏室！
<jsp:include page="foot.jsp"></jsp:include>
</body>
</html>