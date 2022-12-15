fo = open("dict.txt", "r")
words = {}
count = 0
for line in fo.readlines():
    s = str(line).split()
    words[s[0]] = s[1]
    count += 1
fo.close()
while True:
    option = eval(input("********************"
                        "\n1  添加\n2  查询\n3  退出\n"
                        "********************"))

    if option == 1:
        english = input("请输入英文单词: ")
        if english in words:
            print("该单词已经添加到词典里!")
            option_1 = eval(input("是否继续为{}添加多重释义,1为继续添加，2为输入其他选项，3为退出。".format(english)))
            if option_1 == 1:
                chinese = input("请输入中文释义：")
                words[english] = words[english] + "," + chinese
            elif option_1 == 2:
                continue
            elif option_1 == 3:
                break
            else:
                print("输入有误!")
                continue
        else:
            chinese = input("请输入中文释义: ")
            words[english] = chinese
            count += 1
    elif option == 2:
        english = input("请输入你要查询的英文单词：")
        if english not in words:
            print("字典库中未找到这个单词!")
            continue
        else:
            print("{}的中文释义是:{}".format(english, words[english]))
    elif option == 3:
        break
    else:
        print("输入有误")
        break
items = list(words.items())
fo = open("dict.txt", "w")
for i in range(count):
    english, chinese = items[i]
    s = english + " " + chinese + '\n'
    fo.write(s)

fo.close()
print('童言', 2015301332, '软工')