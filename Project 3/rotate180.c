#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
void rotate180(char **pixel,FILE *processed)
{
	int i=0,j=0,a=0;
	extern int X,Y;
	char **output4,**output5;
/*--------------------------------------FV----------------------------------------------*/
	a=Y/2;
	/*ftiaxnoume ton neo pinaka*/
	output4=(char **)malloc(X*sizeof(char*));
	if(output4==NULL)
	{
		exit(1);
	}
	for(i=0;i<X;i++)
	{
		output4[i]=(char *)malloc(Y*sizeof(char));		
		if(output4[i]==NULL)
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
			output4[X-1-i][j]=pixel[i][j];
		}
	}
	for(i=a;i<X;i++)
	{
		for(j=0;j<Y;j++)
		{
			output4[X-1-i][j]=pixel[i][j];
		}
	}
/*------------------------------------------FH---------------------------------------------------*/
	a=Y/2;	
	output5=(char **)malloc(X*sizeof(char*));
	if(output5==NULL)
	{
		exit(1);
	}
	for(i=0;i<X;i++)
	{
		output5[i]=(char *)malloc(Y*sizeof(char));		
		if(output5[i]==NULL)
		{
			exit(1);
		}
	}
	/*antistrefoume ton pinaka*/
	for(j=0;j<a;j++)
	{
		for(i=0;i<X;i++)
		{
			output5[i][Y-1-j]=output4[i][j];
		}
	}
	for(j=a;j<Y;j++)
	{
		for(i=0;i<X;i++)
		{
			output5[i][Y-1-j]=output4[i][j];
		}
	}
	/*Ekthpwsh tou neou pinaka*/
	for(i=0;i<X;i++)
	{
		for(j=0;j<Y;j++)
		{
			fwrite(&output5[i][j],sizeof(char),1,processed);
		}
	}
	/*free tou neou pinaka*/
	for(i=0;i<X;i++)
	{
		free(output4[i]);
	}
	free(output4);
	/*free tou neou pinaka output5*/
	for(i=0;i<X;i++)
	{
		free(output5[i]);
	}
	free(output5);
}
