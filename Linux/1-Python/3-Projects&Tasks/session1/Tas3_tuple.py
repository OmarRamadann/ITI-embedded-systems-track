GroceryInfo=("banana",1.5,"oranges",1,"Berries",2,"cucumber",2.5)
print("Available types are:",GroceryInfo)
Type=input("Enter your choice:")
Weight=int(input("enter its weight:" ))
index=-1

for n in GroceryInfo:
    index+=1
    if (n==Type):
        print ('the price is:' ,GroceryInfo[index+1]*Weight)
        break
    elif(n==GroceryInfo[-1]):
        print("this type is not available")
    else:
        continue