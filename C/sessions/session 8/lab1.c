#include <stdio.h>
#include <stdlib.h>
#include "std_data_types.h"
void swap (u16* a,u16* b);
void main ()
{
	u16 flag=0;
	u8 NumberOfElement ;
	u16 new_number_element;
	u16 *Numbers = NULL ; 
	u8 counter = 0 ;
	u16 upper_count;
	u16 lower_count;
	printf("Enter the NumberOfElement:");
	scanf("%d",&NumberOfElement);
	free(Numbers);
	Numbers = (u16*)malloc(5 * sizeof(u16));//address for first byte allocated
	//for scanning 
	for(counter=0;counter<NumberOfElement;counter++)
	{
		printf("Enter the Number[%d]:",counter);
		scanf("%d",&Numbers[counter]);
		//scanf("%d",(Numbers+counter));
		
	}
	/*Bubble Sorting*/
	for(upper_count=0;upper_count<NumberOfElement-1;upper_count++){
		for(lower_count=0;lower_count<NumberOfElement-1-upper_count;lower_count++){
			if (Numbers[lower_count]<Numbers[lower_count+1]){
				swap(&Numbers[lower_count],&Numbers[lower_count+1]);
				flag=1;
				
			}
		}
		if (flag==0){
			printf("the numbers are sorted\n");
			break;
		}
	}
	
	
	//for Display
	for(counter=0;counter<NumberOfElement;counter++)
	{
		printf(" the Number[%d]=%d\n",counter,*(Numbers+counter));
		//printf("Enter the Number[%d]=%d",counter, Numbers[counter]);	
	}
	printf("enter the new number of elements\n");
	scanf("%d",&new_number_element);
	realloc(Numbers,new_number_element*sizeof(16));
	printf("the last element of the first array is: %d",NumberOfElement-1);
	//scanning new elements
	for (counter=NumberOfElement;counter<new_number_element;counter++){
		printf ("enter the value[%d] :",counter);
		scanf("%d",(Numbers+counter));
	}
	//display new elements
	for(counter=NumberOfElement;counter<new_number_element;counter++)
	{
		printf(" the Number[%d]=%d\n",counter,*(Numbers+counter));
		//printf("Enter the Number[%d]=%d",counter, Numbers[counter]);	
	}
}
	
	
	
	
	
