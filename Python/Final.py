import matplotlib.pyplot as plt
import numpy as np

names = []  #创建列表存储选手姓名
finalscores = {}  #创建字典存储选手的最终得分
while True:
    try:
        jury_num = int(input("请输入评委人数："))
        assert jury_num > 4  #判断评委人数是否至少为5人
        assert isinstance(jury_num, int)  #判断评委人数是否为整数
        break
    except:
        print("评委人数不得少于5人且必须为整数")

while True:
    try:
        player_num = int(input("请输入选手人数："))
        assert player_num > 1  #判断选手人数是否至少为2人
        assert isinstance(player_num, int)  #判断选手人数是否为整数
        break
    except:
        print("选手人数不得少于5人且必须为整数")

def getscores(name):
    scores = []  #创建列表用来存储评委的打分
    for i in range(jury_num):  #循环用来保证用户必须输入0到100之间的数字
        while True:
            try:
                score = input("请输入第{0}个评委的分数：".format(i + 1))  #用i+1来替换占位符{0},i+1是因为计算机从0计数
                score = float(score)  #把字符串转换为实数,分数是实数
                assert 0 <= score <= 100  #assert断言，如果score不在范围内则抛出异常
                scores.append(score)  #符合要求则添加到列表中
                break  #如果数据合法，跳出while循环，继续输入下一个评委的得分
            except:
                print("分数错误")
    finalscores[name] = count_scores(scores)  #调用计算函数并将其存入字典

def count_scores(scores):  #计算选手最终得分
    scores.remove(max(scores))
    scores.remove(min(scores))  #去掉一个最高分和一个最低分
    return round(sum(scores) / len(scores), 2)  #round函数返回四舍五入2位的值

def main():
    for i in range(player_num):
        while True:
            try:
                name = input("请输入第{0}位选手的姓名：".format(i + 1))  #依次输入选手姓名
                assert isinstance(name, str)
                names.append(name)
                getscores(names[i])  #录入选手分数
                break  #如果数据合法，跳出while循环，继续输入下一个选手的姓名
            except:
                print("请重新输入")
    for i in range(player_num):
        print("{0}选手的最后得分是：{1}".format(names[i], finalscores[names[i]]))
final_list = []  #创建列表存储选手最终成绩
plt.rcParams['font.sans-serif'] = ['SimHei']  #用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  #用来正常显示负号
for i in range(player_num):
    final_list.append(finalscores[names[i]])
p = plt.bar(names, final_list)
plt.grid(True, axis="y", ls=":")
plt.bar_label(p, label_type="edge")
plt.title("决赛选手最终成绩")
plt.xlabel("选手姓名")
plt.ylabel("选手成绩")
plt.show()
print('童言', 2015301332, '软工')