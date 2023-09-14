str = 'python'
var = [i for i in str]
print(var)

list = [i for i in range(20) if i % 2 == 0]
print(list)

list = []
for i in range(20):
    if i % 2 == 0:
        list.append(i)
print(list)

dict = {'py': 'python', 'sel': 'selenium', 'at': 'autotest'}
dict_conversion = {v: k for k, v in dict.items()}
print(dict_conversion)

var = {x ** 2 for x in range(1, 10)}
print(var)