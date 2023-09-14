gen = (x for x in range(5))
print(type(gen))

gen = (x for x in range(5))
print(next(gen))
print(next(gen))
print(next(gen))
print(next(gen))
print(next(gen))

gen = (x for x in range(5))
for i in gen:
    print(i)


def sequence(numb):
    for i in range(numb):
        i = i * 3
        yield i


g = sequence(3)
print(next(g))
print(next(g))
print(next(g))


def sequence(numb):
    for i in range(numb):
        i = i * 3
        temp = yield i
        print(temp)


g = sequence(5)
print(next(g))
print(next(g))
print(g.send("send发送参数"))
print(g.send(None))