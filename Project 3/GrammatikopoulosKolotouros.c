#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
/*Header file*/	
#include "header.h"
int main(argc,argv)
int argc;
char *argv[];
{
	srand(time(NULL));
	FILE *photo,*processed;
	int x=0,y=0,i=0,j=0,c=0,a=0,b=0,flag=0;
	char lex[smallersize]={'\0'};
	/*elegxos gia orismata grammhs entolwn*/
	if(argc!= 4)
	{
		printf("You must give 4 arguments.\n");
	}
	/*Anoigoume ta arxeia kai prosthetoume to .pgm sto telos*/
	strcat(lex,argv[3]);
	strcat(argv[2],".pgm");
	strcat(lex,".pgm");
	/*elegxos gia to an to input file exei idio onoma me to output file kati pou den mporei na ginei*/
	if(!(strcmp(argv[2],lex)))
	{
		printf("[input_file] and [output_file] must not be the same.\n");
		return 0;
	}
	if(!(photo=fopen(argv[2],"rb")))
	{
		printf("Error oppening [input_file] file.\n");
		return 0;
	}
	if(!(processed=fopen(lex,"wb")))
	{
		printf("Error oppening [output_file] file.\n");
		return 0;
	}
	fread(&code[0],sizeof(unsigned char),1,photo);
	fwrite(&code[0],sizeof(unsigned char),1,processed);
	fread(&code[1],sizeof(unsigned char),1,photo);	
	fwrite(&code[1],sizeof(unsigned char),1,processed);
	fread(&code[2],sizeof(unsigned char),1,photo);
	fwrite(&code[2],sizeof(unsigned char),1,processed);
	/*elegxoume an einai to P5\n o kwdikos ths eikonas*/
	if(code[0]!='P' && code[1]!='5')
	{
		printf("Please give a valid picture type.\n");
		return 0;
	}
	/*elegxos gia allagh diastashs*/
	if( (!strcmp(argv[1],"-rR1")) || (!strcmp(argv[1],"-rL1")) || (!strcmp(argv[1],"-rR3")) || (!strcmp(argv[1],"-rL3")))
	{
		flag=1;
	}
	/*An exoume creator*/
	fread(&creator[0],sizeof(creator[0]),1,photo);
	if(creator[0]=='#')
	{
		fwrite(&creator[0],sizeof(unsigned char),1,processed);
		i++;
		while(!feof(photo))
		{
			fread(&creator[i],sizeof(unsigned char),1,photo);
			fwrite(&creator[i],sizeof(unsigned char),1,processed);
			if(creator[i]=='\n')
			{
				break;
			}
			i++;
		}
		/*Diastash X*/
		i=0;
			while(!feof(photo))
			{
				fread(&dimX[i],sizeof(unsigned char),1,photo);
				if(flag!=1)
				{
					fwrite(&dimX[i],sizeof(unsigned char),1,processed);
				}
				if(dimX[i]==' ')
				{
					dimX[i]='\0';
					break;
				}
				i++;
			}
			/*Diastash Y*/
			j=0;
			while(!feof(photo))
			{
				fread(&dimY[j],sizeof(unsigned char),1,photo);
				if(flag!=1)
				{
					fwrite(&dimY[j],sizeof(unsigned char),1,processed);
				}
				if(dimY[j]=='\n')
				{
					dimY[i]='\0';
					break;
				}
				j++;
			}
	}
	/*An den exoume creator*/
	else
	{
		/*Diastash X*/
		dimX[0]=creator[0];
		if(!(strcmp(argv[1],"-rR2")) || !(strcmp(argv[1],"-rL2")) || !(strcmp(argv[1],"-rR4")) || !(strcmp(argv[1],"-rL4")) || (!strcmp(argv[1],"-fV")) || (!strcmp(argv[1],"-fH")) )
		{
			fwrite(&dimX[0],sizeof(unsigned char),1,processed);
		}
			i=1;
			while(!feof(photo))
			{
				fread(&dimX[i],sizeof(unsigned char),1,photo);
				if(flag!=1)
				{
					fwrite(&dimX[i],sizeof(unsigned char),1,processed);
				}
				if(dimX[i]==' ')
				{
					dimX[i]='\0';
					break;
				}
				i++;
			}
			/*Diastash Y*/
			j=0;
			while(!feof(photo))
			{
				fread(&dimY[j],sizeof(unsigned char),1,photo);
				if(flag!=1)
		    {
					fwrite(&dimY[j],sizeof(unsigned char),1,processed);
				}
				if(dimY[j]=='\n')
				{
					dimY[i]='\0';
					break;
				}
				j++;
			}
	}
	/*AN XREIAZOMASTE THN SYNARTHSH TWN 90 MOIRWN*/
	if(flag==1)
	{
		for(i=0;i<strlen(dimY);i++)
		{
			fwrite(&dimY[i],sizeof(char),1,processed);
		}
		lex[0]=' ';
		fwrite(&lex[0],sizeof(char),1,processed);
		for(i=0;i<strlen(dimX);i++)
		{
			fwrite(&dimX[i],sizeof(char),1,processed);
		}
		lex[0]='\n';
		fwrite(&lex[0],sizeof(char),1,processed);
	}
	/*gia paleta*/
	i=0;
	while(!feof(photo))
	{
		fread(&palette[i],sizeof(char),1,photo);
		fwrite(&palette[i],sizeof(unsigned char),1,processed);
		if(palette[i]=='\n')
		{
			c=i;
			if(((int)palette[i-1]-48)%2==0)
			{
				for(i=0;i<c;i++)
				{
					palette[i]='\0';
				}
				printf("Please give a valid palette.\n");
				printf("A valid palette must follow the type 2^(n)-1.\n");
			}
			palette[c]='\0';
			break;
		}
		i++;
	}
	X=atoi(dimY);
	Y=atoi(dimX);
	pal=atoi(palette);
	/*ftiaxnoume ton pinaka*/
	pixel=(char **)malloc(X*sizeof(char*));
	if(pixel==NULL)
	{
		return 0;
	}
	for(i=0;i<X;i++)
	{
		pixel[i]=(char *)malloc(Y*sizeof(char));		
		if(pixel[i]==NULL)
		{
			return 0;
		}
	}
	/*megethos creator,x,y,palette*/
	megCreator=strlen(creator);
	megX=strlen(dimX);
	megY=strlen(dimY);
	megpalette=strlen(palette);
	/*Bazoume ta upoloiapa stoixeia ston pinaka pixel*/
	i=0;
	j=0;
	while(!feof(photo))
	{
		fread(&pixel[i][j],sizeof(char),1,photo);
		if(i<X && j==Y-1)
		{
			i++;
			j=0;
		}
		else if(j<Y)
		{
			j++;
		}
	}
	/*Salt and pepper noise*/
	if(!(strcmp(argv[1],"-n")))
	{
		spnoise(pixel,photo,processed,pal);
		printf("Salt & pepper noise applied on the image.\n");
	}
	/*Flip horizontal*/
	else if(!(strcmp(argv[1],"-fH")))
	{
		FH(pixel,processed);
		printf("Horizontal flip applied on the image.\n");
	}
	/*FLip vertical*/
	else if(!(strcmp(argv[1],"-fV")))
	{
		FV(pixel,processed);
		printf("Vertical flip applied on the image.\n");
	}
	/*---------------------deksiostrofa-------------------*/
	/*Rotate deksiostrofa 90*/
	else if(!(strcmp(argv[1],"-rR1")))
	{
		rotate90right(pixel,processed);
		printf("90 degrees right rotation applied on the image.\n");
	}
	/*Rotate deksiostrofa 180*/
	else if(!(strcmp(argv[1],"-rR2")))
	{
		rotate180(pixel,processed);
		printf("180 degrees right rotation applied on the image.\n");
	}
	/*Rotate deksiostrofa 270*/
	else if(!(strcmp(argv[1],"-rR3")))
	{
		rotate90left(pixel,processed);
		printf("270 degrees right rotation applied on the image.\n");
	}
	/*Rotate deksiostrofa 360*/
	else if(!(strcmp(argv[1],"-rR4")))
	{
		for(i=0;i<X;i++)
		{
			for(j=0;j<Y;j++)
			{
				fwrite(&pixel[i][j],sizeof(char),1,processed);
			}
		}
		printf("360 degrees right rotation applied on the image.\n");
	}
	/*---------------------aristerostrofa-------------------*/
	/*Rotate aristerostrofa 90*/
	else if(!(strcmp(argv[1],"-rL1")))
	{
		rotate90left(pixel,processed);
		printf("90 degrees left rotation applied on the image.\n");
	}
	/*Rotate aristerostrofa 180*/
	else if(!(strcmp(argv[1],"-rL2")))
	{
		rotate180(pixel,processed);
		printf("180 degrees left rotation applied on the image.\n");
	}
	/*Rotate aristerostrofa 270*/
	else if(!(strcmp(argv[1],"-rL3")))
	{
		rotate90right(pixel,processed);
		printf("270 degrees left rotation applied on the image.\n");
	}
	/*Rotate aristerostrofa 360*/
	else if(!(strcmp(argv[1],"-rL4")))
	{
		for(i=0;i<X;i++)
		{
			for(j=0;j<Y;j++)
			{
				fwrite(&pixel[i][j],sizeof(char),1,processed);
			}
		}
		printf("360 degrees left rotation applied on the image.\n");
	}
	else
	{
		printf("Please give a valid <-option>.\n");
		printf("Valid ones: <-n> <-fV> <-fH> <-rR1> <-rR2> <-rR3> <-rR4> <-rL1> <-rL2> <-rL3> <-rL4>\n");
	}
	/*kanoume tis free*/
	if(flag==1)
	{
		for(i=0;i<Y;i++)
		{
			free(pixel[i]);
		}
		free(pixel);
	}
	else
	{
		for(i=0;i<X;i++)
		{
			free(pixel[i]);
		}
		free(pixel);
	}
	/*kleinoume ta arxeia*/
	fclose(processed);
	fclose(photo);
	return 0;
}
