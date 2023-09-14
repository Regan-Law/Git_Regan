class Animal:
    food = "粮食"

    def __init__(self, name):
        self.name = name

    def eat(self):
        print("%s正在吃%s" % (self.name, Animal.food))


cat = Animal("猫咪")
cat.eat()
print(cat.food)

cat = Animal("猫咪")
cat.food = "猫粮"
print(cat.food)

cat.do = "捉老鼠"
print(cat.do)
del cat.do
print(cat.do)


class Persion(object):
    def __init__(self):
        self.__name = "persion"

    def __eat(self):
        print("吃粮食")


xiao_ming = Persion()
print(xiao_ming.__name)

xiao_hua = Persion()
print(xiao_hua.__eat())


class Persion:
    def __init__(self):
        pass

    def eat(self):
        print("吃粮食")


class Student(Persion):
    pass


xiao_ming = Student()
xiao_ming.eat()


class Persion1:
    def __init__(self):
        pass

    def eat(self):
        print("吃粮食")


class Persion2:
    pass


class Student(Persion1, Persion2):
    pass


class Persion(object):
    def __init__(self):
        pass

    def eat(self):
        print("吃粮食")


class Youth(Persion):
    pass


class Student(Youth):
    pass


xiao_ming = Student()
xiao_ming.eat()


class Persion (object):
    def __init__(self):
        self.name ="persion"
    def eat (self):
        print ("吃粮食")
class Student(Persion):
    def __init__(self):
        super(Student, self).__init__()
        print(self.name)

        self.name = "student"
        print(self.name)

    def eat(self):
        print("吃有营养的粮食")

xiao_ming= Student()
xiao ming.eat()