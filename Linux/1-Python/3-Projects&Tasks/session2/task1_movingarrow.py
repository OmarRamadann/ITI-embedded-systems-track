from os import system
from time import sleep
no_stars=0
star="*"
space=" "

#Arrow_Right
def Point_right():
    _ = system('cls')
    print(4*"\n")
    for x in range(6):
        print(10*space+5*space+x*star)
        if(x==5):
            
           print(10*space+3*x*star) # print(5*star+x*star+5*star)
           for x in range(5,0,-1):
                print(10*space+5*space+x*star)
                # sleep(1)
              
           
#Arrow_Left
def Point_left():
    _ = system('cls')
    print(4*"\n")
    inc=5
    for x in range(6):
        print(10*space+(5+inc)*space+x*star)
        inc-=1
        if(x==5):
           print(10*space+3*x*star) # print(5*star+x*star+5*star)
           inc=0
           for x in range(5,0,-1):
                print(10*space+(5+inc)*space+x*star)
                inc+=1
                       
# Arrow_Down
def Point_down():
    _ = system('cls')
    print(4*"\n")
    for x in range(5):
        inc=0
        print(10*space+5*space+star)
    for x in range(11,0,-2):
        # if(x==11):
        print((10+inc)*space+x*star)
        # else:
            # print((10+inc)*space++x*star)
        inc+=1
        if(x==3):
            for x in range(5):
                print(10*space+5*space+star)
   
#Arrow_Up
def Point_up():
    _ = system('cls')
    print(4*"\n")
    for x in range(5):
        inc=4
        print(10*space+5*space+star)
    for x in range(3,12,2):
        # if(x==3):
        print((10+inc)*space+x*star)
        # else:
            # print((10+inc)*space++x*star)
        inc-=1
        if(x==11):
            for x in range(5):
                print(10*space+5*space+star)
  
  
choice=0
while(choice!='e'):
    print(4*"\n")
    print("press d to point right")
    print("press a to point left")
    print("press w to point up")
    print("press s to point down")
    print("press r to rotate Clkwise")
    print("press q to rotate Anti Clkwise")
    print("press e to exit")
    choice=input("your Input is: ")
    if (choice =='d'):
        Point_right()
        # print("/***********************************************************************************************/")
    elif choice=='a':
        Point_left()
        # print("/***********************************************************************************************/")
    elif choice=='w':
        Point_up()
        # print("/***********************************************************************************************/")
    elif choice=='s':
        Point_down()
        # print("/***********************************************************************************************/")
    elif choice=='r':
        brk=0
        # while(brk!='e'):
        while(1):
            # print("enter e to break")
            # brk=input()
            Point_right()
            sleep(0.5)
            Point_down()
            sleep(0.5)
            Point_left()
            sleep(0.5)
            Point_up()
            sleep(0.5)
            
    elif choice=='q':
        brk=0
        while(1):
            Point_left()
            sleep(0.5)
            Point_down()
            sleep(0.5)
            Point_right()
            sleep(0.5)
            Point_up()
            sleep(0.5)
        
        
    









