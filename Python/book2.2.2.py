type = input("请输入需要兑换的币种：")
Money = eval(input("请输入需要兑换的金额："))
if type in ['人民币']:
    C = int(Money/6)
    print("转换后的金额是{:d}美元".format(C))
elif type in ['美元']:
    F = int(Money*6)
    print("转换后的金额是{:d}人民币".format(F))
else:
    print("输入格式错误")
print('童言', 2015301332, '软工')
