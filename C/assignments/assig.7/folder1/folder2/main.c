#include<stdio.h>
#include "..\bitmap.h"
#include "folder3/folder4/sum.h"
#include "folder3/folder5/print.h"
void main(){
	int result;
	int no1,no2;
	scanf("%d %d",&no1,&no2);
	result=sum(no1,no2);
	print(result);
}