for i in range(21):
    a,b="＋","－"*4
    c,d="丨"," "*8
    if(i==0 or i==5 or i==10 or i==15 or i==20):    
        print("{}{}{}{}{}{}{}{}{}".format(a,b,a,b,a,b,a,b,a))    
    else:
        print("{}{}{}{}{}{}{}{}{}".format(c,d,c,d,c,d,c,d,c))
print('童言', 2015301332, '软工')