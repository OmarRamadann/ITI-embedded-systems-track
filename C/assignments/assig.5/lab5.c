#include<Stdio.h>//problem in swap
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
for (int i=0;i<size;i++){
	printf("enter value %d: ",i+1);
	scanf("%d",&number[i]);
}	
	printf("enter search value: ");
	scanf("%d",&search);
	//bubble sort algorithm
	
	for (int i=0;i<size;i++){
		for(int j=0;j<(size-1-i);j++){
		if(number[j]<number[j+1]){
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
	/*for( int k=0;k<10;k++){
		printf("%d\n",number[k]);
	}*/
	//binary search
	while(start<=end){
		mid=(start+end) / 2;
		//printf("the mid %d is: %d\n",mid,number[mid]);
		if (number[mid]==search){
			//printf("second debug\n");
			index=mid;
			//printf("your search in index %d",index);
			break;
		}
		else if(number[mid]<search){
			end =mid-1;
		}
		else if(number[mid]>search){
			//printf("3rd debug\n");
			
			start=mid+1;
		}
	}
	if (start>end){
		printf("value not exist");
	}
	
	
	
}