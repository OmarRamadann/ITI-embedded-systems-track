#include<stdio.h>//problem in swap
#include<stdlib.h>
void swap(int a,int b);
int main(){
int size=10;
int class[10];//number [size] not allowed must have const number
int search;
int mid=0;
int start=0;
int end =size-1;
int index=0;
int flag=0;
int tmp;
char dec;
int ctr_pass=0;
//do{
	for (int i=0;i<3;i++){
	//system("cls");
for (int i=0;i<size;i++){
	printf("enter value %d: ",i+1);
	scanf("%d",&class[i]);
}	
	
	//bubble sort algorithm
	
	for (int i=0;i<size;i++){
		for(int j=0;j<(size-1-i);j++){
		if(class[j]<class[j+1]){//descending
			//printf("first debug");
			//printf("number %d is %d\n",j,number[j]);
			//printf("number %d is %d\n",j+1,number[j+1]);
			//swap(number[j],number[j+1]);
			tmp=class[j];
			class[j]=class[j+1];
			class[j+1]=tmp;
			
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
	for( int i=0;i<size-1;i++){
		if (class[i]>=50){
			ctr_pass++;
		}
	}
	printf("number of passed students is: %d\n",ctr_pass);
	printf("number of failed students is: %d\n",size-ctr_pass);
	printf("the max. grade is: %d\n",class[0]);
	printf("the min. grade is: %d\n",class[size-1]);
	printf("the average grade is: %d\n",class[size/2]);
	//printf("press e to exit \n");
	//scanf(" %c",&dec);
}//while(dec!='e');
}