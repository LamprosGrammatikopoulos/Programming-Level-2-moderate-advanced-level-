/*HEADER*/
#define size 100
#define smallersize 10
char *lex2[smallersize];
char **pixel;
unsigned char code[size]={'\0'},creator[size]={'\0'},dimX[size]={'\0'},dimY[size]={'\0'},palette[size]={'\0'};
int pal=0,X=0,Y=0,megCreator=0,megX=0,megY=0,megpalette=0,allsize=0;
void spnoise(char **pixel,FILE *photo,FILE *processed,int pal);
void FH(char **pixel,FILE *processed);
void FV(char **pixel,FILE *processed);
void rotate90right(char **pixel,FILE *processed);
void rotate90left(char **pixel,FILE *processed);
void rotate180(char **pixel,FILE *processed);
