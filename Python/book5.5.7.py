def hanoi(n,x,y,z):
    if n == 1:
        print(x,'-->',z)
    else:
        hanoi(n-1,x,z,y)
        print(x,'-->',z)
        hanoi(n-1,y,x,z)
n = int(input('请输入汉诺塔层数：'))
hanoi(n,'1','2','3')
print('童言', 2015301332, '软工')