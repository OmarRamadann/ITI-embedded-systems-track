#include<stdio.h>
void main(){
	int a;
	printf("please enter number:");
	scanf("%d",&a);
	if (a%2==0){
		printf("Number is even");
	}
	else{
		printf("number is odd");
	}
}