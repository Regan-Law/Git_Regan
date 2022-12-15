$(function () {
    //4.banner旁菜单l-list
    $(".l-list").children("li").hover(function () {
     
        $(this).css({ backgroundColor: "#ff6700" }).siblings().css({ backgroundColor: "transparent" });
        $(this).children(".child-list").css({ display: "block" }).parent().siblings().children(".child-list").css({ display: "none" });
        $(this).find("li").hover(function () {
            $(this).css({ color: "#ff6700" })
        }, function () {
            $(this).css({ color: "#333" })
        })
    }, function () {
        $(this).css({ backgroundColor: "transparent" }).children(".child-list").css({ display: "none" })
    })
      //5.切换tab
      $(".item-title").children(".more").find("li").hover(function () {
        $(this).addClass("active").siblings().removeClass("active");
        $(this).parents(".c-item").find(".item-con").removeClass("active").eq($(this).index()).addClass("active")
    })

    /* 回顶 */

    // let $backTop = $(".home-tool").find("ul").eq(1);
    // let $phoneTop = $(".c-item").eq(0).offset().top;

    
    // $(document).scroll(function(){
    //     let scrollTop = $(this).scrollTop();
      
    //     if(scrollTop > $phoneTop){
    //         $backTop.show()
    //     }else{
    //         $backTop.hide();
    //     }
    // })

    // $backTop.on("click", function(){
    //     $("html,body").animate({
    //           scrollTop  :0 ,
    //     })
    // })

    let $backTop = $(".home-tool").find("ul").eq(1);
    let $loft = $(".home-loft");
    let $phoneTop = $(".c-item").eq(0).offset().top;
    let $videoTop = $(".c-item").eq(6).offset().top;
    let $videoHeight = $(".c-item").eq(6).height();
    let $topList = [], $heightList = [];
    [...$(".c-item")].forEach((item, index) => {
        $topList.push($(item).offset().top)
        $heightList.push($(item).offset().top + $(item).height() + 22)
    })

    $(document).scroll(function () {
        let scrollTop = $(this).scrollTop();
        if (scrollTop > $phoneTop) {
            $backTop.show();
            if (scrollTop < $videoHeight + $videoTop) {
                $loft.show();
            }
        } else {
            $backTop.hide();
            $loft.hide();
        }
        let $index=$heightList.findIndex(item=>scrollTop<item);
        $(".home-loft").find("li").eq($index).addClass("active").siblings().removeClass("active");
    })

    $backTop.on("click", function () {
        $("html,body").animate({
            scrollTop: 0
        })
    })

    $(".home-loft").children().on("click", "li", function () {
        $("html,body").animate({
            scrollTop: $topList[$(this).index()]
        })
    })



    //8.开启轮播图
    new Swiper({
        el: $(".banner"),
        auto: true,
    })


})