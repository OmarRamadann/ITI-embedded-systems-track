import math
scientList={"pow","sqrt","sin","cos","tan","modulus","log"}
choice=4
while(choice!='e'):
    print('''select Calculator mode:
    1.Standard     2.Scientific  
    press e to exit''')
    choice=(input("your choice is:"))
    if (choice=='1'):
        op1=int(input("enter first operand:"))
        op=input("enter operation:")
        if(op=='+'):
            op2=int(input("enter secon operand:"))
            print("Result of addition is:{}".format(op1+op2))
        elif(op=='-'):
            op2=int(input("enter secon operand:"))
            print("Result of subtraction is:{}".format(op1-op2))
        elif(op=='*'):
            op2=int(input("enter secon operand:"))
            print("Result of multipliction is:{}".format(op1*op2))
        elif(op=='-'):
            op2=int(input("enter secon operand:"))
            print("Result of division is:{}".format(op1/op2))
    elif(choice=='2'):
        print(scientList)
        op1=int(input("enter first operand:"))
        op=input("enter operation:")
        if(op=='pow'):
            op2=int(input("enter power value:"))
            print("Result of squaring is:{}".format(op1**ob2))
        elif(op=='sqrt'):
            # op2=int(input("enter secon operand:"))
            print("Result of rooting is:{}".format(math.sqrt(op1)))
        elif(op=='sin'):
            # op2=int(input("enter secon operand:"))
            print("Result of sin is:{}".format(math.sin(op1)))
        elif(op=='cos'):
            # op2=int(input("enter secon operand:"))
            print("Result of cos is:{}".format(math.cos(op1)))
        elif(op=='tan'):
            # op2=int(input("enter secon operand:"))
            print("Result of tan is:{}".format(math.tan(op1)))
        elif(op=='modulus'):
            # op2=int(input("enter secon operand:"))
            print("Result of modulus is:{}".format(math.fabs(op1)))
        elif(op=='log'):
            # op2=int(input("enter secon operand:"))
            print("Result of log is:{}".format(math.log(op1)))
        else:
            print("invalid entry,Try again")
