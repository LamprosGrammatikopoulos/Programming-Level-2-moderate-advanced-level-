#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
void rotate90left(char **pixel,FILE *processed)
{
	int i=0,j=0,k=0;
	extern int X,Y;
	char **output2,*temp0;
	/*ftiaxnoume ton neo pinaka*/
	output2=(char **)malloc(Y*sizeof(char*));
	if(output2==NULL)
	{
		exit(1);
	}
	for(i=0;i<X;i++)
	{
		output2[i]=(char *)malloc(X*sizeof(char));		
		if(output2[i]==NULL)
		{
			exit(1);
		}
	}
	/*Malloc gia temp0*/
	temp0=(char*)malloc((X*Y)*sizeof(char));
	if(temp0==NULL)
	{
		exit(1);
	}
	/*Gemisma tou temp0*/
	k=0;
	for(i=0;i<X;i++)
	{
		for(j=0;j<Y;j++)
		{
			temp0[k]=pixel[i][j];
			k++;
		}
	}
	/*Perasma tou temp0 ston output2*/
	k=0;
	for(j=0;j<X;j++)
	{
		for(i=Y-1;i>=0;i--)				//90 <-- aristera
		{
			output2[i][j]=temp0[k];
			k++;
		}
	}
	/*k=X*Y-1;
	for(j=0;j<X;j++)
	{
		for(i=Y-1;i>=0;i--)			//90 <-- deksia
		{
			output2[i][j]=temp0[k];
			k--;
		}
	}*/
	for(i=0;i<Y;i++)
	{
		for(j=0;j<X;j++)
		{
			fwrite(&output2[i][j],sizeof(char),1,processed);
		}
	}
	/*free tou neou pinaka*/
	free(temp0);
}
