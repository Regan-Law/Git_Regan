n=input("请输入一行字符:")
a=b=c=d=0
for i in n:
    if ord('a')<=ord(i)<=ord('z') or ord('A')<=ord(i)<=ord('Z'):
        a=a+1
    elif ord('0')<=ord(i)<=ord('9'):
        b=b+1
    elif ord(i)==ord(' '):
        c=c+1
    else:
        d=d+1
print("这一行字符中字母的数量是：{},数字的数量是：{},空格数量是：{},其他字符的数量是：{}。".format(a,b,c,d))
print('童言',2015301332,'软工')