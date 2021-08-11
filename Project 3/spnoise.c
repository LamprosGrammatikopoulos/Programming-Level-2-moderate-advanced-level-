#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
void spnoise(char **pixel,FILE *photo,FILE *processed,int pal)
{
  srand(time(NULL));
  extern char *lex2[10];
  extern int X,Y;
  int i=0,j=0,a=0,b=0;
  for(i=0;i<X;i++)
  {
  	for(j=0;j<Y;j++)
  	{
			/*rand gia to an tha allaksei to pixel*/
			a=rand()%20;
			if(a==1)
			{
				/*rand gia to an tha einai mauro h aspro*/
				b=rand()%2;
				if(b==0)
				{
					pixel[i][j]=0;
					fwrite(&pixel[i][j],sizeof(char),1,processed);
				}
				else if(b==1)
				{
					fwrite(&pal,sizeof(char),1,processed);
				}
			}
			else if(a!=1)
			{
				fwrite(&pixel[i][j],sizeof(char),1,processed);
			}
		}
	}
}
