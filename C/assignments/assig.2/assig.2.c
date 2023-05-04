#include<stdio.h>
void main(){
	int a;
	int b;
	printf("please enter ID:");
	scanf("%d",&a);
	if (a>0 &&a<=25){
		printf("enter password:");
		scanf("%d",&b);//scan string??
	}
	else{
		printf("incorrect ID");
	}
	switch (a){
	case 1:
	if(b==2001){
		printf("user name is Ahmed");
	}
	else {
		printf("incorrect password");
	}
	break;
	case 2:
	if(b==2002){
		printf("user name is omar");
	}
	else {
		printf("incorrect password");
	}
	break;
	
	}
	}