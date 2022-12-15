// 登录成功的弹出框
function loading5() {
    $('body').loading({
        loadingWidth: 240,
        title: '恭喜您',
        name: 'test',
        discription: '登录成功！',
        direction: 'column',
        type: 'pic',
        originBg: '#71EA71',
        originDivWidth: 60,
        originDivHeight: 60,
        originWidth: 6,
        originHeight: 6,
        smallLoading: false,
        loadingBg: '#389A81',
        loadingMaskBg: 'rgba(123,122,222,0.1)'
    });
    setTimeout(function () {
        removerLoding('test');
    }, 3000)
}

const isub = document.querySelector(".input-sub")
isub.onclick = function () {
    console.log(111);
    let result = Validate.start(".mi-form")
    console.log(result)
    //如果通过前端验证 进入后端验证
    if (result) {
        console.log(11111);
        uname = $('input[type=text]').val()
        pwd = $("input[type=password]").val()
        $.ajax({
            type: 'get',
            url: 'http://mine233.com/lsl/login',
            data: {
                account: uname,
                password: pwd,
            },
            dataType: 'json',
            success: function (res) {
                console.log(111);
                console.log(res.message);
                // 存起指代用户，独一无二
                localStorage.setItem('uid', JSON.parse(res.message).id)
                loading5()
                setTimeout(function () {
                    location.href = "./index.html"
                }, 2000)
                // 存入登录状态和账号，以便后需
                localStorage.setItem("login", 'true')
                localStorage.setItem('account', JSON.parse(res.message).account)
            },
            error: function (err) {
                alert('用户名或者密码错误')
                console.log(err);
            }
        })
    }
    return false
}




