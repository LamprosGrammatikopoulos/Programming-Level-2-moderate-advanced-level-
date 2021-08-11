#include <stdio.h>
#include <stdlib.h>
int summing(int array[],int len);
int main()
{
 int len,i;
 int *array;
 printf("Dwse mikos");
 scanf("%d",&len);
 array=(int *)malloc(sizeof(len));
 for(i=0;i<len;i++)
  {
   scanf("%d",&array[i]);
  }
 printf("Result\n",summing(array,len));
 return 0;
}
int summing(int array[],int len)
{
	int a=0;
	if(len==1)
	{
	 return a;
	}
	else
	{
	 a=a+array[len-1];
	 return summing(array,len-1);
	}
}

