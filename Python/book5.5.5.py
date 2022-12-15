def isPrime(x):     
    try:
        while x>1:
            if x==2:
                return True
            else:
                for i in range(2,x+1):
                    if x%i==0:
                        return False
                    else:
                        return True
    except:
        print("输入的数值错误，请重新输入！")
        x=int(input("请输入一个数值："))
a=int(input("请输入一个数值："))
print("%s" % isPrime(int(a)))  
print('童言', 2015301332, '软工')