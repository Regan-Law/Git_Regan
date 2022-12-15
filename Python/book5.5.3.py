def isNum(str):
    try:
        str=eval(str)
        if type(str)==int or type(str)==float or type(str)==complex:
            return True
    except NameError:
        return False
a=input("输入一个字符串")
print(isNum(a))
print('童言', 2015301332, '软工')