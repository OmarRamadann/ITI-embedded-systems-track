#include<stdio.h>
void swap (int*x,int*y,int*z);

int main(){
	int x=20;
	int y=30;
	int z=40;
	int*p=&x;
	int*q=&y;
	int*r=&z;
	printf("x= %d\n",x);
	printf("y= %d\n",y);
	printf("z= %d\n",z);
	printf("p= %d\n",p);
	printf("q= %d\n",q);
	printf("r= %d\n",r);
	printf("*p= %d\n",*p);
	printf("*q= %d\n",*q);
	printf("*r= %d\n",*r);
	printf("swapping pointers\n");
	swap(p,q,r);
	printf("x= %d\n",x);
	printf("y= %d\n",y);
	printf("z= %d\n",z);
	printf("p= %d\n",p);
	printf("q= %d\n",q);
	printf("r= %d\n",r);
	printf("*p= %d\n",*p);
	printf("*q= %d\n",*q);
	printf("*r= %d\n",*r);
}
void swap(int*x,int*y,int*z){
	int* tmp;
	int empty;
	//here the swap of dereferenced variables is working
	empty=*x;
	*x=*y;
	*y=*z;
	*z=empty;
	//here the swap of addresses (pointers) is not working(will be deleted after leaving swap)
	tmp=x;
	x=y;
	y=z;
	z=tmp;
}