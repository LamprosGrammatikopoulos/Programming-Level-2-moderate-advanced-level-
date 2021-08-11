/*
Lampros Grammatikopoulos
AM:2022201800038
dit18038@uop.gr


Kwnstantinos Kolotouros
AM:2022201800090
dit18090@uop.gr
*/

/*
Game:<Demolition Man>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*9 giati den theloume deutero arithmo*/
#define maxrow 9
#define maxcol 9
#define stringcommand 50
char str[stringcommand]={'\0'};
double counter=0,score=0,cs=0,wombocombo=1;
char **p1;
int n=0,m=0,adN=0,adM=0,t=0;
int createarray(void);
void getcommand(void);
void numofcolors(void);
void randomnumbers(void);
void printarray(void);
void menu(void);
void gravity(void);
void bomb(void);
void add(void);
int hammer(int s1,int s2,char s3);
int quit(void);
int main(void)
{
	char temp,s3;
	int flag=0,g,pingemkouk=0,array=0,command=0,level=0;
	int i=0,j=0,k=0,q=0,alloj=0,v=0;
	char c[6]={'\0'};
	int s1,s2,h;
	int prinh=0,metah=0,l=0,met=0,met2=0;
	
	
	/*tuxaiopoihsh ths shnarthshs rand()*/
	srand(time(NULL));
	
	/*arxikopoihsh pinaka*/
	do
	{
		printf("\n");
		printf("Give strating number of rows for the border of the game (min number:3 , max number:9):");
		scanf("%d",&n);	
		p1=(char**)malloc((n+adN)*sizeof(char*));
		printf("Give strating number of columns for the border of the game (min number:3 , max number:9):");
		scanf("%d",&m);
		if(p1==NULL)
			{
				continue;
			}
		for(i=0;i<n+adN;i++)
		{
			p1[i]=(char*)malloc((m+adM)*sizeof(char));
			if(p1[i]==NULL)
				{
					continue;
				}
		}
	}while(n<3 || m<3 || n+adN>maxrow || m+adM>maxcol);
	
	/*arithmos xrwmatwn*/
	do
	{
		printf("Give maximum number of colors (from 1 to 9):");
		for(i=0;i<3;i++)
		{
			c[i]=getchar();
		}
	}while( ((int)c[1]-48<1 || (int)c[1]-48>9) || c[2]!='\n' );
	
	/*tuxaiopoihsh arithmwn*/
	for(i=0;i<n+adN;i++)
	{
		for(j=0;j<m+adM;j++)
		{
			/*etsi tuxaiopoihountai oi arithmoi alla den exoun isopithanh suxnothta emfanhshs*/
			p1[i][j]=1+rand()%((int)c[1]-48);
		}
	}
	
	/*menu paixnidiou*/
	printf("\n---------------------------------------Menu-----------------------------------------\n");
	printf("| To bomb a color press: B i,j or b i,j.                                           |\n");
	printf("| To push a color left press: pl.                                                  |\n");
	printf("| To push a color right press: pr.                                                 |\n"); 
	printf("| To add a color press: a i,j <color> or A i,j <color>.                            |\n");
	printf("| To exit Demolition Man press: X or x.                                            |\n");
	printf("---------------------------------------Tips-----------------------------------------\n");
	printf("| Keep in mind that the more colors you destroy the quicker your score advances!   |\n");
	printf("| Keep in mind that the more levels you pass the quicker your score advances!      |\n");
	printf("------------------------------------------------------------------------------------\n\n");
	 
	/*Ektupwsh pinaka*/
	printarray();
	printf("Remaining colors to brake: %d.\n", ((n+adN)*(m+adM)-pingemkouk) );
	
	do
	{
		/*dhmiourgia pinaka gia ta epomena epipeda*/
		if(level!=0 && ((n+adN)*(m+adM)-pingemkouk!=0) && l==0)
		{
			/*free p1*/
			for(i=0;i<n;i++)
			{
				free(p1[i]);
			}
			free(p1);
			if( ((n+adN)*(m+adM)-pingemkouk!=0) )
			{
				pingemkouk=0;
				p1=(char**)malloc((n+adN)*sizeof(char*));
				if(p1==NULL)
				{
					return 0;
				}
				for(i=0;i<n+adN;i++)
				{
					p1[i]=(char*)malloc((n+adN)*sizeof(char));
					if(p1[i]==NULL)
					{
						return 0;
					}
				}
			}
			/*tuxaiopoihsh arithmwn*/
			for(i=0;i<n+adN;i++)
			{
				for(j=0;j<m+adM;j++)
				{
					/*etsi tuxaiopoihountai oi arithmoi alla den exoun isopithanh suxnothta emfanhshs*/
					p1[i][j]=1+rand()%((int)c[1]-48);
				}
			}
			printarray();
			printf("Remaining colors to brake: %d.\n", ((n+adN)*(m+adM)-pingemkouk) );
		}
		/*pairnoume entolh tou paixth*/
		score=cs*(level+1);
		printf("Level:%d\n",level);
		printf("Score:%f\n",score);
		printf("Shall i wait more? Make your move:\n");
		for(i=0;i<stringcommand-1;i++)
		{
			str[i]=getchar();
			if( str[0]=='X' || str[0]=='x' )
			{
				if(i>0 && str[i]=='\n')
				{
					if(level==0)
					{
						printf("Levels you passed:%d\n",level);
						printf("Score you acquired:%f\n",score);
					}
					else if(level>0)
					{
						printf("Levels you passed:%d\n",level);
						printf("Score you acquired:%f\n",score);
					}
					printf("Thanks for playing :)\n");
					return 0;
				}
			}
			else if( str[0]=='p' )
			{
				if(i>1 && str[i]=='\n')
				{
					break;
				}
			}
			else if( (str[0]=='B' || str[0]=='b') || (str[0]=='H' || str[0]=='h') )
			{
				if(i>4 && str[i]=='\n')
				{
					break;
				}
			}
			else if( (str[0]=='A' || str[0]=='a') ) 
			{
				if(i>6 && str[i]=='\n')
				{
					break;
				}
			}
			else
			{
				printf("Please choose one of the existing commands.\n");
				break;
			}
		}
		if(str[2]==48 || str[4]==48 || str[2]>n+adN+48 || str[4]>m+adM+48)
		{
			printf("Please give a valid number.\n");
			printarray();
			continue;
		}
		
		/*bohthika ths hammer*/
		s1=(int)str[2]-49;
		s2=(int)str[4]-49;
		if(s1>=0 && s1<=9 && s2>=0 && s2<=9)
		{
			s3=p1[s1][s2];
		}
		
	/*entolh bomb*/																						
	if( ((str[0]=='B') || (str[0]=='b')) && str[1]==' ' && str[2]<=n+adN+48 && str[3]==',' && str[4]<=m+adM+48 && str[5]=='\n')
	{
		/*an o xrhsths prospathisei na vomvardisei teleia*/
		if(p1[(int)str[2]-49][(int)str[4]-49]=='.')
		{
			printf("You can not bomb an empty plate.\n");
			printarray();
			printf("Remaining colors to brake: %d.\n", ((n+adN)*(m+adM)-pingemkouk) );
			continue;
		}
		else
		{
			/*elegxos an o xrhsths edwse swstes suntetagmenes*/
			if( (str[2]<49 || str[2]>n+adN+48) || (str[4]<49 || str[4]>m+adM+48) )
			{
				printf("Please give a valid number.\n");
				counter=0;
				printarray();
				printf("Remaining colors to brake: %d.\n", ((n+adN)*(m+adM)-pingemkouk) );
				continue;
			}
			/*h kentrhkh*/
			else if((int)str[2]-1>48 && (int)str[2]+1<=n+adN+48 && (int)str[4]-1>48 && (int)str[4]+1<=m+adM+48)
			{
				/*an uparxoun hdh koukides*/
		 		if(p1[(int)str[2]-1-49][(int)str[4]-49]=='.' && p1[(int)str[2]+1-49][(int)str[4]-49]=='.' && p1[(int)str[2]-49][(int)str[4]-1-49]=='.' && p1[(int)str[2]-49][(int)str[4]+1-49]=='.' && p1[(int)str[2]-1-49][(int)str[4]-1-49]=='.' && p1[(int)str[2]-1-49][(int)str[4]+1-49]=='.' && p1[(int)str[2]+1-49][(int)str[4]-1-49]=='.' && p1[(int)str[2]+1-49][(int)str[4]+1-49]=='.')
				{
					printf("Theese boxes do not contain any color to bomb.\n");
					counter=0;
					printarray();
					printf("Remaining colors to brake: %d.\n", ((n+adN)*(m+adM)-pingemkouk) );
					continue;
				}
				counter=0;
				for(i=-1;i<2;i++)
				{
					for(j=-1;j<2;j++)
					{
						if(p1[(int)str[2]+i-49][(int)str[4]+j-49]!='.')
						{
							counter=counter+1;
							cs=cs+1;	
						}
					}
				}
				/*bonus gia megalh omada plakidiwn*/
				cs=cs+3;
				p1[(int)str[2]-49][(int)str[4]-49]='.';
				p1[(int)str[2]-1-49][(int)str[4]-49]='.';
				p1[(int)str[2]+1-49][(int)str[4]-49]='.';
				p1[(int)str[2]-49][(int)str[4]-1-49]='.';
				p1[(int)str[2]-49][(int)str[4]+1-49]='.';
				p1[(int)str[2]-1-49][(int)str[4]-1-49]='.';
				p1[(int)str[2]-1-49][(int)str[4]+1-49]='.';
				p1[(int)str[2]+1-49][(int)str[4]-1-49]='.';
				p1[(int)str[2]+1-49][(int)str[4]+1-49]='.';
				gravity();
				printarray();
			}
			/*oi tesereis gwniakes*/
			else if((int)str[2]-1<=48 && (int)str[4]-1<=48)
			{
				/*an uparxoun hdh koukides*/
		 		if(p1[(int)str[2]-49][(int)str[4]-49]=='.' && p1[(int)str[2]-49][(int)str[4]+1-49]=='.' && p1[(int)str[2]+1-49][(int)str[4]-49]=='.' && p1[(int)str[2]+1-49][(int)str[4]+1-49]=='.')
				{
					printf("Theese boxes do not contain any color to bomb.\n");
					counter=0;
					printarray();
					printf("Remaining colors to brake: %d.\n", ((n+adN)*(m+adM)-pingemkouk) );
					continue;
				}
				counter=0;
				for(i=0;i<2;i++)
				{
					for(j=0;j<2;j++)
					{
						if(p1[(int)str[2]+i-49][(int)str[4]+j-49]!='.')
						{
							counter=counter+1;
							cs=cs+1;		
						}
					}
				}
				/*bonus gia megalh omada plakidiwn*/
				cs=cs+1;
				p1[(int)str[2]-49][(int)str[4]-49]='.';
				p1[(int)str[2]-49][(int)str[4]+1-49]='.';
				p1[(int)str[2]+1-49][(int)str[4]-49]='.';
				p1[(int)str[2]+1-49][(int)str[4]+1-49]='.';
				gravity();
				printarray();
			}
			else if((int)str[2]-1<=48 && (int)str[4]+1>m+adM+48)
			{
				/*an uparxoun hdh koukides*/
		 		if(p1[(int)str[2]-49][(int)str[4]-49]=='.' && p1[(int)str[2]-49][(int)str[4]-1-49]=='.' && p1[(int)str[2]+1-49][(int)str[4]-49]=='.' && p1[(int)str[2]+1-49][(int)str[4]-1-49]=='.')
				{
					printf("Theese boxes do not contain any color to bomb.\n");
					counter=0;
					printarray();
					printf("Remaining colors to brake: %d.\n", ((n+adN)*(m+adM)-pingemkouk) );
					continue;
				}
				counter=0;
				for(i=0;i<2;i++)
				{
					for(j=-1;j<1;j++)
					{
						if(p1[(int)str[2]+i-49][(int)str[4]+j-49]!='.')
						{
							counter=counter+1;
							cs=cs+1;		
						}
					}
				}
				/*bonus gia megalh omada plakidiwn*/
				cs=cs+1;
				p1[(int)str[2]-49][(int)str[4]-49]='.';
				p1[(int)str[2]-49][(int)str[4]-1-49]='.';
				p1[(int)str[2]+1-49][(int)str[4]-49]='.';
				p1[(int)str[2]+1-49][(int)str[4]-1-49]='.';
				gravity();
				printarray();
			}
			else if((int)str[2]+1>n+adN+48 && (int)str[4]+1>m+adM+48)
			{
				/*an uparxoun hdh koukides*/
		 		if(p1[(int)str[2]-49][(int)str[4]-49]=='.' && p1[(int)str[2]-49][(int)str[4]-1-49]=='.' && p1[(int)str[2]-1-49][(int)str[4]-49]=='.' && p1[(int)str[2]-1-49][(int)str[4]-1-49]=='.')
				{
					printf("Theese boxes do not contain any color to bomb.\n");
					counter=0;
					printarray();
					printf("Remaining colors to brake: %d.\n", ((n+adN)*(m+adM)-pingemkouk) );
					continue;
				}
				counter=0;
				for(i=-1;i<1;i++)
				{
					for(j=-1;j<1;j++)
					{
						if(p1[(int)str[2]+i-49][(int)str[4]+j-49]!='.')
						{
							counter=counter+1;
							cs=cs+1;		
						}
					}
				}
				/*bonus gia megalh omada plakidiwn*/
				cs=cs+1;
				p1[(int)str[2]-49][(int)str[4]-49]='.';
				p1[(int)str[2]-49][(int)str[4]-1-49]='.';
				p1[(int)str[2]-1-49][(int)str[4]-49]='.';
				p1[(int)str[2]-1-49][(int)str[4]-1-49]='.';
				gravity();
				printarray();
			}
			else if((int)str[2]+1>=n+adN+48 && (int)str[4]-1<=48)
			{
				/*an uparxoun hdh koukides*/
		 		if(p1[(int)str[2]-49][(int)str[4]-49]=='.' && p1[(int)str[2]-1-49][(int)str[4]-49]=='.' && p1[(int)str[2]-1-49][(int)str[4]+1-49]=='.' && p1[(int)str[2]-49][(int)str[4]+1-49]=='.')
				{
					printf("Theese boxes do not contain any color to bomb.\n");
					counter=0;
					printarray();
					printf("Remaining colors to brake: %d.\n", ((n+adN)*(m+adM)-pingemkouk) );
					continue;
				}
				counter=0;
				for(i=-1;i<1;i++)
				{
					for(j=0;j<2;j++)
					{
						if(p1[(int)str[2]+i-49][(int)str[4]+j-49]!='.')
						{
							counter=counter+1;
							cs=cs+1;		
						}
					}
				}
				/*bonus gia megalh omada plakidiwn*/
				cs=cs+1;
				p1[(int)str[2]-49][(int)str[4]-49]='.';
				p1[(int)str[2]-1-49][(int)str[4]-49]='.';
				p1[(int)str[2]-1-49][(int)str[4]+1-49]='.';
				p1[(int)str[2]-49][(int)str[4]+1-49]='.';
				gravity();
				printarray();
			}
			/*oi tesereis mh gwniakes*/
			else if((int)str[2]-1<=48)
			{
				/*an uparxoun hdh koukides*/
		 		if(p1[(int)str[2]-49][(int)str[4]-49]=='.' && p1[(int)str[2]-49][(int)str[4]-1-49]=='.' && p1[(int)str[2]-49][(int)str[4]+1-49]=='.' && p1[(int)str[2]+1-49][(int)str[4]-49]=='.' && p1[(int)str[2]+1-49][(int)str[4]-1-49]=='.' && p1[(int)str[2]+1-49][(int)str[4]+1-49]=='.')
				{
					printf("Theese boxes do not contain any color to bomb.\n");
					counter=0;
					printarray();
					printf("Remaining colors to brake: %d.\n", ((n+adN)*(m+adM)-pingemkouk) );
					continue;
				}
				counter=0;
				for(i=0;i<2;i++)
				{
					for(j=-1;j<2;j++)
					{
						if(p1[(int)str[2]+i-49][(int)str[4]+j-49]!='.')
						{
							counter=counter+1;
							cs=cs+1;		
						}
					}
				}
				/*bonus gia megalh omada plakidiwn*/
				cs=cs+2;
				p1[(int)str[2]-49][(int)str[4]-49]='.';
				p1[(int)str[2]-49][(int)str[4]-1-49]='.';
				p1[(int)str[2]-49][(int)str[4]+1-49]='.';
				p1[(int)str[2]+1-49][(int)str[4]-49]='.';
				p1[(int)str[2]+1-49][(int)str[4]-1-49]='.';
				p1[(int)str[2]+1-49][(int)str[4]+1-49]='.';
				gravity();
				printarray();
			}
			else if((int)str[4]+1>m+adM+48)
			{
				/*an uparxoun hdh koukides*/
		 		if(p1[(int)str[2]-49][(int)str[4]-49]=='.' && p1[(int)str[2]-1-49][(int)str[4]-49]=='.' && p1[(int)str[2]-1-49][(int)str[4]-1-49]=='.' && p1[(int)str[2]-49][(int)str[4]-1-49]=='.' && p1[(int)str[2]+1-49][(int)str[4]-1-49]=='.' && p1[(int)str[2]+1-49][(int)str[4]-49]=='.')
				{
					printf("Theese boxes do not contain any color to bomb.\n");
					counter=0;
					printarray();
					printf("Remaining colors to brake: %d.\n", ((n+adN)*(m+adM)-pingemkouk) );
					continue;
				}
				counter=0;
				for(i=-1;i<2;i++)
				{
					for(j=-1;j<1;j++)
					{
						if(p1[(int)str[2]+i-49][(int)str[4]+j-49]!='.')
						{
							counter=counter+1;	
							cs=cs+1;	
						}
					}
				}
				/*bonus gia megalh omada plakidiwn*/
				cs=cs+2;
				p1[(int)str[2]-49][(int)str[4]-49]='.';
				p1[(int)str[2]-1-49][(int)str[4]-49]='.';
				p1[(int)str[2]-1-49][(int)str[4]-1-49]='.';
				p1[(int)str[2]-49][(int)str[4]-1-49]='.';
				p1[(int)str[2]+1-49][(int)str[4]-1-49]='.';
				p1[(int)str[2]+1-49][(int)str[4]-49]='.';
				gravity();
				printarray();
			}
			else if((int)str[2]+1>n+adN+48)
			{
				/*an uparxoun hdh koukides*/
		 		if(p1[(int)str[2]-49][(int)str[4]-49]=='.' && p1[(int)str[2]-49][(int)str[4]-1-49]=='.' && p1[(int)str[2]-49][(int)str[4]+1-49]=='.' && p1[(int)str[2]-1-49][(int)str[4]+1-49]=='.' && p1[(int)str[2]-1-49][(int)str[4]-49]=='.' && p1[(int)str[2]-1-49][(int)str[4]-1-49]=='.')
				{
					printf("Theese boxes do not contain any color to bomb.\n");
					counter=0;
					printarray();
					printf("Remaining colors to brake: %d.\n", ((n+adN)*(m+adM)-pingemkouk) );
					continue;
				}
				counter=0;
				for(i=-1;i<1;i++)
				{
					for(j=-1;j<2;j++)
					{
						if(p1[(int)str[2]+i-49][(int)str[4]+j-49]!='.')
						{
							counter=counter+1;
							cs=cs+1;		
						}
					}
				}
				/*bonus gia megalh omada plakidiwn*/
				cs=cs+2;
				p1[(int)str[2]-49][(int)str[4]-49]='.';
				p1[(int)str[2]-49][(int)str[4]-1-49]='.';
				p1[(int)str[2]-49][(int)str[4]+1-49]='.';
				p1[(int)str[2]-1-49][(int)str[4]+1-49]='.';
				p1[(int)str[2]-1-49][(int)str[4]-49]='.';
				p1[(int)str[2]-1-49][(int)str[4]-1-49]='.';
				gravity();
				printarray();
			}
			else if((int)str[4]-1<=48)
			{
				/*an uparxoun hdh koukides*/
		 		if(p1[(int)str[2]-49][(int)str[4]-49]=='.' && p1[(int)str[2]-1-49][(int)str[4]-49]=='.' && p1[(int)str[2]-1-49][(int)str[4]+1-49]=='.' && p1[(int)str[2]-49][(int)str[4]+1-49]=='.' && p1[(int)str[2]+1-49][(int)str[4]+1-49]=='.' && p1[(int)str[2]+1-49][(int)str[4]-49]=='.')
				{
					printf("Theese boxes do not contain any color to bomb.\n");
					counter=0;
					printarray();
					printf("Remaining colors to brake: %d.\n", ((n+adN)*(m+adM)-pingemkouk) );
					continue;
				}
				counter=0;
				for(i=-1;i<2;i++)
				{
					for(j=0;j<2;j++)
					{
						if(p1[(int)str[2]+i-49][(int)str[4]+j-49]!='.')
						{
							counter=counter+1;
							cs=cs+1;		
						}
					}
				}
				/*bonus gia megalh omada plakidiwn*/
				cs=cs+2;
				p1[(int)str[2]-49][(int)str[4]-49]='.';
				p1[(int)str[2]-1-49][(int)str[4]-49]='.';
				p1[(int)str[2]-1-49][(int)str[4]+1-49]='.';
				p1[(int)str[2]-49][(int)str[4]+1-49]='.';
				p1[(int)str[2]+1-49][(int)str[4]+1-49]='.';
				p1[(int)str[2]+1-49][(int)str[4]-49]='.';
				gravity();
				printarray();
			}
		}
	}
	
			/*entolh hammer*/
			else if( (str[0]=='H' || str[0]=='h') && str[1]==' ' && s1<=n+adN+1+48 && str[3]==',' && s2<=m+adM+1+48)
			{
				/*an o xrhsths kanei hammer se teleia*/
				if(p1[s1][s2]=='.')
				{
					printf("There is no color to hammer at theese coordinates.\n");
					printarray();
					counter=0;
				}
				/*an o xrhsths kanei hammer se monaxiko xrwma*/
				/*kentrikh*/
				else if((int)str[2]-1>48 && (int)str[2]+1<=n+adN+48 && (int)str[4]-1>48 && (int)str[4]+1<=m+adM+48 )
				{
					if(p1[s1-1][s2]!=s3 && p1[s1+1][s2]!=s3 && p1[s1][s2-1]!=s3 && p1[s1][s2+1]!=s3)
					{
						printf("The color you tried to hammer is not surrounded by any plate with the same color.\n");
						counter=0;
					}
					else
					{
						prinh=0;
						wombocombo=1;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{
									prinh=prinh+1;
								}
							}
						}
						h=hammer(s1,s2,s3);
						metah=0;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{						  
									metah=metah+1;
								}
							}
						}				
						counter=metah-prinh;
					}
					gravity();
					printarray();
				}
				/*oi tesereis gwniakes*/
				else if((int)str[2]-1<=48 && (int)str[4]-1<=48)
				{
					if(p1[s1+1][s2]!=s3 && p1[s1][s2+1]!=s3)
					{
						printf("The color you tried to hammer is not surrounded by any plate with the same color.\n");
						counter=0;
					}
					else
					{
						prinh=0;
						wombocombo=1;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{
									prinh=prinh+1;
								}
							}
						}
						h=hammer(s1,s2,s3);
						metah=0;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{						  
									metah=metah+1;
								}
							}
						}				
						counter=metah-prinh;
					}
					gravity();
					printarray();
				}
				else if((int)str[2]-1<=48 && (int)str[4]+1>=m+adM+48)
				{
					if(p1[s1+1][s2]!=s3 && p1[s1][s2-1]!=s3)
					{
						printf("The color you tried to hammer is not surrounded by any plate with the same color.\n");
						counter=0;
					}
					else
					{
						prinh=0;
						wombocombo=1;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{
									prinh=prinh+1;
								}
							}
						}
						h=hammer(s1,s2,s3);
						metah=0;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{						  
									metah=metah+1;
								}
							}
						}				
						counter=metah-prinh;
					}
					gravity();
					printarray();
				}
				else if((int)str[2]+1>=n+adN+48 && (int)str[4]+1>=m+adM+48)
				{
					if(p1[s1-1][s2]!=s3 && p1[s1][s2-1]!=s3)
					{
						printf("The color you tried to hammer is not surrounded by any plate with the same color.\n");
						counter=0;
					}
					else
					{
						prinh=0;
						wombocombo=1;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{
									prinh=prinh+1;
								}
							}
						}
						h=hammer(s1,s2,s3);
						metah=0;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{						  
									metah=metah+1;
								}
							}
						}				
						counter=metah-prinh;
					}
					gravity();
					printarray();
				}
				else if((int)str[2]+1>=n+adN+48 && (int)str[4]-1<=48)
				{
					if(p1[s1-1][s2]!=s3 && p1[s1][s2+1]!=s3)
					{
						printf("The color you tried to hammer is not surrounded by any plate with the same color.\n");
						counter=0;
					}
					else
					{
						prinh=0;
						wombocombo=1;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{
									prinh=prinh+1;
								}
							}
						}
						h=hammer(s1,s2,s3);
						metah=0;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{						  
									metah=metah+1;
								}
							}
						}				
						counter=metah-prinh;
					}
					gravity();
					printarray();
				}
				/*oi tesereis mh gwniakes*/
				else if((int)str[2]-1<=48)
				{
					if(p1[s1+1][s2]!=s3 && p1[s1][s2-1]!=s3 && p1[s1][s2+1]!=s3)
					{
						printf("The color you tried to hammer is not surrounded by any plate with the same color.\n");
						counter=0;
					}
					else
					{
						prinh=0;
						wombocombo=1;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{
									prinh=prinh+1;
								}
							}
						}
						h=hammer(s1,s2,s3);
						metah=0;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{						  
									metah=metah+1;
								}
							}
						}				
						counter=metah-prinh;
					}
					gravity();
					printarray();
				}
				else if((int)str[4]+1>=m+adM+48)
				{
					if(p1[s1-1][s2]!=s3 && p1[s1+1][s2]!=s3 && p1[s1][s2-1]!=s3)
					{
						printf("The color you tried to hammer is not surrounded by any plate with the same color.\n");
						counter=0;
					}
					else
					{
						prinh=0;
						wombocombo=1;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{
									prinh=prinh+1;
								}
							}
						}
						h=hammer(s1,s2,s3);
						metah=0;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{						  
									metah=metah+1;
								}
							}
						}				
						counter=metah-prinh;
					}
					gravity();
					printarray();
				}
				else if((int)str[2]+1>=n+adN+48)
				{
					if(p1[s1-1][s2]!=s3 && p1[s1][s2-1]!=s3 && p1[s1][s2+1]!=s3)
					{
						printf("The color you tried to hammer is not surrounded by any plate with the same color.\n");
						counter=0;
					}
					else
					{
						prinh=0;
						wombocombo=1;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{
									prinh=prinh+1;
								}
							}
						}
						h=hammer(s1,s2,s3);
						metah=0;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{						  
									metah=metah+1;
								}
							}
						}				
						counter=metah-prinh;
					}
					gravity();
					printarray();
				}
				else if((int)str[4]-1<=48)
				{
					if(p1[s1-1][s2]!=s3 && p1[s1+1][s2]!=s3 && p1[s1][s2+1]!=s3)
					{
						printf("The color you tried to hammer is not surrounded by any plate with the same color.\n");
						counter=0;
					}
					else
					{
						prinh=0;
						wombocombo=1;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{
									prinh=prinh+1;
								}
							}
						}
						h=hammer(s1,s2,s3);
						metah=0;
						for(i=0;i<n+adN;i++)
						{
							for(j=0;j<m+adM;j++)
							{
								if(p1[i][j]=='.')
								{						  
									metah=metah+1;
								}
							}
						}				
						counter=metah-prinh;
					}
					gravity();
					printarray();
				}	
			}
		
		/*entolh push left*/
    else if(str[0]=='p' && str[1]=='l' && str[2]=='\n')
    {
    	flag=0;
    	alloj=0;
    	for(j=0;j<m+adM;j++)
    	{
    		for(i=0;i<n+adN;i++)
        {
        	if(p1[i][j]=='.')
          {
          	flag=1;
          }
          else if(p1[i][j]!='.')
          {
            flag=0;
          }
        }
        if(flag==1)
        {
        	alloj=j;
          break;
       	}
      }
      if(flag==0)
      {
      	printf("There are not any empty columns to push.\n");
      }
		  if(flag==1)
		  {
		  	do
		  	{
		  		/*poses einai oi gemates sthles*/
					met=0;
					for(g=0;g<=m+adM-1;g++)
					{
						if(p1[n+adN-1][g]!='.')
						{
							met=met+1;
						}
					}
					/*antimetathesh stoixeiwn*/
					for(i=0;i<n+adN;i++)
				  {
				   	for(j=alloj;j<m+adM;j++)
				    {
				       if(j+1<m+adM && p1[i][j]=='.')
				       {
								 temp=p1[i][j];
						  	 p1[i][j]=p1[i][j+1];
						     p1[i][j+1]=temp;
				       } 
				    }
					}
					/*poses sthles adiasan apo deksia pros ta aristera*/
					met2=0;
					for(g=m+adM-1;g>=met;g--)
					{
						if(p1[n+adN-1][g]=='.')
						{
							met2=met2+1;
						}
					}					
				}while(met2 != m+adM-met);
			}
      printarray();
      counter=0;
    }
                     
		/*entolh push right*/
    else if(str[0]=='p' && str[1]=='r' && str[2]=='\n')
    {
    	flag=0;
    	alloj=0;
    	for(j=m+adM-1;j>=0;j--)
    	{
    		for(i=0;i<n+adN;i++)
        {
        	if(p1[i][j]=='.')
          {
          	flag=1;
          }
          else if(p1[i][j]!='.')
          {
            flag=0;
          }
        }
        if(flag==1)
        {
        	alloj=j;
          break;
       	}
      }
      if(flag==0)
      {
      	printf("There are not any empty columns to push.\n");
      }
		  if(flag==1)
		  {
		  	do
		  	{
		  		/*poses einai oi gemates sthles*/
					met=0;
					for(g=0;g<=m+adM-1;g++)
					{
						if(p1[n+adN-1][g]!='.')
						{
							met=met+1;
						}
					}
					/*antimetathesh stoixeiwn*/
					for(i=0;i<n+adN;i++)
				  {
				   	for(j=alloj;j>0;j--)
				    {
				       if(j-1>=0 && p1[i][j]=='.')
				       {
								 temp=p1[i][j];
						  	 p1[i][j]=p1[i][j-1];
						     p1[i][j-1]=temp;
				       } 
				    }
					}
					/*poses sthles adiasan apo aristera pros ta deksia*/
					met2=0;
					for(g=0;g<=m+adM-1-met;g++)
					{
						if(p1[n+adN-1][g]=='.')
						{
							met2=met2+1;
						}
					}
				}while(met2 != m+adM-met);
			}
      printarray();
      counter=0;
    }
    
		/*entolh add*/
		else if( (str[0]=='A' || str[0]=='a') && str[1]==' ' && (int)str[2]<=n+adN+1+48 && str[3]==',' && (int)str[4]<=m+adM+1+48 && str[5]==' ' )
		{
			if(str[6]==48)
			{
				printf("Please add a color from 1 to 9 at a plate.\n");
				counter=0;
				printarray();
				continue;
			}
			else if((int)str[6]-48<=(int)c[1]-48 && str[7]=='\n')
			{
				if(p1[(int)str[2]-49][(int)str[4]-49]=='.')
				{
					p1[(int)str[2]-49][(int)str[4]-49]=(int)str[6]-48;
					counter=-1;
					gravity();
					printarray();
				}
				else if(p1[(int)str[2]-49][(int)str[4]-49]!='.')
				{
					printf("Theese coordinates already contain a color\n");
					printarray();
				}
			}
			else
			{
				printf("Please add a color from 1 to 9 at a plate.\n");
				counter=0;
				printarray();
				continue;
			}
		}

		/*exit*/
		else if(str[0]=='X' || str[0]=='x')
		{
			return 0;
		}
		
		/*lathos entolh*/
		else
		{
			printf("Please enter a valid command.\n");
			counter=0;
			printarray();			
		}
		
  	/*elegxos gia ton an o pinakas gemise koukides*/
  	pingemkouk=pingemkouk+counter;
  	
  	printf("Remaining colors to brake: %d.\n", ((n+adN)*(m+adM)-pingemkouk) );
  	/*afkshsh diastashs kata 1 gia kathe epomeno epipedo kai epomena levels*/
  	l=1;	
  	if(pingemkouk==(n+adN)*(m+adM))
  	{
  		l=0;
  		level=level+1;
			if(n>2 && n<9)
			{
				adN=adN+1;
			}
			if(m>2 && m<9)
			{
				adM=adM+1;
			}
  	}
	}while( (pingemkouk!=(n+adN)*(m+adM)) && ((n+adN)!=maxrow+1) && ((m+adM)!=maxcol+1) );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	/*free p1*/
	for(i=0;i<n;i++)
	{
		free(p1[i]);
	}
	free(p1);
	
	/*score*/
	if(level==0)
	{
		printf("Levels you passed:%d\n",level);
		printf("Score you acquired:%f\n",score);
	}
	else if(level>0)
	{
		printf("Levels you passed:%d\n",level);
		printf("Score you acquired:%f\n",score);
	}
	printf("%d\n",pingemkouk);
	printf("You won! :)\n");	
			
	return 0;                                                               
}

	
	
