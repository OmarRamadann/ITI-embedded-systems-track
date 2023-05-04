#include<stdio.h>
int x=10;
int y=20;
//int z;
void swap(void);//no arguments given
int main(){
	

swap();
printf("x after swap: %d\n",x);
printf("y after swap: %d",y);
	
}
void swap(void){
	int z;
	z=x;
	x=y;
	y=z;
	/*  swap rule 
	x=x+y;
	y=x-y;
	x=x-y;*/
}