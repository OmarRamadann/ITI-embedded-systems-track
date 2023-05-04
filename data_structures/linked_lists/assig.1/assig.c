#include<stdio.h>
#include<stdlib.h>
#include"std_data_types.h"
#include"single_linked_list.h"
void main(){
	u16 choice;
	u8 value1,delete,search,index;
	u8 counter=0;
	u16* arr;
	u16 value2;
do
{
	printf("to add a node enter 0\n");
	//printf("size is: %d",sizeof(u16));
	printf("to print the linked list  enter 1\n");
	printf("to exit enter 2\n");
	printf("to delete a value enter 3\n");
	printf("to search for a value enter 4\n");
	printf("to add a  value at certain position enter 5\n");
	scanf("%d",&choice);
	printf("your choice: %d\n",choice);
	switch (choice)
	{
		default:
		printf("invalid choice,try again\n");
		break;
		case 0:
		printf("please enter node value: \n");
		scanf("%d",&value1);
		add_element(value1);
		counter++;
		printf("node added, thank you\n");
		break;
		case 1:
		arr=print_list();
		for (int i=0;i<counter;i++){
			printf("node number %d = %d\n",i,arr[i]);
		}
		break;
		case 2:
		printf("Thank you\n Good Bye\n");
		break;
		case 3:
		printf("enter the value to be deleted\n");
		scanf("%d",&delete);
		delete_list(delete);
		counter--;
		break;
		case 4:
		printf("enter value to search for : \n");
		scanf("%d",&search);
		element* ptr =search_element(search);
		printf("the address of the node is: %d\n",ptr);
		printf("the data of the node is: %d\n",ptr->data);
		//printf("the search value is in node :%d \n",search_counter);
		break;
		case 5:
		printf("enter value to be added\n");
		scanf("%d",&value2);//must scan more than u8
							//therefore define u1 or u32 value2.
		printf("enter index to add the node at: \n");
		scanf("%d",&index);
		add_node_middle( value2, index);
		counter++;
		break;
		
		
	}
}while(choice!=2);
}