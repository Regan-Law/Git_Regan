height,weight=eval(input("请输入身高（米）和体重（公斤）[逗号隔开]："))
bmi=weight/pow(height,2)
print("BMI数值为：{:.2f}".format(bmi))
who,dom="",""
if bmi<18.5:
    who,dom="偏瘦","偏瘦"
elif 18.5<=bmi<=24:
    who,dom="正常","正常"
elif 24<=bmi<25:
    who,dom="正常","偏胖"
elif 25<=bmi<28:
    who,dom="偏胖","偏胖"
elif 28<=bmi<30:
    who,dom="偏胖","肥胖"
else:
    who,dom="肥胖","肥胖"
print("BMI指标为：国际'{0}',国内'{1}'".format(who,dom))
print('童言', 2015301332, '软工')
