#include<stdio.h>
void main(){
	
	int height;
	int base;
	int inc=1;
	printf("enter height");
	scanf("%d",&height);
	base=(2*height)-1;
	for (int a=0;a<height;a++){
		int k=(base-inc)/2;
		int flag=0;
	for(int j=0;j<2;j++){
		
	for(int i=0;i<k;i++){
		printf(" ");
		
		
	}
	
	for(int p=0;p<inc;p++){
	if(flag==1){
		break;
	}
	printf("*");
	
	}
	printf("\n");
	flag=1;
	
	}inc+=2;
	}
	
}