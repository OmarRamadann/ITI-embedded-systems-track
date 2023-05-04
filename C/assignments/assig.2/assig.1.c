#include<stdio.h>
void main(){
	int a,b,c,d,e,f,g,h,i,j,k;
	int arr[10];
	int flag=0;
	for (int i=0;i<10;i++){
	printf("please enter number%i:",i);
	scanf("%d",&a);
	arr[i]=a;
	}
	/*printf("please enter number2:");
	scanf("%d",&b);
	printf("please enter number3:");
	scanf("%d",&c);
	printf("please enter number4:");
	scanf("%d",&d);
	printf("please enter number5:");
	scanf("%d",&e);
	printf("please enter number6:");
	scanf("%d",&f);
	printf("please enter number7:");
	scanf("%d",&g);
	printf("please enter number8:");
	scanf("%d",&h);
	printf("please enter number9:");
	scanf("%d",&i);
	printf("please enter number10:");
	scanf("%d",&j);*/
	printf("enter value to search:");
	scanf("%d",&k);
	for(int j=0;j<10;j++){
		
	if (k==arr[j]){
		printf("value is exist at element number:%d",j+1);
		flag=1;
		break; //break??
	}
	}
	if (flag==0){
	
	printf("number no exist");
	}
	
}