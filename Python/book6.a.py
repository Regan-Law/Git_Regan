import jieba
s=input("请输入一串中文字符串：")
s1 = list(jieba.lcut(s))
print("".join(s1[::-1]))
print('童言', 2015301332, '软工')