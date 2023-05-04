#ifndef DOUBLE_LINKED_LIST_H_
#def DOUBLE_LINKED_LIST_H_

#define null=(void*)0

//create a struct for the node
typedef struct node{
	u16 data;
	element *next;
	element *previous;
}element;

element* Head=NULL; //create head pointing to dummy then pointing to first element 
element* tail=NULL



#endif