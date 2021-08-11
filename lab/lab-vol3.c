#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
 char name[50];
 int id;
 double timh;
}stock;
int main(void)
{
 stock *ptr
 int n,i;
 double pr;
 printf("Give the num of stocks:");
 scanf("%d",&n);
 ptr=(stock*)malloc(n*sizeof(stock));
 if(prt==null)
  {
   printf("no memo");
  }
for(i=0;i<n;i+=)
{
 printf("Give stock %d",i+1);
 printf("\nname:");
 fgets(prt[i],name,50,stdin);
 printf("\n id:");
 scanf("%d",&prt[i].id);
 prinf("\n price:");
 scanf("%lf",&ptr[i].timh);
}
printf("Give a price:");
scanf("%lf",pr);
for(i=0;i<n;i++)
{
 if(ptr[i].timh<pr)
  {
   printf("%ptr\n",ptr[i].name);
  }
}free(ptr);
return 0;
}
 
