$(function () {
    $.ajax({
        url: 'http://mine233.com/lsl/findgoods',
        type: 'get',
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
            $('.item-con').find('ul').eq(0).html(htmlStr);
        }
    })
    // 登录之后添加用户账号
    if (localStorage.getItem("login") == 'true') {
        console.log(111);
        var acc = localStorage.getItem("account");
        $('.header-info').children().eq(0).find('a').html(acc)
    }
})



