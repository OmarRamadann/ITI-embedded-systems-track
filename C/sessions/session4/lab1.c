#include<stdio.h>
int Get_Max (int x,int y);
int a,b,result;
int main(){
	printf("enter no.1: ");
	scanf("%d",&a);
	printf("enter no.2: ");
	scanf("%d",&b);
	result=Get_Max(a,b);
	printf("result is : %d",result);
}
int Get_Max(int x,int y){
	if (a>b){
		return a;
	}
	else{
		return b;
	}
}