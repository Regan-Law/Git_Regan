$(function () {
    //1.移入出现btn
    $(".item").hover(function () {
        $(this).find(".item-btn").stop().animate({
            "margin-top": -30,
        }, 200)
    }, function () {
        $(this).find(".item-btn").stop().animate({
            "margin-top": 28,
        }, 200)
    })
    if (localStorage.getItem('login') == "true") {
        var acc = localStorage.getItem("account");
        $(".h-info").eq(0).html(acc)
        $(".cart").hide();
        $("table").show();
        $(".cart-bar").show();
    } else {
        $(".cart").show();
        $("table").hide();
        $(".cart-bar").hide();
    }
    $(".h-info").click(function () {
        location.href = "./index.html"
    })
    //模拟登录userinfo 状态
    // $(".cart").hover(function () {
    //     $(".cart").hide();
    //     $("table").show();
    //     $(".cart-bar").show();

    // }, function () {
    //     $(".cart").show();
    //     $("table").hide();
    //     $(".cart-bar").hide();
    // })


    if (!localStorage.getItem("uid")) {
        $(".cart").show();
        $("table").hide();
        $(".cart-bar").hide();
    } else {
        $(".cart").hide();
        $("table").show();
        $(".cart-bar").show();
    }



    var uid = localStorage.getItem("uid");
    $.ajax({
        url: 'http://mine233.com/lsl/findcart',
        type: 'get',
        data: {
            uid: uid,
        },

        getType: 'json',
        success: function (result) {
            const data = JSON.parse(result.message);
            data.forEach(item => {
                if (item.img) {
                    let arr = item.img.split(",")
                    item.img = arr
                }
            });
            console.log(data);
            let htmlStr = template('tpl', {
                data,
            });

            $('#tab').html(htmlStr);

            function upDateCartBar() {
                let buyNumber = 0, tatalMoney = 0;
                $("#tab").children().each(function (index, item) {
                    buyNumber += Number($(item).children().eq(4).find("input").val());
                    tatalMoney += Number($(item).children().eq(5).text());
                })
                $(".buy-number").text(buyNumber);
                $(".total-money").text((tatalMoney));
            }
            upDateCartBar();

            /* 加减 */
            $("#tab").on("click", ".sub", function () {
                let num = $(this).next().val();
                num--;
                if (num <= 1) {
                    num = 1;
                }
                $(this).next().val(num);
                let price = $(this).parents("tr").children().eq(3).text();
                $(this).parents("tr").children().eq(5).text(num * price);

                upDateCartBar();
            })

            $("#tab").on("click", ".sup", function () {
                let num = $(this).prev().val();
                num++;
                $(this).prev().val(num);
                let price = $(this).parents("tr").children().eq(3).text();
                $(this).parents("tr").children().eq(5).text(num * price);
                upDateCartBar();
            })


            /* 删除 */
            var uid = localStorage.getItem("uid");
            $("#tab").on("click", ".del", function () {
                layer.confirm("尊敬的米主 确定删除您的宝贝吗", {
                    btn: ['下狠心删除宝贝', "可爱留下"]
                }, () => {
                    layer.msg("删除成功", { icon: 1 });
                    $(this).parents("tr").remove();
                    const hid = $(this).parents("tr").children().eq(0).text();
                    $.ajax({
                        url: "http://mine233.com/lsl/deletecart",
                        type: 'get',
                        dataType: 'json',
                        data: {
                            uid: uid,
                            pid: hid,
                        },

                    })
                    upDateCartBar();

                }, function () {

                });




            })


            // $(".pay").on("click", function (evt) {
            //     layer.confirm('亲 确定提交支付了吗，还需要加入宝贝吗？', {
            //         btn: ['确定', '取消']
            //     }, () => {
            //         layer.msg('支付成功', { icon: 1 });

            //         setTimeout(function () {
            //             location.href = "./finall.html"
            //         }, 2000)


            //     }, function () {
            //         layer.msg("取消成功", { icon: 4 })
            //     });
            // })


            $(".pay").click(function() {
                loading1();
               setTimeout(loading5, 3000)
               setTimeout(function(){
                   location.href= "./finall.html"
               },6000)
            }) 
        
            function loading1() {
                    $('body').loading({
                        loadingWidth: 240,
                        title: '请稍等!',
                        name: 'test',
                        discription: '正在支付中',
                        direction: 'column',
                        type: 'origin',
                        // originBg:'#71EA71',
                        originDivWidth: 40,
                        originDivHeight: 40,
                        originWidth: 6,
                        originHeight: 6,
                        smallLoading: false,
                        loadingMaskBg: 'rgba(0,0,0,0.2)'
                    });
                    setTimeout(function () {
                        removeLoading('test');
                        //跳转到首页
                    }, 3000);
                }
        
                function loading5() {
                    $('body').loading({
                        loadingWidth: 240,
                        title: '恭喜您',
                        name: 'test',
                        discription: '支付成功！',
                        direction: 'column',
                        type: 'pic',
                        originBg: '#71EA71',
                        originDivWidth: 60,
                        originDivHeight: 60,
                        originWidth: 6,
                        originHeight: 6,
                        smallLoading: false,
                        loadingBg: '#389A81',
                        loadingMaskBg: 'rgba(123,122,222,0.2)'
                    });
        
                    setTimeout(function () {
                        removeLoading('test');
                    }, 3000);
                }
        
        }
    })
})



