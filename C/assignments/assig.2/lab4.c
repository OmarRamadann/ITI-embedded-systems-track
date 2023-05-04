#include<stdio.h>
void main(){
	int a;
	printf("please enter number:");
	scanf("%d",&a);
	if(a<50 && a>=0){
		printf("your rating is failed");
	}
	else if(a>=50&& a<65){
		printf("your rating is normal");
	}
	else if (a>=65 && a<75){
	printf("your rating is good");}
		else if(a>=75 &&a<85){
			printf("your rating is very good");
		}
		else{
			printf("your rating is excellent");
		}
	
	
	
	
}