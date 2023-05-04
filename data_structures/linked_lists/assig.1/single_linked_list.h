#include<stdio.h>
//create a struct for the node
typedef struct node{
	u16 data;
	struct node *next;
}element;


element* create_element();
void add_element(u8 data);
element* search_element(u8 data);
void delete_list (u8 data);
u16* print_list();
void add_node_middle(u8 value,u8 index);