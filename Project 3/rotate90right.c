#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
void rotate90right(char **pixel,FILE *processed)
{
	int i=0,j=0,k=0;
	extern int X,Y;
	char **output3,*temp1;
	/*ftiaxnoume ton neo pinaka*/
	output3=(char **)malloc(Y*sizeof(char*));
	if(output3==NULL)
	{
		exit(1);
	}
	for(i=0;i<X;i++)
	{
		output3[i]=(char *)malloc(X*sizeof(char));		
		if(output3[i]==NULL)
		{
			exit(1);
		}
	}
	/*Malloc gia temp1*/
	temp1=(char*)malloc((X*Y)*sizeof(char));
	if(temp1==NULL)
	{
		exit(1);
	}
	/*Gemisma tou temp1*/
	k=0;
	for(i=0;i<X;i++)
	{
		for(j=0;j<Y;j++)
		{
			temp1[k]=pixel[i][j];
			k++;
		}
	}
	/*Perasma tou temp1 ston output3*/
	//k=0;
	/*for(j=0;j<X;j++)
	{
		for(i=Y-1;i>=0;i--)			//90 <-- aristera
		{
			output3[i][j]=temp1[k];
			k++;
		}
	}*/
	k=X*Y-1;
	for(j=0;j<X;j++)
	{
		for(i=Y-1;i>=0;i--)		//90 <-- deksia
		{
			output3[i][j]=temp1[k];
			k--;
		}
	}
	for(i=0;i<Y;i++)
	{
		for(j=0;j<X;j++)
		{
			fwrite(&output3[i][j],sizeof(char),1,processed);
		}
	}
	/*free tou neou pinaka*/
	free(temp1);
}




