#include<stdio.h>
void main(){
	float result;
	int denom;
	int numer;
	int arr[4];
	for(int i=0;i<4;i++){
	printf("enter value %i",i+1);
	scanf("%d",&arr[i]);
	


}
numer=arr[0]+arr[1];
denom=arr[2]-arr[3];
if (denom==0){
	printf("error division by zero");
}
else{
	printf("ratio is :%0.2f",(float)numer/denom);
}

}