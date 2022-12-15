from random import randint

def func():
    n = int(input("请输入模拟次数（整数）："))
    count1 = count2 = 0
    for i in range(n):
        car = randint(1, 3)
        x = randint(1, 3)
        if x == car:
            count1 += 1
        else:
            count2 += 1
    print(f"坚持选择的胜率：{count1/n:.2%}")
    print(f"改变选择的胜率：{count2/n:.2%}")

func()
print('童言', 2015301332, '软工')
