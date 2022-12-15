window.onload = function()
{
    var html = document.documentElement,
xiproduct =document.querySelector('.xm-nav');
var initPos = xiproduct.offsetTop;
window.onscroll = function(){
    console.log(initPos);
    console.log(html.scrollTop)
    if(html.scrollTop >initPos){
        with(xiproduct.style){
            position = 'fixed';
            top = 0;
        }
    }else if(html.scrollTop==0){
        console.log('触发')
        xiproduct.style.position = 'relative';
    }
}
}