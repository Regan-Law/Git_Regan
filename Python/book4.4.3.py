x=eval(input('请输入一个整数：'))
y=eval(input('请输入一个整数：'))
z=x*y
if x<y:
    x,y=y,x
n=x%y
while n!=0:
    x,y=y,n
    n=x%y
z=z/y
print('它们的的最大公约数为{}，最小公倍数为{}'.format(y,z))
print('童言',2015301332,'软工')