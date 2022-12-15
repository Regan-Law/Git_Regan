$(function () {

    //1.logo点击
    $(".logo").mousedown(function () {
        $(this).animate({
            width: 52,
            height: 52,
            marginTop: -$(".logo").height() / 2,
            marginLeft: -$(".logo").width() / 2,
        }, 50)
    }).mouseup(function () {
        $(this).animate({
            width: 56,
            height: 56
        }, 50, () => {
            window.location.reload()
        })
    })

    //2.headNav下拉菜单
    $(".h-list").children("li").mouseenter(function () {
        let flag = false;
        $(this).parent().find(".down-menu-wrapper").each(function (index, item) {
            if ($(item).css("display") != "none") {
                flag = true;
            }
        })
        if (flag) {
            $(this).find(".down-menu-wrapper").css({ display: "block" }).end().siblings().find(".down-menu-wrapper").css({ display: "none" })
        } else {
            $(this).find(".down-menu-wrapper").stop().slideDown(500)
        }

        //取消搜索框下拉
        $(".h-search").find("input").css({
            "border-color": "#e0e0e0",
        }).siblings("button").css({
            "border-color": "#e0e0e0",
        }).siblings(".search-list").css({
            "display": "none",
        })
    })

    $(".h-list").mouseleave(function () {
        $(this).find(".down-menu-wrapper").stop().slideUp(0)
    })


    //3.h-search搜索框
    $(".h-search").find("input").click(function (event) {
        event.stopPropagation();//阻止事件冒泡
        $(this).css({
            "border-color": "#ff6700",
        }).siblings("button").css({
            "border-color": "#ff6700",
        }).siblings(".search-list").css({
            "display": "block",
        })
    })

    $(".search-list").on("click", "li", function (event) {
        $(this).parent().siblings("[ type='text']").val($(this).text());
    })

    $("body").click(function () {
        $(".h-search").find("input").css({
            "border-color": "#e0e0e0",
        }).siblings("button").css({
            "border-color": "#e0e0e0",
        }).siblings(".search-list").css({
            "display": "none",
        })
    })
    //4.渲染页面
    const hid = location.search.slice(5).trim();//获取商品的编号
    console.log(hid);
    $.ajax({
        url: 'http://mine233.com/lsl/findgoods',
        type: 'get',
        getType: 'json',
        data: {
            pid: hid
        },
        success: function (result) {
            console.log(result);
            const da = JSON.parse(result.message);
            console.log(da);
            let arr = da.img.split(',');
            console.log(arr);
            let htmlStr = template('tpl', {
                da, img_arr: arr
            });
            $('.product-box').html(htmlStr);
            // 分两部分渲染
            htmlStr = template('tpl1', {
                da, img_arr: arr
            });
            // 导航名称更改
            $('.xi-product').html(htmlStr);
            // 加入购物车请求
            var uid = localStorage.getItem("uid");// 指代用户
            $(".putin").click(function (event) {
                event.preventDefault();
                console.log(00);
                $.ajax({
                    url: 'http://mine233.com/lsl/addcart',
                    type: 'get',
                    dataType: 'json',
                    data: {
                        uid: uid,
                        pid: hid
                    },
                    success: function (res) {
                        console.log(res);
                    },
                    error: function (err) {
                        console.log(err);
                    }
                })
                layer.msg('已加入到购物车');
            })
            // 加入喜欢请求
            var uid = localStorage.getItem("uid");// 指代用户
            $(".likes").click(function (event) {
                event.preventDefault();
                console.log(00);
                $.ajax({
                    url: 'http://mine233.com/lsl/addfavorite',
                    type: 'get',
                    dataType: 'json',
                    data: {
                        uid: uid,
                        pid: hid
                    },
                    success: function (res) {
                        console.log(res);
                    },
                    error: function (err) {
                        console.log(err);
                    }
                })
                layer.msg('多谢米主的小心心！');
            })
            // 吸顶效果
            var html = document.documentElement,
                xiproduct = document.querySelector('.xm-nav');
            var initPos = xiproduct.offsetTop;
            window.onscroll = function () {
                console.log(initPos);
                console.log(html.scrollTop)
                if (html.scrollTop > initPos) {
                    with (xiproduct.style) {
                        position = 'fixed';
                        top = 0;
                    }
                } else if (html.scrollTop == 0) {
                    console.log('触发')
                    xiproduct.style.position = 'relative';
                }
            }
        }
    })
    //5.在头部设置账号
    if (localStorage.getItem("login") == 'true') {
        console.log(111);
        var acc = localStorage.getItem("account");
        $('.header-info').children().eq(0).find('a').html(acc)
        $(".login-notice").hide()
    }
    console.log($(".putin"));
})

