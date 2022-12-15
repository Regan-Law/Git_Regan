def gethasspaceText():
    txt = open("D:\\Regan\\Desktop\\Python\\hamlet.txt", "r").read()
    txt = txt.lower()
    for ch in '!"#$%&*()+,-./:;<=>?@[\\]^_`{|}~\'':
        txt = txt.replace(ch, " ")
    return txt

def getnospaceText():
    txt = open("D:\\Regan\\Desktop\\Python\\hamlet.txt", "r").read()
    txt = txt.lower()
    for ch in '!"#$%&*()+,-./:;<=>?@[\\]^_`{|}~\'\n ':
        txt = txt.replace(ch, "")
    return txt

hamletTxt = gethasspaceText()
words = hamletTxt.split()
counts = {}
lengths = {}
for word in words:
    counts[len(word)] = counts.get(len(word), 0) + 1
items = list(counts.items())
items.sort(key=lambda x: x[1], reverse=True)
print("按照频率从高到低统计单词长度的分布为：")
for i in range(len(items)):
    word, count = items[i]
    print("{}:{}".format(word, count))

hamletTxt = getnospaceText()
counts = {}
for word in hamletTxt:
    counts[word] = counts.get(word, 0) + 1
items = list(counts.items())
items.sort(key=lambda x: x[1], reverse=True)
print("按照频率从高到低统计英文26字母出现的频率分布为:")
for i in range(len(items)):
    word, count = items[i]
    print("{}:{}".format(word, count))
print("童言", 2015301332, "软工")