#include<stdio.h>
int x;
int y;
int add (void);
int sub (void);
int mul (void);
float div (void);

void main(){
	printf("enter number 1: ");
	scanf("%d",&x);
	printf("enter number 2: ");
	scanf("%d",&y);
	printf("addition is: %d\n",add());
	printf("subtraction is: %d\n",sub());
	printf("multiplication is: %d\n",mul());
	printf("division is: %f\n",div());
	
	
}
int add(){
	return x+y;
}
int sub(){
	return x-y;
}
int mul(){
	return x*y;
}
float div(){
	return (float)x/y;
}