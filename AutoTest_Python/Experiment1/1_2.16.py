def func(a, b):
    try:
        return a / b
    except ZeroDivisionError as e:
        return e


print(func(3, 2))
print(func(3, 0))


def func(a, b):
    try:
        print(a / b)
    except:
        print('error')
    else:
        print(' try...else')


func(2, 1)
func(2, 0)


def func(a, b):
    try:
        print(a / b)
    except:
        print('error')
    finally:
        print('try...else')


func(2, 1)
func(2, 0)