/*Ektupwsh pinaka*/
void printarray(void)
{
  int i,j;
	printf("   ");
	for(i=1;i<=m+adM;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for(i=0;i<=((m+adM)+((m+adM)-2)+3);i++)
	{
	  printf("-");
	}
	printf("\n");
	for(i=0;i<n+adN;i++)
	{
	  printf("%d|",i+1);
	  for(j=0;j<m+adM;j++)
	  {
	      if (p1[i][j] == '.')
	      {
	      	printf(" %c", '.');
	      }
	      else
	      {
	      	printf(" %d",(int)p1[i][j]);
	      }
	  }
	  printf("\n");
	}
}



/*peftoun ta xrwmata kai anebainoun oi telitses (varuthta)*/
void gravity(void)
{
  int i,j,k;
	for(k=0;k<n+adN;k++)
	{
		for(i=0;i<n+adN-1;i++)
		{
			for(j=0;j<m+adM;j++)
			{
				if(p1[i+1][j]=='.')
				{
					p1[i+1][j]=p1[i][j];
					p1[i][j]='.';
				}    
			}
		}
	}	
}	




/*hammer*/
int hammer(int s1,int s2,char s3)
{
	/*elegxoume oria pinaka*/
  if(s1<0 || s1>n+adN-1 || s2<0 || s2>m+adM-1)
  {
  	return 1;
  }
  /*mexri na mhn vrei allo ston stavro*/
	if(p1[s1][s2]!=s3)
		{
		  return 1;
		}
	/*gemizoume thn diadromh ektos apo to arxiko plakidio me teleies*/
	p1[s1][s2]='.';
	wombocombo=1.1;
	cs=(cs+1)*wombocombo;
	/*panw*/
	if(hammer(s1,s2-1,s3)==0)
		{
		  return 0;
		}
	/*deksia*/
	if(hammer(s1,s2+1,s3)==0)
		{
		  return 0;
		}
	/*aristera*/	
	if(hammer(s1-1,s2,s3)==0)
		{
			return 0;
		}
	/*katw*/
	if(hammer(s1+1,s2,s3)==0)
		{
		  return 0;
		}
	/*gemizoume to arxiko plakidio me teleia*/
	p1[s1][s2]='.';
	return 1;
}





	
