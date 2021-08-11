#include <stdio.h>
int product(int n1, int n2);
int main()
{
	int num1,num2;
	printf("Enter first number: \n");
	do
  {
  	scanf("%d",&num1);
  	scanf("%d",&num2);
	}while(num1<0 || num2<0);
	printf("The result is %d\n",product(num1,num2));
	return 0;
}
int product(int n1, int n2)
{
	if(n1==1)
	{
		return n2;
	}
	else
	{
		return n2+product(n1-1,n2);
	}
}
