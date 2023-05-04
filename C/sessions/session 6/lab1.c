#include<stdio.h>

int main(){
	int x=10;
	printf("the number before is %d\n",x);
	int *ptr=&x;
	*ptr=20;
	printf("the number after is %d",x);
}