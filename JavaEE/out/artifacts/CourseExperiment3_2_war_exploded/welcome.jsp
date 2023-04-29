<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 4/28/2023
  Time: 11:03
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
<%=name%>你好,欢迎光临游戏室！
<jsp:include page="foot.jsp"></jsp:include>

</body>
</html>