txt = input("请输入一段文本：")
txt = txt.lower()
count= {}        
for word in txt:
    if word==" ":
        continue
    else:
        count[word] = count.get(word,0) + 1   
items = list(count.items())               
items.sort(key = lambda x:x[1],reverse = True)
for i in range(len(items)):                  
    word,count = items[i]
    print("{:<10}{:<5}".format(word,count))
print('童言', 2015301332, '软工')