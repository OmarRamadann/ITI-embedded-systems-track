#include<stdio.h>

int add (int a,int b);
int sub (int a,int b);
int mul (int a,int b);
float div (int a,int b);
int and (int a,int b);
int or (int a,int b);
int not (int a);
int xor (int a,int b);
int remaainder (int a,int b);
int increment (int a);
int decrement (int a);

void main(){
	char exit=0;
	do{
	int x;
	int y;
	printf("enter number 1: ");
	scanf("%d",&x);
	printf("enter number 2: ");
	scanf("%d",&y);
	printf("addition is: %d\n",add(x,y));
	printf("subtraction is: %d\n",sub(x,y));
	printf("multiplication is: %d\n",mul(x,y));
	printf("division is: %f\n",div(x,y));
	printf("anding is: %d\n",and(x,y));
	printf("oring is: %d\n",or(x,y));
	printf("NOTing x is: %d\n",not(x));
	printf("NOTing x is: %d\n",not(y));
	printf("XORing is: %d\n",xor(x,y));
	printf("remainder is: %d\n",remaainder(x,y));
	printf("inc x is: %d\n",increment(x));
	printf("inc y is: %d\n",increment(y));
	printf("dec x is: %d\n",decrement(x));
	printf("dec y is: %d\n",decrement(y));
	printf("press e to exit");
	scanf(" %c",&exit);
	
	
}while(exit!='e');
}
int add(int a,int b){
	return a+b;
}
int sub(int a,int b){
	return a-b;
}
int mul(int a,int b){
	return a*b;
}
float div(int a,int b){
	return (float)a/b;
}
int and (int a,int b){
	return a&b;
}
int or (int a,int b){
	return a|b;
}
int not (int a){
	return ~a;
}
int xor (int a,int b){
	return a^b;
}
int remaainder (int a,int b){
	return a%b;
}
int increment (int a){
	return ++a;
}
int decrement (int a){
	return --a;
}