// 前端验证

window.onload = function () {
    function loading5(){
        $("body").loading({
            loadingWidth: 240,
            title: '恭喜您',
            name: 'test',
            discription: '注册成功！',
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
        },3000)
    }

    const  isub = document.querySelector(".input-sub")
    const  psd = document.querySelector('.input-psd')
    const cpsd = document.querySelector('.input-cpsd')
    console.log(cpsd);
    flag = true
    isub.onclick = function() {
        if(psd.value != cpsd.value) {
            cpsd.value = " "
            cpsd.setAttribute("data-missing", "密码不一致")
            flag = false
            console.log(111);
        }
        flag = true
        let result = Validate.start(".mi-form")
        if(result && flag) {
            // 前端验证通过进入后端验证
            uname = $('input[type=text]').val()
            pw = $('input[type=password]').val()
            email = $('input[type=email]').val()

            console.log(uname,pw);
            $.ajax({
                type : 'get',
                url: 'http://mine233.com/lsl/register',
                data : {
                    account : uname,
                    password: pw,
                    email:email
                },
                dataType : 'json',
                success: function (res) {
                    console.log(res);
                    loading5()
                    setTimeout(function() {
                        location.href = "./login2.html"
                    },1000)
                },
                error: function(err) {
                    alert('用户名已存在')
                    console.log(err);
                }
            })
        }
    

    
    }
}
