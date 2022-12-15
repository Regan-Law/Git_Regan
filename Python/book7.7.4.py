import json

fr = open("D:\\Regan\\Desktop\\Python\\price2016.csv", 'r')
ls = []
for line in fr:
    line = line.replace("\"", "")
    line = line.replace(" ", "")
    line = line.replace("\n", "")
    line = line.replace(" ", "")
    ls.append(line.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)"))
fr.close
fw = open('cityout.json', 'w')
for i in range(1, len(ls)):
    ls[i] = dict(zip(ls[0], ls[i]))
json.dump(ls[1:], fw, sort_keys=True, indent=4, ensure_ascii=False)
fw.close()
print('转换完成')
print('童言', 2015301332, '软工')