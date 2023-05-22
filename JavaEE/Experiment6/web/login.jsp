<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 5/22/2023
  Time: 19:32
--%>
<%@ page contentType="text/html;charset=UTF-8" %>
<html>
<head>
	<title>$Title$</title>
</head>
<body>
<form action="loginServlet.do" method="post">
	<table>
		<tr>
			<td>用户名：</td>
			<td><label>
				<input type="text" name="username"/>
			</label></td>
		</tr>
		<tr>
			
			<td>密码：</td>
			<td><label>
				<input type="password" name="password">
			</label></td>
		</tr>
		<tr>
			<td><label>
				<input type="submit" value="提交"/>
			</label></td>
			<td><label>
				<input type="reset" value="重置"/>
			</label></td>
		</tr>
	</table>
</form>
</body>
</html>