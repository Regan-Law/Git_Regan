<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 2023/4/3
  Time: 19:14
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%!
	private int demoValue=56;
	
	public int getValue(){
		return demoValue;
	}%>
<html>
<body>
第一个表达式，value的值是<%=demoValue%> <br><!-- 表达式是一个变量-->
第二个表达式，value的值是<%=getValue()%> <br><!--表达式是一个具有返回值的函数-->
第三个表达式，<%="test"%> <!--表达式是一个对象-->
</body>
</html>