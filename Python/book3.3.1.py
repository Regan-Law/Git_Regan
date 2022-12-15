weight=input("输入你当前的体重(kg)：")
addweight=int(weight)
for i in range(10):
    addweight+=0.5
    print("未来",i+1,"年后的你在地球上的体重为：{:.3f}kg".format(addweight))
    lunarweight=addweight*0.165
    print("未来",i+1,"年后的你在月球上的体重为：{:.3f}kg".format(lunarweight))
print('童言', 2015301332, '软工')