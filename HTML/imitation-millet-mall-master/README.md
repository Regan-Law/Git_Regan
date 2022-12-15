# store （参考小米商城）

##  前言

​	关于为什么决定模仿小米商城编写页面，我想主要是因为小米的那种极简理念，产品和生活的相结合，打动了我，和生活的道理不谋而合，另一方面的话，这也是一个商城系列的，有很多之前学过的效果，也能找到一些参考方向，巩固一下之前学过的东西，同时它也具有一定的挑战性。，

## 说明

​	本项目前后端分离，前端参考小米商城实现。

##  项目简介

​	本项目前后端分离，前端基于`HTML+CSS+`JavaScript`+`Ajax+`jQuery`，参考小米商城实现。后端基于`servlet`+`Mysql`实现。

前端包含了6个页面：首页、登录、注册、商品详情页、我的收藏、购物车。

实现了商品的展示、商品详细信息动态展示、登录、注册、用户购物车、订单结算、用户收藏列表以及表单验证功能。

 ## 技术栈

- **前端：**`HTML+CSS+`JavaScript`+`Ajax+`jQuery`
- **后端：**servlet框架
- **数据库：**`Mysql`

## 功能模块

 ### 全局组件

- ​	**第三方插件**:Swiper+layui+loading+jQuery+iconfont

###  登录

​	按钮使用了loading插件中的效果，当登录成功后会过三秒之后跳转到首页当中，导航条上会显示注册的号码，会有这个用户收藏的商品，以及加入购物车的商品，若用户没加入商品到购物车，则为空。

登录按钮这样设计是为了既可以通过点击页面中的按钮登录，也可以是用户访问需要登录验证的页面或后端返回需要验证登录的提示后自动弹出登录框，减少了页面的跳转，简化用户操作。

用户输入的数据往往是不可靠的，所以本项目前后端都对登录信息进行了校验，前端基于validate的表单校验方式，自定义了校验规则进行校验，当前端验证成功后，会跳入后端验证数据是否准确，成功后才会成功登入。

登录处理主要代码：

​	`const isub = document.querySelector(".input-sub")`

`isub.onclick = function () {`

  `console.log(111);`

  `let result = Validate.start(".mi-form")`

  `console.log(result)`

  `//如果通过前端验证 进入后端验证`

  `if (result) {`

​    `console.log(11111);`

​    `uname = $('input[type=text]').val()`

​    `pwd = $("input[type=password]").val()`

​    `$.ajax({`

​      `type: 'get',`

​      `url: 'http://mine233.com/lsl/login',`

​      `data: {`

​        `account: uname,`

​        `password: pwd,`

​      `},`

​      `dataType: 'json',`

​      `success: function (res) {`

​        `console.log(111);`

​        `console.log(res.message);`

​        `// 存起指代用户，独一无二`

​        `localStorage.setItem('uid', JSON.parse(res.message).id)`

​        `loading5()`

​        `setTimeout(function () {`

​          `location.href = "./index.html"`

​        `}, 2000)`

​        `// 存入登录状态和账号，以便后需`

​        `localStorage.setItem("login", 'true')`

​        `localStorage.setItem('account', JSON.parse(res.message).account)`

​      `},`

​      `error: function (err) {`

​        `alert('用户名或者密码错误')`

​        `console.log(err);`

​      `}`

​    `})`

  `}`

  `return false`

`}`

### 注册

​	注册同样使用了loading中的插件用于提示用户注册成功的提示以及validate的前端认证。

​	当用户输入完注册信息提交之后，会进行后端验证，当发现用户已注册时，会提示已存在，前后端都成功数据才会存入后台数据库，方便于后续的登录操作。

​	注册主要代码：

`const isub = document.querySelector(".input-sub")`

  `const psd = document.querySelector('.input-psd')`

  `const cpsd = document.querySelector('.input-cpsd')`

  `console.log(cpsd);`

  `flag = true`

  `isub.onclick = function() {`

​    `if(psd.value != cpsd.value) {`

​      `cpsd.value = " "`

​      `cpsd.setAttribute("data-missing", "密码不一致")`

​      `flag = false`

​      `console.log(111);`

​    `}`

​    `flag = true`

​    `let result = Validate.start(".mi-form")`

​    `if(result && flag) {`

​      `// 前端验证通过进入后端验证`

​      `uname = $('input[type=text]').val()`

​      `pw = $('input[type=password]').val()`

​      `email = $('input[type=email]').val()`



​      `console.log(uname,pw);`

​      `$.ajax({`

​        `type : 'get',`

​        `url: 'http://mine233.com/lsl/register',`

​        `data : {`

​          `account : uname,`

​          `password: pw,`

​          `email:email`

​        `},`

