p=1
for i in range(365):
    temp=i%7
    if(temp<3):
        p=p
    else:
        p=p*1.01
print("连续学习365天后能力值是{:.4f}".format(p))
print('童言', 2015301332, '软工')