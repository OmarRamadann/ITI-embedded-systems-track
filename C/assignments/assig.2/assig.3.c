#include<stdio.h>
void main(){
	int a;
	int b;
	int c;
	int biggest;
	printf("please enter number1:");
	scanf("%d",&a);
	printf("please enter number2:");
	scanf("%d",&b);
	printf("please enter number3:");
	scanf("%d",&c);
	if (a>b &&a>c){
		printf("Maximum number is %d",a);
	}
	else if(b>a && b>c){
		printf("Maximum number is %d",b);
	}
	else{
		printf("Maximum number is %d",c);
	}
}