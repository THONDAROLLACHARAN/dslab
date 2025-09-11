#include <stdio.h>
int main()
{
	int roll_no;
	char name[50];
	int marks[5],total=0;
	int i;
	
	printf("Enter Roll Number: ");
	scanf("%d", &roll_no);
	printf("Enter Name: ");
	scanf("%s",&name);
	for(i = 0 ; i < 5 ; i++) {
		printf("Enter marks for subject %d: ",i + 1);
		scanf("%d",&marks[i]);
		total+=marks[i];
	}
	printf("\n---student details(using Arrays)---\n");
	printf("Roll number: %d\n",roll_no);
	printf("Name: %s\n",name);
	printf("Marks: ");
	
	for(i = 0 ; i < 5 ;i++)
	{
		printf("%d ",marks[i]);
	}
	printf("\nTotal: %d\n",total);
	return 0;
}
