#include"Std_types.h"
#include<stdio.h>
#include<stdlib.h>
#include"queue_based_array.h"

u8 DataArry[Max_Size] = {0};
s8 front = -1 ;     //Anwer -> index number 0 
s8 rear= -1 ; 
void EnQueue(u8 data)
{
	if (IsFul()==Fully)
	{
		return ; 
	}
	else //if (front!=Max_Size)
	{
		if(front==-1&&rear==-1){
			front=rear=0;
		}
		else
		{
		 rear++;
		}
		DataArry[rear] = data ;
		//tail=front+1;
		
		
	}
}


u8 DeQueue(void)
{
	if (IsEmpty()==Empty)
	{
		printf("empty queue\n") ;
	}
	else 
	{
		
		return DataArry[front--];
	}
}

u8 IsEmpty(void) 
{
	 if (front == rear)
	 {
		 
		 return Empty ;
	 }
	 else 
	 {
		 return NotEmpty ; 
	 }
}


u8 IsFul(void) 
{
	//if (front == (Max_Size -1
	//if (front == (Max_Size-1 ))
	
	if (rear==Max_Size -1)
	{
		return Fully ; 
	}
	else 
	{
		return NotFully ; 
	}
}

u8* display ()
{
	return DataArry;

}
