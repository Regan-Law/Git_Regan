<%--
  Created by IntelliJ IDEA.
  User: Regan
  Date: 4/28/2023
  Time: 12:58
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
	<title>Register</title>
</head>
<body>
<form action="RegisterSuccess.jsp" method="post">
	<table>
		<tr>
			<td><label>用户名：
				<input type="text" name="username" required="required">
			</label></td>
		</tr>
		<tr>
			<td>
				<label>
					密 码：
					<input type="password" name="password" required="required">
				</label>
			</td>
		</tr>
		<tr>
			<td>
				<label>
					姓 名：
					<input type="text" name="name" required="required">
				</label>
			</td>
		</tr>
		<tr>
			<td>
				<label>
					性 别：
					<input name="sex" type="radio" value="男" checked="checked">男
					<input name="sex" type="radio" value="女">女
				</label>
			</td>
		</tr>
		<tr>
			<td>
				<label>
					爱 好：
					<input name="hobby" type="checkbox" value="篮球">篮球
					<input name="hobby" type="checkbox" value="足球">足球
					<input name="hobby" type="checkbox" value="排球">排球
					<input name="hobby" type="checkbox" value="羽毛球">羽毛球
					<input name="hobby" type="checkbox" value="乒乓球">乒乓球
				</label><br>
			</td>
		</tr>
		<tr>
			<td>
				<input type="submit" value="注册">
				<input type="reset" value="重置">
			</td>
		</tr>
	</table>
</form>
</body>
</html>