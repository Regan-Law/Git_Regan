import jieba

txt = open('D:\\Regan\\Desktop\\Python\\白鹿原.txt', 'r', encoding="UTF-8").read()
words = jieba.lcut(txt)
counts = {}
for word in words:
    if len(word) == 1:
        continue
    else:
        counts[word] = counts.get(word, 0) + 1

wordlst = list(counts.items())
wordlst.sort(key=lambda x: x[1], reverse=True)
maxfreq = wordlst[0][1]
maxfreqwords = []
for i in wordlst:
    if i[1] == maxfreq:
        maxfreqwords.append(i)
    else:
        break
maxfreqwords.sort(key=lambda x: x[0], reverse=True)
print(maxfreqwords[0][0])
print("童言", 2015301332, "软工")