function login() {
	var username = document.getElementById("input-id");
	var pass = document.getElementById("input-psd");

	if (username.value == "") {
		alert("请输入用户名");
	} else if (pass.value == "") {
		alert("请输入密码");
	} else if (username.value == "admin" && pass.value == "123456") {
		window.location.href = "workfianl.html";
	} else {
		alert("请输入正确的用户名和密码！");
	}
}
