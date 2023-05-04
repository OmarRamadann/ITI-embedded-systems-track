#include<stdlib.h>
#include"Std_types.h"
typedef struct node
{
u8 tail;
u8 head;
u8 size;
u8 capacity;
u8 data;
struct node*next;
struct node*prev;
}queue_element;

element* head=null; //create head pointing to dummy then pointing to first element 
element* tail=null

queue_element* create_element(u8 capacity)
{
queue_element* user=(queue_element*)malloc (sizeof(queue_element));
user->head=0;
user->tail=0;
user->size=0;
user->capacity=size-1;
return user;

}

//add value

void add_value(u8 data){
//case empty queue
queue_element*user=create_element();
user->data=value;
user->next=null;
//the created element is first element

if (head==null)
	{
		head=user;//make head point to first element 
		tail=user;
		head->next=null;
		tail->next=null;
		
	}
	else
	{
	
	tail->next=user;
	tail=user;
	user->next=null
	}
}


void delete ()
{
if (IsEmpty()==Empty)
	{
		printf("empty queue\n") ;
	}
	else 
	{
	queue_element* temp =head;
	head=head->next;
	free(temp);

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