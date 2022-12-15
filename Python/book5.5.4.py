def multi():
    try:
        str=input("输入要计算的参数，用空格隔开")
        c=1
        for item in str.split():
            c=c*int(item)
        print(c)
    except:
        print("error")
multi()
print('童言', 2015301332, '软工')