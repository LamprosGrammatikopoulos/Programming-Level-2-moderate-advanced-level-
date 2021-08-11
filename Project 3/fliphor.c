#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
void FH(char **pixel,FILE *processed)
{
	int i=0,j=0,a=0;
	extern int X,Y;
	char **output0;
	a=Y/2;
	/*ftiaxnoume ton neo pinaka*/
	output0=(char **)malloc(X*sizeof(char*));
	if(output0==NULL)
	{
		exit(1);
	}
	for(i=0;i<X;i++)
	{
		output0[i]=(char *)malloc(Y*sizeof(char));		
		if(output0[i]==NULL)
		{
			exit(1);
		}
	}
	/*antistrefoume ton pinaka*/
	for(j=0;j<a;j++)
	{
		for(i=0;i<X;i++)
		{
			output0[i][Y-1-j]=pixel[i][j];
		}
	}
	for(j=a;j<Y;j++)
	{
		for(i=0;i<X;i++)
		{
			output0[i][Y-1-j]=pixel[i][j];
		}
	}
	/*Ekthpwsh tou neou pinaka*/
	for(i=0;i<X;i++)
	{
		for(j=0;j<Y;j++)
		{
			fwrite(&output0[i][j],sizeof(char),1,processed);
		}
	}
	/*free tou neou pinaka*/
	for(i=0;i<X;i++)
	{
		free(output0[i]);
	}
	free(output0);
}
