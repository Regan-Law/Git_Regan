window.onload= function(){
    var lis_0 = document.querySelector('.wrapper li:first-child')
    lis_0.style.display = 'block';

        var nextBtn = document.querySelector('.turning a:last-child'),
            prevBtn = document.querySelector('.turning a:first-child');
    
        var lis = document.querySelectorAll('.wrapper li'),
            spans = document.querySelectorAll('.pagination span');
    
        var timer = null;
    
        var index = 0; // 指针 指示显示哪张图
        nextBtn.addEventListener('click', nextFrame);
        prevBtn.addEventListener('click', prevFrame);
        //两个左右<>的效果
       
       
        //点击下面小圆圈的效果
        //再次提醒，你不foreach，怎么区别里面的子元素？、记住，这些格式都是一样的，不管怎样绑定时间规定的格式
        spans.forEach(function (item, page) {
            item.onmouseenter = function () {
                // index->page
                index = page;//点到下面小圆圈，就执行这一页
                // 执行该帧
                perFrame();//yyds
            }
        })
    
        function nextFrame() {
            console.log(1111);
            index++;
            // 检测 如果超出 重置为0
            if (index >= lis.length) index = 0;
            // 执行这一帧
            perFrame();
        }
    
        function prevFrame() {
            index--;
            if (index < 0) index = lis.length - 1;
            perFrame();
        }
        
        // 显示该页图片,就很重要,所有的操作都会运行这一步，思路yyds，经典
        function perFrame() {
            init();
    
            // 先隐藏所有内容
            hideAll();
            // 切换显示的图片
            lis[index].style.display = 'block';
            // 高亮页面栏图标
            spans[index].classList.add('active');
        }
    
        function init() {
            // 每次执行时 都要重新初始化定时器
            if (timer) {
                clearInterval(timer);
                timer = null;
            }
            
            timer = setInterval(nextFrame, 3000); // 初始化 自动播放下一页
    
        }
    
        function hideAll() {
            lis.forEach(function (item, index) {
                item.style.display = 'none';
                spans[index].classList.remove('active');
            })
        }
    
        init();//只有打开网页那一下才运行了，后面都没进过这一句
}