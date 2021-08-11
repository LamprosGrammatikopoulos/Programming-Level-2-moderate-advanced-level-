#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
void FV(char **pixel,FILE *processed)
{
	int i=0,j=0,a=0;
	extern int X,Y;
	char **output1;
	a=Y/2;
	/*ftiaxnoume ton neo pinaka*/
	output1=(char **)malloc(X*sizeof(char*));
	if(output1==NULL)
	{
		exit(1);
	}
	for(i=0;i<X;i++)
	{
		output1[i]=(char *)malloc(Y*sizeof(char));		
		if(output1[i]==NULL)
		{
			exit(1);
		}
	}
	/*antistrefoume ton pinaka*/
	a=X/2;
	for(i=0;i<a;i++)
	{
		for(j=0;j<Y;j++)
		{
			output1[X-1-i][j]=pixel[i][j];
		}
	}
	for(i=a;i<X;i++)
	{
		for(j=0;j<Y;j++)
		{
			output1[X-1-i][j]=pixel[i][j];
		}
	}
	/*Ekthpwsh tou neou pinaka*/
	for(i=0;i<X;i++)
	{
		for(j=0;j<Y;j++)
		{
			fwrite(&output1[i][j],sizeof(char),1,processed);
		}
	}
	/*free tou neou pinaka*/
	for(i=0;i<X;i++)
	{
		free(output1[i]);
	}
	free(output1);
}
