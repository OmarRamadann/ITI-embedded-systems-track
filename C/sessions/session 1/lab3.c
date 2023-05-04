#include<stdio.h>
int main(){
	unsigned int a;
	unsigned int b;
	printf("enter first number \n ");
	scanf("%i",&a);
	printf("enter second number \n ");
	scanf("%i",&b);
	printf("addition: %i",a+b);
	printf("subtraction: %i",a-b);
	printf("multiplication: %i",a*b);
	printf("division: %0.1f",(float)a/b);
	
	return 0;
	
}