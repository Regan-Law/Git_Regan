p=1
for i in range(365):
    temp=i%11
    if(temp<3):
        p=p
    elif(temp<8):
        p=p*1.01
    else:
        p=p
print("如此学习365天后能力值是{:.4f}".format(p))
print('童言', 2015301332, '软工')
#p=1
#for i in range(365):
#    temp=i%16
#    if(3<temp<8):
#        p=p*1.01
#    elif(10<temp<15):
#        p=p*1.01
#    else:
#        p=p
#print("如此学习365天后能力值是{:.4f}".format(p))
#print('童言', 2015301332, '软工')