
$(function () {
    let name;
    var uid = localStorage.getItem("uid");
    $.ajax({
        url: 'http://mine233.com/lsl/findfavorite',
        type: 'get',
        data: {
            uid: uid,
            name :"wj" ,
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
            $('.goods-fav').html(htmlStr);
            // 删除喜欢
            
    
            $('.del').on('click',  function (evt) {
                evt.preventDefault();
                console.log(evt);
               
                // // 询问框
                layer.confirm('确定要删除吗？', {
                    btn: ['确定', '取消'] //按钮
                }, () => {
                    layer.msg('已删除', { icon: 1 });
                    // 从数据库删除
                 
                    var hid;
                 
                   var pname =  $(this).parents('.goods-fav').find("#aa").text().trim().slice(0,4);
                   console.log(pname);
                  
                    data.forEach(item => {
                        console.log(pname);
                        
                        if(item.pName.includes(pname)){
                            hid = item.id;
                        }
                    })
                    console.log(data);
                    console.log(hid);
                   $(this).parents('.xm-goods-list').remove();
                    $.ajax({
                        url:"http://mine233.com/lsl/delfavorite",
                        type:"get",
                        datatype:"json",
                        data:{  
                            uid : uid,
                            pid :  hid,
                        },
                        // success :
                    })
                }, function () {
                    //    取消的操作不需要操作k
                });
                // 第二种写法
                // layer.open({
                //     content: '确定要删除吗？'
                //     , btn: ['确定', '取消']
                //     , yes: function (index, layero) {
                //         console.log(layero);
                //         //按钮【按钮一】的回调
                //         // 这个this不对
                //         $(this).parents('.xm-goods-list').remove();
                //         // alert(1);
                //     }
                // $(function () {
                //     $('.del').on('click', function (evt) {
                //         evt.preventDefault();
                //         if(window.confirm('确定要删除该项吗？')){
                //            $(this).parents('.xm-goods-list').remove();
                //         }
                //     })
                // })
        
            })
        }
    })
       //.在头部设置账号
       if (localStorage.getItem("login") == 'true') {
        console.log(111);
        var acc = localStorage.getItem("account");
        $('.header-info').children().eq(0).find('a').html(acc)
    } 
})
