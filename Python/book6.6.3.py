ls = eval(input("请输入一个列表："))
if ls != list(set(ls)):
    print(True)
else:
    print(False)
print('童言', 2015301332, '软工')