''' ***************************task2 using Dict***************************************'''

# info={
    # "ClientName":["Omar","Ali","Said"],
    # "PassKey":[4567,1234,2222],
    # "Cash":[10000,25000,30000]
# }
# print (info)
# Pass=int(input("enter your Pass Key:"))
# if(Pass==4567):
 
    # index = 0
    # print('Welcome back Mr.',info["ClientName"][index])
    # print("Your account has:",info["Cash"][index])
    
# elif(Pass==1234):
    # index = 1
    # print('Welcome back Mr.',info["ClientName"][index])
    # print("Your account has:",info["Cash"][index])
    
# elif(Pass==2222):
    # index = 2
    # print('Welcome back Mr.',info["ClientName"][index])
    # print("Your account has:",info["Cash"][index])
    
''' ***************************task2 using List***************************************'''
# Info_List=[["Omar",4567,10000],["Ali",1234,25000],["Said",2222,30000]]
#print(Info_List)
# def Money_Take(Info_List):   
    # MoneyNeeded=int(input("Enter quantity you need:"))
    # if(MoneyNeeded<=Info_List[index][2]):
        # Info_List[index][2]=Info_List[index][2]-MoneyNeeded

# Pass=int(input("enter your Pass Key:"))
# if(Pass==4567):
 
    # index = 0
    # print('Welcome back Mr.',Info_List[index][0])
    # print("Your account has:",Info_List[index][2])
    # Money_Take(Info_List)
    # print("Your account has:",Info_List[index][2])
# elif(Pass==1234):
    # index = 1
    # print('Welcome back Mr.',Info_List[index][0])
    # print("Your account has:",Info_List[index][2])
    # Money_Take(Info_List)
    # print("Your account has:",Info_List[index][2])
    
# elif(Pass==2222):
    # index = 2
    # print('Welcome back Mr.',Info_List[index][0])
    # print("Your account has:",Info_List[index][2])
    # Money_Take(Info_List)
    # print("Your account has:",Info_List[index][2])
''' ***************************task2 using Range***************************************'''
IDInfo=range(0000,10000,1)#10000 clients with 1000 diff IDs available
PassInfo=range(000,1000,1)#10000 4-digit PassKey
choice=0
while(choice!='e'):
    choice=input("1-enter e to exit\n 2-enter s to start")
    if (choice=='s'):
        ID=int(input("Enter your ID"))
        flag=0
        for n in IDInfo:
            if (flag==1):
                break
            elif (ID==n):
                Pass=int(input("enter your PassKey:"))
                for n in PassInfo:
                    if(Pass==n):
                        flag=1
                        print("Welcome User!")
                        break
                    elif (n==999):
                       print("Wrong PassKey,Try again")
                       flag=1
                    else:
                        continue
            elif (n==9999):
                print("Wrong ID,Try again")
            else:
                continue
                
                
                
        


