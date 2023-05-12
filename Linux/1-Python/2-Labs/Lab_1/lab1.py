
lis=[1,2,0]
list=['a','b','c','d','e','f']
choice=9
while(choice!='0'):
    print("Enter 1 for partition() function:")
    print("Enter 2 for startswith() function:")
    print("Enter 0 to exit: ")
    str="omaressam"
    choice=input()
    if (choice == '1'):
        print("partition():Returns a tuple where the string is parted into three parts")
        print(f'''here is an example: 
        
        str="omaressam"
        
        str.partition("m")={str.partition("m")}
        
        /*******************************************************************************************************/''')
        
    elif (choice == '2'):
            print("startswith():Returns true if the string starts with the specified value")
            print(f'''here is an example: 
            
            str="omaressam"
            
            str.startswith("o")={str.startswith("o")}
            str.startswith("m")={str.startswith("m")}
            
        /*******************************************************************************************************/''')