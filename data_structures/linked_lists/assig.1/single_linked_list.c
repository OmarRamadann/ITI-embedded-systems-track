#include <stdio.h>
#include <stdlib.h>
#include "std_data_types.h"
#include"single_linked_list.h"

u8 counter=0;
u8 search_counter=0;

element* head=NULL; //create head pointing to dummy

//function that return adderss of a new element
element* create_element(){
	 counter++;
	return (element*)malloc(sizeof(element));
}




//function to add element from the end &link the created element with the head or the one behind
void add_element(u8 value)
{
	//1.call the create function
	element* user= create_element();
	//2. get data from user to put it in data section of struct
	//printf("enter data");
	//scanf("/d",&(user->data));
	user->data=value;
	//3.assign the next section in it to null
	user->next=NULL;
	
	/*linking*/
	//the created element is first element
	if (head==NULL)
	{
		head=user;//make head point to first element 
	}
	//the created not first element
	else{
		
		element* temp =head;//make temp goes to first element (the address of head)
		while(temp->next !=NULL){
			temp=temp->next;//take the address of next in this node
		}
		temp->next=user;//make the past  element -which the head pointing to -points to the created element 
	}
}




//function to search for data in an element
 element* search_element(u8 data){
	 element* temp2=head;
	 while(temp2->data!=data){
		 temp2=temp2->next;
		search_counter++;		 
		 if (temp2==NULL){
			 printf("data is not present");
			 return NULL;
		 }
	 }
	 
	 printf("search value is in node %d\n",search_counter+1);
	 search_counter=0;
	 return temp2;	 
 }
 
 
 //function to delete a certain node
//delete the data inside node first then free the node 
	void delete_list (u8 data){
	 element*temp3=search_element(data);//element needed to be deleted
	 element*temp4=head;
	 if (temp3!=NULL)
	 {
	 //case the element is the first and only element
	 if (temp3==head && temp3->next==NULL){
		 head=NULL;
	 }
	//case the element is the last element
	 else if (temp3->next==NULL){
		 while (temp4->next!=temp3){//to get the place before the place i am at.
				temp4=temp4->next;	//while the next in temp4 no pointing to the
		 }						//address of temp3 searched for continue.
		 temp4->next=NULL;		//make this element the last.
	 }
	//the element is the first element
	 else if (temp3==head){
		 head=temp3->next;
	 }
	 //the element is in the middle
	 else{
		 while (temp4->next!=temp3)//same as element is the last.
		 {
			temp4=temp4->next;
		 }
			temp4->next=temp3->next;
		}
			free (temp3);
			counter--;
			//printf("counter is %d: \n",counter);
	}		
		 }
		 
		


		
		u16* print_list()
		{
			u8 i=0;
		u16 *arr=(u16*)malloc(counter*sizeof(u16));
		element*temp5=head;
		if (temp5==NULL){
			//printf("i is : %d\n",i);
			printf("list is empty\n");
			return 0;
		
		}
		while(temp5->next!=NULL)
		{
			arr[i]=temp5->data;
			temp5=temp5->next;
			i++;
		}
		
		arr[i]=temp5->data;
		return arr;
		}
		
		
		
		
		void add_node_middle(u8 value,u8 index)
		{
			element* user= create_element();//create the element
			user->data=value;//fill it with the data.
			//search for the index to place it in.
			u8 index_counter=0;
			element*temp6=head;
			if(temp6!=NULL){
				printf("test1\n");
				while(temp6->next!=NULL){
					printf("test2\n");
					if (index==0){
						printf("test4\n");
						user->next=temp6;
						head=user;
						counter++;
						break;
				}
					else if (index_counter==index-1){
						printf("test3\n");
						user->next=temp6->next;
						temp6->next=user;
						counter++;
						break;
					}
					temp6=temp6->next;
					index_counter++; //this means that temp is pointing now at the next element
					
				}
				
			}
		}