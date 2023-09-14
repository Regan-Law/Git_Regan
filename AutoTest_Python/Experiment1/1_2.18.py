print('selenium', 'web', 'autotest', sep='\n-----------\n')

a = 1
b = 2
a, b = b, a
print(a, b)

list = [1, 4, 45, 23, 54]
reversed_list = list[::-1]

print(reversed_list)

a = 4
print(4 == a < 6)


def func(y):
    x = -1
    return x if (y > 99) else 1


list1 = [1, 2, 3, 4]
list2 = ['py', 'sel', 'web', 'at']
for i, j in zip(list1, list2):
    print(str(i) + ': ' + j)

listl = ['py', 'sel', 'at']
list2 = ['python', 'selenium', 'autotest']
dic = dict(zip(listl, list2))
print(dic)

l = [2] * 5
print(l)

l = ['py', 'sel', 'at', 'py', 'py', 'at']
new_l = list(set(l))
print(new_l)

seq = ['py', 'sel', 'web', 'at']
for index, item in enumerate(seq):
    print(index, item)

list(enumerate(seq, start=l))

list(map(lambda x, y: x * y, [1, 3, 7], [13, 5, 21]))

print(any([0, 1]))  # True
print(any(['', 0, False]))  # False
print(any([]))  # 空列表返回False
print(any(()))  # 空元组,返回False
print(any({}))  # 空字典,返回False

print(all([1, 2, 3]))  # True
print(all([0, 1, 2]))  # 元素0为False,返回结果为False
print(all(['a', 'b', '']))  # 元素空字符串为False,返回结果为False
print(all(()))  # 空元组,返回True
print(all([]))  # 空列表,返回 True
print(all({})) #空字典，返回 True

s=" hello selenium "
s.strip()
s.lstrip()
s.rstrip()

import os
realpath=os.path.split(os.path.realpath((__file__))[0]