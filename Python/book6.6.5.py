import random
def miss(num):
    flag=0
    for i in range(num):
        ls=[]
        for i in range(23):
            birthday=random.choice(range(365))
            ls.append(birthday)
        dount=set(ls)
        if len(dount)!=len(ls):
            flag+=1
    return flag/num
print("23个人当中至少有两人生日相同的概率为：{:.2f}%".format(miss(10000)*100))
print('童言', 2015301332, '软工')