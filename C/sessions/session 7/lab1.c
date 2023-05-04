#include<stdio.h>
struct employee{
	int salary;
	int bonus;
	int deductions;
};
void main(){
	struct employee arr[3];
	struct employee total_value={0,0,0};
	char* names[3]={"Ahmed","Amr","Wael"};
for (int i=0;i<3;i++){
	printf("enter %s salary:  \n",names[i]);
	scanf("%d",&(arr[i].salary));
	printf("enter %s bonus:  \n",names[i]);
	scanf("%d",&(arr[i].bonus));
	printf("enter %s deductions:  \n",names[i]);
	scanf("%d",&(arr[i].deductions));
	total_value.salary+=arr[i].salary;
	total_value.bonus+=arr[i].bonus;
	total_value.deductions+=arr[i].deductions;
}
printf("total salary= %d",total_value.salary);
}