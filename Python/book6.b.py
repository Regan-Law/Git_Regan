try:
    d = {}
    a = input()
    b = eval(a)
    for k in b:
        d[b[k]] = k
    print(d)
except:
    print('输入错误')
print('童言', 2015301332, '软工')