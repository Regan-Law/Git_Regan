//if(window.$===undefined){
//	throw new Error("myPlugins库依赖于jQuery库")
//}
jQuery.fn.tabs=function(){
	
	this.addClass("tabs");//为父元素添加tabs
	this.find(".top>ul>li:first").addClass("active");//找到第一个显示的头头 (即标题)---> 添加acctive 为display:block
	this.find("ul.rt_li:first").addClass("active");//找到第一个显示的标题下的内容   -->添加acctive  为display :block
	$(".top>ul>li>a").hover(function(e){//找到要点击或者鼠标进入时的元素 为其添事件
		e.preventDefault();//阻止a默认行为
		$(this).parent().addClass("active").siblings(".active")
			.removeClass("active");
		$($(this).attr("href")).addClass("active").siblings(".active")
			.removeClass("active");	
	});
}
