def repeat(lis):
    if len(set(lis))<len(lis):
        return True
    else:
        return False
p = eval(input('请输入一个列表：'))
print(repeat(p))
print('原来输入的列表{}'.format(p))
print('童言', 2015301332, '软工')