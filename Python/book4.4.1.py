import random
Setnumber = random.randint(0,10)
try:
    Guessnumber=int(input("请输入猜测的数："))
    int(Guessnumber)
    N=1
    while(Guessnumber<Setnumber or Guessnumber>Setnumber):
        N=N+1
        if Guessnumber>Setnumber:
            print("遗憾，太大了")
        elif Guessnumber<Setnumber:
            print("遗憾，太小了")
        Guessnumber=int(input("请重新输入猜测的数："))
    print("预测{}次，你猜中了".format(N))
except:
    print("输入不合法，请重新输入:")
print('童言', 2015301332, '软工')