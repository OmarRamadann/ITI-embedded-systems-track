#include<stdio.h>// question if global var better or local in (int function())?
int get_max(int a,int b,int c, int d);
int get_min(int a,int b,int c, int d);
int main(){
	int arr[4];
	int result_max;
	int result_min;
	for (int i=1;i<5;i++){
	printf("enter number % : ",i);
	scanf("%d",&arr[i-1]);
	}
	result_max=get_max(arr[0],arr[1],arr[2],arr[3]);
	result_min=get_min(arr[0],arr[1],arr[2],arr[3]);
	printf("the max. number is : %d\n",result_max);
	printf("the min. number is : %d",result_min);
	
}
int get_max(int a,int b,int c, int d){
	if ((a>b)&&(a>c)&&(a>d)){
		return a;
	}
	else if((b>a)&&(b>c)&&(b>d)){
		
		return b;
	}
	else if((c>a)&&(c>b)&&(c>d)){
		
		return c;
	}
	else{
		return d;
	}
	
	}
	
	
	

int get_min(int a,int b,int c, int d){
	if ((a<b)&&(a<c)&&(a<d)){
		return a;
	}
	else if((b<a)&&(b<c)&&(b<d)){
		
		return b;
	}
	else if((c<a)&&(c<b)&&(c<d)){
		
		return c;
	}
	else{
		return d;
	}
	
	}
