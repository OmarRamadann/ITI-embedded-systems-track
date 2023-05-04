#include<stdio.h>
void func (int *arr);
int main(){
	//int tmp;
	//int flag=0;
	int arr[10]={8,6,7,10,4,1,20,36,9,26};
	func(arr);
	
}
void func(int*arr){
	int tmp;
	int flag=0;
	for (int i=0;i<10;i++){
		for(int j=0;j<10-1-i;j++){
			if (arr[j]>arr[j+1]){
				
				tmp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=tmp;
			flag=1;
			}
		}
		if (flag==0){
			printf("the array is sorted\n");
			break;
		}
	}
	for(int i=0;i<10;i++){
		printf("%d\n",arr[i]);
	}
}