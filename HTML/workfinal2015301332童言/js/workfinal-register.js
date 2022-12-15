function register() {
	var username = document.getElementById("input-id");
	var email = document.getElementById("cfm");
	if (username.value == "") {
		alert("请输入手机号");
	} 
	else if (email.value == "") {
		alert("请输入验证码");
	} else if(email.value!==""&&username.value!=""){
		alert("注册成功！");
		window.location.href = "workfinal.html";}
}
