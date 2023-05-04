#include<stdio.h>//problem in swap
#include<stdlib.h>
void swap(int a,int b);
int main(){
int size=10;
int number[10];//number [size] not allowed must have const number
int search;
int mid=0;
int start=0;
int end =size-1;
int index=0;
int flag=0;
int tmp;
char dec;
do{
	system("cls");
for (int i=0;i<size;i++){
	printf("enter value %d: ",i+1);
	scanf("%d",&number[i]);
}	
	
	//bubble sort algorithm
	
	for (int i=0;i<size;i++){
		for(int j=0;j<(size-1-i);j++){
		if(number[j]<number[j+1]){//descending
			//printf("first debug");
			//printf("number %d is %d\n",j,number[j]);
			//printf("number %d is %d\n",j+1,number[j+1]);
			//swap(number[j],number[j+1]);
			tmp=number[j];
			number[j]=number[j+1];
			number[j+1]=tmp;
			
			//printf("number after %d is %d\n",j,number[j]);
			//printf("number after  %d is %d\n",j+1,number[j+1]);
			flag=1;
			
		}
		
		}
		if (flag==0){
			/*put this condition after first (for) as 
			if no sort happens at first then array is sorted*/
			printf("the array is sorted\n");
			
			break;
		}
	}
	printf("the max. no. is: %d\n",number[0]);
	printf("the min. no. is: %d\n",number[size-1]);
	printf("press e to exit \n");
	scanf(" %c",&dec);
}while(dec!='e');
}
	
	