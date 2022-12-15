import random
s = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
     "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
     "0","1","2","3","4","5","6","7","8","9"] 
for i in range(10):   
    for i in range(8):
        print (random.choice(s),end="")
    print("\n")
print('童言', 2015301332, '软工')