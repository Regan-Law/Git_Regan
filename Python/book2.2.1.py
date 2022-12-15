symbol = input("请输入温度的符号")
TempStr = eval(input("请输入温度值："))
if symbol in ['F', 'f']:
    C = int((TempStr-32)/1.8)
    print("转换后的温度是{:d}C".format(C))
elif symbol in ['C', 'c']:
    F = int(1.8*TempStr+32)
    print("转换后的温度是{:d}F".format(F))
else:
    print("输入格式错误")
print('童言', 2015301332, '软工')
