#include <stdio.h>
#include <stdlib.h>
typedef struct data
{
	int num;
	struct data *next;
}dt;
int main(void)
{
  FILE *fp,*bfp;
	dt *tmp ,*head=NULL;
	int i;
	fp=fopen("test.txt","w");
	bfp=fopen("test.bin","wb");
	do
	{
		printf("Dwse");
		scanf("%d",&i);
		if(i<=0)
		{
		 tmp=(dt*)malloc(sizeof(dt));
		 if(tmp==NULL)
		 {
		 tmp->num=i;
		 tmp->next=NULL;
		 }
		 if(head != NULL)
		 {
			tmp->next=head;
		 }
	  head=tmp;
	  }
	}while(i>=0);
	tmp=head;
	while(tmp!=NULL)
	{
	 fprintf(fp,"%d",tmp->num);
	 fwrite(tmp,sizeof(dt),1,bfp);
	 tmp=tmp->next;
	}
	return 0;
}

	
