<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 5/15/2023
  Time: 19:17
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
	<title>Title</title>
</head>
<body>
<%
	//获取考号
	//获取session中关键字是id的对象（考号）
	String id=(String)session.getAttribute("id");
	//计算成绩
	int sum=0;
	//如果单项选择第一题选中D选项，得2分。
	//获取session中关键字是one的对象（选择答案）
	String first=(String)session.getAttribute("one");
	if("D".equals(first)){
		sum+=2;
	}
	//如果判断第一题选中True，得2分。
	//获取session中关键字是two的对象（判断答案）
	String second=(String)session.getAttribute("two");
	if("True".equals(second)){
		sum+=2;
	}
%>
您的成绩公布如下：
<table border="1">
	<tr>
		<th width="50%">
			考号
		</th>
		<th width="50%">
			成绩
		</th>
	</tr>
	<tr>
		<td><%=id%>
		</td>
		<td align="right"><%=sum%>
		</td>
	</tr>
</table>

</body>
</html>