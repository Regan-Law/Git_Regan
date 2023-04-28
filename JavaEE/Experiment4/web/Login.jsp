<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 4/28/2023
  Time: 12:58
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
	<title>login</title>
</head>
<body>
<form action="LoginControl.jsp" method="post">
	
	<table>
		<tr>
			<td>
				<label>
					用户名:
					<input name="username" type="text" id="username" placeholder="请输入用户名" required="required">
				</label>
			</td>
		</tr>
		<tr>
			<td>
				<label>
					密码:
					<input name="password" type="password" id="password" placeholder="请输入密码" required="required">
				</label>
			</td>
		</tr>
		<tr>
			<td>
				<input type="submit" name="Submit" value="登录">
				<input type="reset" name="Reset" value="重置">
			</td>
		</tr>
	</table>
</form>
</body>
</html>