import random
for i in range(10):
    print(random.randint(0,100))
print(random.randrange(0,100,2))
s='abcdefghij'
for i in range(4):
    print(s[random.randint(0,len(s)-1)])
print(['apple','pear','peach','orange'][random.randint(0,3)])
print('童言',2015301332,'软工')