​        `dataType : 'json',`

​        `success: function (res) {`

​          `console.log(res);`

​          `loading5()`

​          `setTimeout(function() {`

​            `location.href = "./login2.html"`

​          `},1000)`

​        `},`

​        `error: function(err) {`

​          `alert('用户名已存在')`

​          `console.log(err);`

​        `}`

​      `})`

​    `}`

  `}`

### 首页

​	首页主要是对一些商品的分类展示（主要使用了弹性盒布局，动态渲染），主要效果有轮播效果（swiper），右侧边固定栏，左侧楼层效果，搜索框，商品快速浏览项，选项卡效果等

渲染主要代码：

         <script type="type/html" id="tpl">
                            {{ each data item}}
                        <a href="./goods-details.html?pid={{item.id}}" >
                            <li class="item">
                                <img src="{{item.img[0]}}" alt="">
                                <h3 class="item-name">{{item.pName}}</h3>
                                <p class="item-info">120Hz高帧率流速屏</p>
                                <p class="item-price">
                                    <span class="present-price">{{ item.pPrice}}元</span>
                                    <span class="primary-price">8899元</span>
                                </p>
                            </li>
                        </a>
                        {{/each}}
           </script>



### 商品详情页

​	详情页是通过调用接口外加模板引擎渲染出来的，当点击首页的商品之后，会跳到详情页，动态渲染出相对应的数据信息。

​	主要效果：原生js轮播图，吸顶效果，侧边导航。

​	加入购物车和喜欢操作都是通过layui插件进行提示操作，增强用户的体验感。

​	请求数据主要代码：

`const hid = location.search.slice(5).trim();//获取商品的编号`

  `console.log(hid);`

  `$.ajax({`

​    `url: 'http://mine233.com/lsl/findgoods',`

​    `type: 'get',`

​    `getType: 'json',`

​    `data: {`

​      `pid: hid`

​    `},`

​    `success: function (result) {`

​      `console.log(result);`

​      `const da = JSON.parse(result.message);`

​      `console.log(da);`

​      `let arr = da.img.split(',');`

​      `console.log(arr);`

​      `let htmlStr = template('tpl', {`

​        `da, img_arr: arr`

​      `});`

​      `$('.product-box').html(htmlStr);`

​      `// 分两部分渲染`

​      `htmlStr = template('tpl1', {`

​        `da, img_arr: arr`

​      `});`

​      `// 导航名称更改`

​      `$('.xi-product').html(htmlStr);`

`)}`



### 我的购物车

​	在详情页中，当用户对此商品加入购物车之后，购物车则会通过接口外加动态渲染，把此商品以相对应的样式置入购物车中，可以对商品进行数量的加减的操作、计算价格、从购物车中删除商品，这些操作都会在数据库中进行更改。

​	点击删除按钮，这用到了layui的插件，会出提示框，询问用户是否确定删除？删除成功也会提示。

​	往购物车中加入数据部分代码：

​	`// 加入购物车请求`

​      `var uid = localStorage.getItem("uid");// 指代用户`

​      `$(".putin").click(function (event) {`

​        `event.preventDefault();`

​        `$.ajax({`

​          `url: 'http://mine233.com/lsl/addcart',`

​          `type: 'get',`

​          `dataType: 'json',`

​          `data: {`

​            `uid: uid,`

​            `pid: hid`

​          `},`

​          `success: function (res) {`

​            `console.log(res);`

​          `},`

​          `error: function (err) {`

​            `console.log(err);`

​          `}`

​        `})`

​        `layer.msg('已加入到购物车');`

​      `})`

### 我的收藏

​	当用户在详情页中点击喜欢，也是通过接口，把对应的数据动态渲染进去了，同样如果点击删除按钮，这用到了layui的插件，会出提示框，询问用户是否确定删除？删除成功也会提示。



## 页面截图

[![4RtzRS.png](https://z3.ax1x.com/2021/09/27/4RtzRS.png)](https://imgtu.com/i/4RtzRS)

[![4R8il9.png](https://z3.ax1x.com/2021/09/27/4R8il9.png)](https://imgtu.com/i/4R8il9)



[![4R8PSJ.jpg](https://z3.ax1x.com/2021/09/27/4R8PSJ.jpg)](https://imgtu.com/i/4R8PSJ)



[![4R8Vw6.png](https://z3.ax1x.com/2021/09/27/4R8Vw6.png)](https://imgtu.com/i/4R8Vw6)



[![4R8kO1.png](https://z3.ax1x.com/2021/09/27/4R8kO1.png)](https://imgtu.com/i/4R8kO1)

[![4R8FyR.png](https://z3.ax1x.com/2021/09/27/4R8FyR.png)](https://imgtu.com/i/4R8FyR)

