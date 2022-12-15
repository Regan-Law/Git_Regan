
/******1.*验证***/

//----H5

/***********用户名输入验证**********/
/*uname.onblur=function(){
	if(this.validity.valueMissing){
		var msg ='用户名密码不能为空';
		this.nextElementSibling.innerHTML = msg;
		this.nextElementSibling.className='help-block bg-danger';
		this.setCustomValidity(msg);
	}else if(this.validity.tooShort){
		 var msg='用户名不能少于6位!';
		 this.nextElementSibling.innerHTML=msg;
		 this.nextElementSibling.className="help-block bg-danger";
		 this.setCustomValidity(msg);
	}else if(this.validity.tooLong){
		 var msg='用户名不能多于9位';
		 this.nextElementSibling.innerHTML=msg;
		 this.nextElementSibling.className="help-block bg-danger";
		 this.setCustomValidity(msg);
	}else{
		 this.nextElementSibling.innerHTML='用户名输入合法';
		 this.nextElementSibling.className='help-block bg-success';
		 this.setCustomValidity('');
	}
}*/
/*******密码********/
upwd.onblur=function(){
	if(this.validity.valueMissing){
		this.nextElementSibling.innerHTML='密码不能为空';
		this.nextElementSibling.className='help-block bg-danger';
	}else if(this.validity.tooShort){
		this.nextElementSibling.innerHTML='密码不能少于6位';
		this.nextElementSibling.className='help-block bg-danger';
	}else {
		 this.nextElementSibling.innerHTML='密码输入正确';
		 this.nextElementSibling.className='help-block bg-success';
	}

}
//-------------->用户名和密码此处必须在html中写required不然不填不走第一个if（配套）


//---

var uname =document.getElementById('uname');
uname.onblur=function(){
	 var val=uname.value;
	if(val===""){
		this.nextElementSibling.innerHTML="用户名不能为空"
		 this.nextElementSibling.className='help-block bg-danger';
	}else if(val.length<3||val.length>9){
		 this.nextElementSibling.innerHTML="用户名大于3位小于6位";
		 this.nextElementSibling.className='help-block bg-danger';
	}else{
		 this.nextElementSibling.innerHTML="用户名输入正确";
		 this.nextElementSibling.className='help-block bg-success';
	}
}
//对邮箱进行验证
$('#email').blur(function(){
	 if(this.validity.typeMismatch){
			this.nextElementSibling.innerHTML='邮箱格式不正确';
			this.nextElementSibling.className='help-block bg-danger';
			this.setCustomValidity('请输入xx@xx.cn/com');
	 }else{
			this.nextElementSibling.innerHTML='邮箱格式正确';
			this.nextElementSibling.className='help-block bg-success';
			this.setCustomValidity('');
	 }
})

/****2.异步提交注册******/





























