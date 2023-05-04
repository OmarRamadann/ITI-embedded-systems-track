#include<stdio.h>
#include<stdlib.h>
#include"Std_types.h"
#include "queue_based_array.h"
void main(){
u16 choice;
u8 value1,delete;
u8 counter=0;
u8 *arr;
do
{
	printf("to add a value enter 0\n");
	printf("to display the queue  enter 1\n");
	printf("to delete a value enter 2\n");
	printf("to exit enter 3\n");
scanf("%d",&choice);
	printf("your choice: %d\n",choice);
	switch (choice)
	{
		default:
		printf("invalid choice,try again\n");
		break;
		case 0:
		printf("please enter  value: \n");
		scanf("%d",&value1);
		EnQueue(value1);
		counter++;
		printf("value added, thank you\n");
		break;
		case 1:
		arr=display();
		for (int i=0;i<counter;i++)
{
	
	printf("value %d is : %d\n",i,arr[i]);
}	
		break;
		case 2:
		delete=DeQueue();
		counter--;
		break;
		case 3:
		printf("Thank you\n Good Bye\n");
		break;
	}
}while(choice!=3);

}