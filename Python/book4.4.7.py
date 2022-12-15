TempStr = input("请输入带有符号的温度值：")
if TempStr[-1] in ['F','f']:
    try:
        C = (eval(TempStr[0:-1])-32)/1.8
        print("转换后的温度是{:.2f}C".format(C))
    except:
        print("您输入的温度格式有误！")
elif TempStr[-1] in ['C','c']:
    try:
        F = 1.8*(eval(TempStr[0:-1]))+32
        print("转换后的温度是{:.2f}F".format(F))
    except:
        print("您输入的温度格式有误！")
else:
    print("您输入的温度格式有误！")
print('童言',2015301332,'软工')