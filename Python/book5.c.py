candidate=[2,3,5]
list=[]
result=[]
def search(candidates,target,list):
   if (sum(list)==target):
      list.sort()
      if list not in result:
         result.append(list)
      return
   if (sum(list)>target):
      return
   for i in range(len(candidate)):
      search(candidates,target,list+[candidates[i]])
search(candidate,8,list)
print(result)
print('童言', 2015301332, '软工')