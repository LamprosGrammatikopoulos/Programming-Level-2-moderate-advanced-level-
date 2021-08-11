/*
Lampros Grammatikopoulos
AM:2022201800038
dit18038@uop.gr


Kwnstantinos Kolotouros
AM:2022201800090
dit18090@uop.gr
*/

/*
LATEX FILE CREATION APP
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define size 1000
#define smallsize 100
#define tinysize 10
char a[size]={'\0'},*lex[tinysize],*as0,*as1,*as2,*as3,*as4,*as5,*as6,*sec[size],*sec2[size],**x0,**x1,**list0=NULL,**list1=NULL;
int kommata=0,counter=0,unc=0,prc=0,flpr=0,f=0,y=0,q=0,flagnt=0,v=0,tablecomma=0,fd=0;
/*metablhtes ths palias save*/
/*int db=0,d1=0,d2=0,d3=0,d22=0;*/
/*h stoiva*/
typedef struct typesettingStack
{
	char tps[12];
	int param1;
	int param2;
	char *text;
	struct typesettingStack *prev;
}tpsStack;
/*metablhtes gia xrhsh stoivas*/
tpsStack *p,*head=NULL,*new_node,*tmp,*tmp1,*curr;
FILE *myfile, *mystream;
/*sunarthseis*/
char *strcasestr(const char *s, const char *find);
void add_stack(void);
void undo(void);
void print(tpsStack*);
void show(void);
void load(void);
void save(tpsStack*);
int newTitle(void);
int newAuthor(void);
int newAbstract(void);
int newSection(void);
int newTable(void);
int newIlist(void);
int newElist(void);
int main(void)
{
	int i=0,j=0,c=0,m=0,n=0,w=0,thesh=0;
	/*dhmiourgia stoivas*/
	p=(tpsStack*)malloc(sizeof(tpsStack));
	if(p==NULL)
	{
		printf("Error: Not availiable memory.\n");
		return 0;
	}
	do
	{
		/*newTitle kai newAuthor na mporoun na ksanampoun an adeiasoume thn stoiva*/
		if(unc==0)
		{
			m=0;
			n=0;
			flagnt=0;	
		}
		/*an kanoume undo mexri na adeiasei h stoiva kai valoume pali kapoia entolh*/
		if(fd==1)
		{
			p=(tpsStack*)malloc(sizeof(tpsStack));
		}
		/*adiazoume kathe fora ton pinaka alfarithmhtikwn*/
		for(i=0;i<size;i++)
		{
			a[i]='\0';
		}
		/*pernoume thn entolh tou xrhsth*/
		/*----------TA X KAI Y SE OLES TIS SUNARTHSEIS PREPEI NA PERIEXONTAI STO [0,9]----------*/
		/*gia tis upoloipes entoles*/
		if(flagnt==1)
		{
			printf("Give command:\n");
			for(i=0;i<size;i++)
			{
				a[i]=getchar();
				if(a[i]=='\n' || a[i]==EOF)
				{
					break;	
				}
			}
			if(a[0]=='e' && a[1]=='x' && a[2]=='i' && a[3]=='t')
			{
				break;
			}
			if(a[5]==' ')
			{
				flpr=1;
			}
		}
		/*gia na einai h newTitle prwth entolh*/
		if(flagnt==0)
		{
			do
			{
				printf("Give a title:\n");
				for(i=0;i<size;i++)
				{
					a[i]=getchar();
					if(a[i]=='\n' || a[i]==EOF)
					{
						break;	
					}
				}
				if(a[0]=='e' && a[1]=='x' && a[2]=='i' && a[3]=='t')
				{
					break;
				}
			}while(a[0]!='n' || a[1]!='e' || a[2]!='w' || a[3]!='T' || a[4]!='i' || a[5]!='t' || a[6]!='l' || a[7]!='e');
		}
		q=strlen(a);
		flagnt=1;
		/*xwrizoume to alfarithmhtiko sta spaces*/
		lex[0]=strtok(a," ");
		/*newTitle*/
		if(strcmp(lex[0],"newTitle")==0  && m!=1)
		{
			m=newTitle();
			unc=unc+1;
			prc=prc+1;
		}
		/*newAuthor*/
		if(strcmp(lex[0],"newAuthor")==0)
		{
			w=newAuthor();
			unc=unc+1;
			prc=prc+1;
		}
		/*newAbstract*/
		if(strcmp(lex[0],"newAbstract")==0 && n!=1)
		{
			n=newAbstract();
			unc=unc+1;
			prc=prc+1;
		}
		/*newSection*/
		if(strcmp(lex[0],"newSection")==0)
		{
			w=newSection();
			unc=unc+1;
			prc=prc+1;
		}
		/*newTable*/
		if(strcmp(lex[0],"newTable")==0)
		{
			w=newTable();
			unc=unc+1;
			prc=prc+1;
		}
		/*newIlist*/
		if(strcmp(lex[0],"newIlist")==0)
		{
			w=newIlist();
			unc=unc+1;
			prc=prc+1;
		}
		/*newElist*/
		if(strcmp(lex[0],"newElist")==0)
		{
			w=newElist();
			unc=unc+1;
			prc=prc+1;
		}
		/*undo*/
		if(a[0]=='u' && a[1]=='n' && a[2]=='d' && a[3]=='o')
		{
			undo();
		}
		/*print*/
		if(a[0]=='p' && a[1]=='r' && a[2]=='i' && a[3]=='n' && a[4]=='t')
		{
			/*elegxos an uparxei x*/
			if(flpr==0)
			{
				printf("Please give a valid command.\n");
			}
			else
			{
				print(head);
			}
		}
		/*show*/
		if(a[0]=='s' && a[1]=='h' && a[2]=='o' && a[3]=='w')
		{
			show();
		}
		/*load*/
		if(a[0]=='l' && a[1]=='o' && a[2]=='a' && a[3]=='d')
		{
			load();
		}
		/*save*/
		if(a[0]=='s' && a[1]=='a' && a[2]=='v' && a[3]=='e')
		{
			lex[1]=strtok(NULL," ");
			lex[1]=strtok(lex[1],"\n");
			strcat(lex[1],".tex");
			myfile=fopen(lex[1],"w");
			if(!myfile)
			{
				printf("Error openning \"myfile\"\n");
			}
			else
			{
				printf("\"myfile\" openned successfully\n");
				if(myfile==NULL)
				{
					fprintf(stdout,"Problem openning the file.\n");
				}
				else
				{
					fprintf(myfile,"\\documentclass{article}\n");
					save(head);
					fprintf(myfile,"\\end{document}\n");
				}
			}
			/*kleinoume to arxeio*/
			fclose(myfile);
		}
		/*mhdenismos metablhtwn*/
		kommata=0;
		flpr=0;
	}while(a[0]!='e' || a[1]!='x' || a[2]!='i' || a[3]!='t');
	/*kanoume free gia ola ta periexomena twn nodes ths stoivas*/
	p=head;
	while(p!=NULL)
	{
		if(strcmp(p->tps,"newTitle"))
		{
			free(as0);
		}
		else if(strcmp(p->tps,"newAuthor"))
		{
			free(as1);
		}
		else if(strcmp(p->tps,"newAbstract"))
		{
			free(as2);
		}
		else if(strcmp(p->tps,"newSection"))
		{
			free(x0);
			free(as3);
		}
		else if(strcmp(p->tps,"newTable"))
		{
			for(i=0;i<(new_node->param1);i++)
			{
				free(x1[i]);
			}
			free(x1);
			free(as4);
		}
		else if(strcmp(p->tps,"newIlist"))
		{
			free(as5);
			free(list0);
		}
		else if(strcmp(p->tps,"newElist"))
		{
			free(as6);
			free(list1);
		}
		p=p->prev;
	}
	/*kanoume free gia ola ta nodes ths stoivas*/
	p=head;
	while(p!=NULL)
	{
		if(strcmp(p->tps,"newTitle"))
		{
			free(p);
		}
		else
		{
			free(new_node);
		}
		p=p->prev;
	}
	return 0;
}
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/



/*newTitle*/
int newTitle(void)
{
	int i,h,e=0;
	/*mhdenizoume to text ths entolhs thn prwth fora meta apo mhdenismo ths stoivas*/
	for(i=0;i<12;i++)
	{
		p->tps[i]='\0';
	}
	/*xwrizoume to alfarithmhtiko sta spaces*/
	for(i=1;i<2;i++)
	{
		lex[i]=strtok(NULL," ");			
	}
	/*ftiaxnoume to string gia to *text*/
	h=strlen(lex[1]);
	as0=(char *)malloc(h*sizeof(char));
	for(i=q-h;i<q-1;i++)
	{
		as0[e]=a[i];		
		e=e+1;	
	}
	/*antigrafoume apo to megalo string a[size] thn entolh tou xrhsth sto tps[12]*/
	for(i=0;i<8;i++)
	{
		p->tps[i]=a[i];			
	}
	/*antigrafoume apo to megalo string a[size] ta x,y sta param1,param2*/
	p->param1=0;
	p->param2=0;
	/*antigrafoume apo to megalo string a[size] to keimeno sto *text*/
	p->text=as0;
	/*dhmiourgia ths stoivas*/
	add_stack();
	/*pernoume thn thn arxh tou struct*/
	tmp=head;
	/*otan ektelestei mia fora h entolh newTitle to m ginetai 1*/
	return 1;
}



/*newAuthor*/
int newAuthor(void)
{
	int i,h,e=0;
	/*dhmiourgia ths stoivas*/
	add_stack();
	/*mhdenizoume to text ths entolhs thn prwth fora meta apo mhdenismo ths stoivas*/
	for(i=0;i<12;i++)
	{
		p->tps[i]='\0';
	}
	/*xwrizoume to alfarithmhtiko sta spaces*/
	for(i=1;i<2;i++)
	{
		lex[i]=strtok(NULL," ");			
	}
	/*ftiaxnoume to string gia to *text*/
	h=strlen(lex[1]);
	as1=(char *)malloc(h*sizeof(char));
	for(i=q-h;i<q-1;i++)
	{
		as1[e]=a[i];		
		e=e+1;	
	}
	/*antigrafoume apo to megalo string a[size] thn entolh tou xrhsth sto tps[12]*/
	for(i=0;i<9;i++)
	{
		new_node->tps[i]=a[i];			
	}
	/*antigrafoume apo to megalo string a[size] ta x,y sta param1,param2*/
	new_node->param1=0;
	new_node->param2=0;
	/*antigrafoume apo to megalo string a[size] to keimeno sto *text*/
	new_node->text=as1;
	return 0;
}



/*newAbstract*/
int newAbstract(void)
{
	int i,h,e=0;
	/*dhmiourgia ths stoivas*/
	add_stack();
	/*mhdenizoume to text ths entolhs thn prwth fora meta apo mhdenismo ths stoivas*/
	for(i=0;i<12;i++)
	{
		p->tps[i]='\0';
	}
	/*xwrizoume to alfarithmhtiko sta spaces*/
	for(i=1;i<2;i++)
	{
		lex[i]=strtok(NULL," ");			
	}
	/*ftiaxnoume to string gia to *text*/
	h=strlen(lex[1]);
	as2=(char *)malloc(h*sizeof(char));
	for(i=q-h;i<q-1;i++)
	{
		as2[e]=a[i];		
		e=e+1;	
	}
	/*antigrafoume apo to megalo string a[size] thn entolh tou xrhsth sto tps[12]*/
	for(i=0;i<11;i++)
	{
		new_node->tps[i]=a[i];			
	}
	/*antigrafoume apo to megalo string a[size] ta x,y sta param1,param2*/
	new_node->param1=0;
	new_node->param2=0;
	/*antigrafoume apo to megalo string a[size] to keimeno sto *text*/
	new_node->text=as2;
	/*otan ektelestei mia fora h entolh newAbstract to n ginetai 1*/
	return 1;
}



/*newSection*/
int newSection(void)
{
	int i,aber=0,h,e=0;
	char **x;
	/*dimiourgia pinaka gia abersan*/
	x0=(char**)malloc(10*sizeof(char*));
	if(x0==NULL)
	{
		return 0;
	}
	/*xwrizoume to alfarithmhtiko sta spaces*/
	for(i=1;i<3;i++)
	{
		lex[i]=strtok(NULL," ");		
	}
	/*elegxos gia x*/
	if(a[11]<'0' || a[11]>'9')
	{
		printf("Please enter a valid command.\n");
		return 0;
	}
	/*ftiaxnoume to string gia to *text*/
	h=strlen(lex[2]);
	as3=(char *)malloc(h*sizeof(char));
	for(i=q-h;i<q-1;i++)
	{
		as3[e]=a[i];		
		e=e+1;	
	}
	if(atoi(lex[1])==1 || atoi(lex[1])==2 || atoi(lex[1])==3)
	{
		/*elegxos an uparxoun &*/	
		if(strchr(lex[2],'&')!=NULL)
		{
			/*dhmiourgia ths stoivas*/
			add_stack();
			/*mhdenizoume to text ths entolhs thn prwth fora meta apo mhdenismo ths stoivas*/
			for(i=0;i<12;i++)
			{
				p->tps[i]='\0';
			}
			/*kratame enan deikth sthn thesh mesa sthn stoiva tou newSection gia thn ulopoihsh tou subSection*/
			tmp1=head;
			/*antigrafoume apo to megalo string a[size] to keimeno sto *text*/
			new_node->text=as3;
			/*elegxos gia ton arithmo twn &*/
			for(i=14;i<size;i++)
			{
				if(a[i]=='\n')
				{
					break;
				}
				else if(a[i]=='&')
				{
					aber=aber+1;
				}
			}
			/*xwrizoume to text sta &*/
			x0[0]=strtok(lex[2],"&");
			x0[1]=strtok(NULL,"&");
			/*antigrafoume apo to megalo string a[size] ta x,y sta param1,param2*/
			new_node->param1=atoi(lex[1]);
			new_node->param2=0;
			/*antigrafoume apo to megalo string a[size] thn entolh tou xrhsth sto tps[12]*/
			for(i=0;i<10;i++)
			{
				new_node->tps[i]=a[i];
			}
		}
		else
		{
			printf("Please give a title and a text that are connected with &.\n");
		}
	}
	else
	{
		printf("Please give a number between [1-3].\n");	
	}
	return 0;
}



/*newTable*/
int newTable(void)
{
	int i,j,k=0,c=0,f=0,h,e=0;
	/*xwrizoume to alfarithmhtiko sta spaces*/
	lex[1]=strtok(NULL," ");
	/*elegxos gia x*/
	if(a[9]<'0' || a[9]>'9')
	{
		printf("Please enter a valid command.\n");
		return 0;
	}
	lex[2]=strtok(NULL," ");
	/*elegxos gia y*/
	if(a[11]<'0' || a[11]>'9')
	{
		printf("Please enter a valid command.\n");
		return 0;
	}
	lex[3]=strtok(NULL," ");
	/*ftiaxnoume to string gia to *text*/
	h=strlen(lex[3]);
	as4=(char *)malloc(h*sizeof(char));
	for(i=q-h;i<q-1;i++)
	{
		as4[e]=a[i];		
		e=e+1;	
	}
	/*metrame ta kommata sto string*/
	for(i=13;i<size;i++)
	{
		if(a[i]=='\n')
		{
			break;
		}
		else if(a[i]==',')
		{
			kommata=kommata+1;
		}
	}
	if( (atoi(lex[1])*atoi(lex[2])-1)!=kommata )
	{
		printf("Please enter a valid command.\n");
		return 0;
	}
	/*dhmiourgia ths stoivas*/
	add_stack();
	/*mhdenizoume to text ths entolhs thn prwth fora meta apo mhdenismo ths stoivas*/
	for(i=0;i<12;i++)
	{
		p->tps[i]='\0';
	}
	/*antigrafoume apo to megalo string a[size] thn entolh tou xrhsth sto tps[12]*/
	for(i=0;i<8;i++)
	{
		new_node->tps[i]=a[i];			
	}
	/*antigrafoume apo to megalo string a[size] ta x,y sta param1,param2*/
	new_node->param1=atoi(lex[1]);
	new_node->param2=atoi(lex[2]);
	x1=(char**)malloc(new_node->param1*sizeof(char*));
	if(x1==NULL)
	{
		return 0;
	}
	for(i=0;i<(new_node->param1);i++)
	{
		x1[i]=(char*)malloc((new_node->param2*new_node->param1)*sizeof(char));
		if(x1[i]==NULL)
		{
			return 0;
		}
	}
	/*midenismos x[i][j]*/
	for(i=0;i<(new_node->param1);i++)
	{
		for(j=0;j<(new_node->param2);j++)
		{
			x1[i][j]='\0';
		}
	}
	/*antigrafoume apo to megalo string a[size] to keimeno sto *text*/
	new_node->text=as4;
	/*pername ola ta stoixeia tou text ston pinaka pou dhmiourghsame apo ta x kai y*/
  k=13;
	for(i=0;i<(new_node->param1);i++)
	{			
		for(j=0;j<(new_node->param2);j++)
		{
			k=13+c;
			c=c+1;
			if(a[k]!=',')
			{
				if(a[k]!='\n')
				{
					x1[i][j]=a[k];
				}
				else
				{
					x1[i][j]='\0';
				}
				tablecomma=tablecomma+1;		
			}
			else if(a[k]==',')
			{
				if(tablecomma<=new_node->param2)
				{
					tablecomma=0;
					x1[i][j]=a[k+1];
					c=c+1;
				}
				else
				{
					tablecomma=0;
					printf("Please enter elements in table not greater than table's y dimension.\n");
					return 0;
				}
			}
		}
	}
	return 0;
}



/*newIlist*/
int newIlist(void)
{
	int i,h,e=0;
	/*xwrizoume to alfarithmhtiko sta spaces*/
	for(i=1;i<3;i++)
	{
		lex[i]=strtok(NULL," ");		
	}
	/*elegxos gia x*/
	if(a[9]<'0' || a[9]>'9')
	{
		printf("Please enter a valid command.\n");
		return 0;
	}
	/*ftiaxnoume to string gia to *text*/
	h=strlen(lex[2]);
	as5=(char *)malloc(h*sizeof(char));
	for(i=q-h;i<q-1;i++)
	{
		as5[e]=a[i];		
		e=e+1;	
	}
	/*metrame ta kommata sto string*/
	for(i=11;i<size;i++)
	{
		if(a[i]=='\n')
		{
			break;
		}
		else if(a[i]==',')
		{
			kommata=kommata+1;
		}
	}
	if(kommata!=(atoi(lex[1])-1))
	{
		printf("Please enter a valid command.\n");
		return 0;
	}
	/*dhmiourgia ths stoivas*/
	add_stack();
	/*mhdenizoume to text ths entolhs thn prwth fora meta apo mhdenismo ths stoivas*/
	for(i=0;i<12;i++)
	{
		p->tps[i]='\0';
	}
	/*antigrafoume apo to megalo string a[size] thn entolh tou xrhsth sto tps[12]*/
	for(i=0;i<8;i++)
	{
		new_node->tps[i]=a[i];			
	}
	/*antigrafoume apo to megalo string a[size] ta x,y sta param1,param2*/
	new_node->param1=atoi(lex[1]);
	new_node->param2=0;
	/*ftiaxnoume thn mh arithmhmenh lista*/
	lex[0]=strtok(a," ");
	for(i=1;i<atoi(lex[2]);i++)
	{
		lex[i]=strtok(NULL," ");
	}
	list0=(char **)malloc(atoi(lex[1])*sizeof(char*));
	if(list0==NULL)
	{
		return 0;
	}
	list0[0]=strtok(lex[2],",");
	for(i=1;i<atoi(lex[1]);i++)
	{
		list0[i]=strtok(NULL,",");
	}
	/*antigrafoume apo to megalo string a[size] to keimeno sto *text*/
	new_node->text=as5;
	return 0;
}



/*newElist*/
int newElist(void)
{
	int i,j,c=1,h,e=0;
	/*xwrizoume to alfarithmhtiko sta spaces*/
	for(i=1;i<3;i++)
	{
		lex[i]=strtok(NULL," ");	
	}
	/*elegxos gia x*/
	if(a[9]<'0' || a[9]>'9')
	{
		printf("Please enter a valid command.\n");
		return 0;
	}
	/*ftiaxnoume to string gia to *text*/
	h=strlen(lex[2]);
	as6=(char *)malloc(h*sizeof(char));
	for(i=q-h;i<q-1;i++)
	{
		as6[e]=a[i];		
		e=e+1;	
	}
	/*metrame ta kommata sto string*/
	for(i=11;i<size;i++)
	{
		if(a[i]=='\n')
		{
			break;
		}
		else if(a[i]==',')
		{
			kommata=kommata+1;
		}
	}
	if(kommata!=(atoi(lex[1])-1))
	{
		printf("Please enter a valid command.\n");
		return 0;
	}
	/*dhmiourgia ths stoivas*/
	add_stack();
	/*mhdenizoume to text ths entolhs thn prwth fora meta apo mhdenismo ths stoivas*/
	for(i=0;i<12;i++)
	{
		p->tps[i]='\0';
	}
	/*antigrafoume apo to megalo string a[size] thn entolh tou xrhsth sto tps[12]*/
	for(i=0;i<8;i++)
	{
		new_node->tps[i]=a[i];			
	}
	/*antigrafoume apo to megalo string a[size] ta x,y sta param1,param2*/
	new_node->param1=atoi(lex[1]);
	new_node->param2=0;
	/*ftiaxnoume thn mh arithmhmenh lista*/
	lex[0]=strtok(a," ");
	for(i=1;i<atoi(lex[2]);i++)
	{
		lex[i]=strtok(NULL," ");
	}
	list1=(char**)malloc(atoi(lex[1])*sizeof(char*));
	list1[0]=strtok(lex[2],",");
	/*antigrafoume apo to megalo string a[size] to keimeno sto *text*/
	new_node->text=as6;
	return 0;
}



/*add_stack*/
void add_stack(void)
{
	new_node=(tpsStack*)malloc(sizeof(tpsStack));
	if(new_node==NULL)
	{
		printf("Error: Not availiable memory.\n");
		exit(EXIT_FAILURE);
	}
	*new_node=*p;
	new_node->prev=head;
	head=new_node;
}



/*undo*/
void undo(void)
{
	if(unc>0)
	{
		new_node=head;
		head=head->prev;
		free(new_node);
		if(unc==1)
		{
			fd=1;
		}
		unc=unc-1;
	}
	else
	{
		printf("You can not undo a command while the stack it is empty.\n");
	}
	p=head;	
}



/*print*/
void print(tpsStack *current)
{
	/*an o xrhsths edwse space meta apo print*/
	if(flpr==1)
	{
		if(y==0)
		{
			lex[1]=strtok(NULL," ");
			f=atoi(lex[1]);
			y=1;
		}
		/*x megalutero apo periexomena stoivas*/
		if(f>prc)
		{
			if((current!=NULL) && (current->prev==NULL))
			{
				printf("tps[12]:(%s) param1:(%d) param2:(%d) text:(%s)\n",current->tps,current->param1,current->param2,current->text);
			}
			else if(current!=NULL)
			{
				print(current->prev);
				printf("tps[12]:(%s) param1:(%d) param2:(%d) text:(%s)\n",current->tps,current->param1,current->param2,current->text);
			}
		}
		/*x mikrotero h iso apo periexomena stoivas*/
		else if(f<=prc && f>0)
		{
			if((current!=NULL) && (current->prev==NULL))
			{
				printf("tps[12]:(%s) param1:(%d) param2:(%d) text:(%s)\n",current->tps,current->param1,current->param2,current->text);
				f=f-1;
				v=1;
			}
			else if(current!=NULL && f>0)
			{
				print(current->prev);
				if(v==1 && f>0)
				{
					printf("tps[12]:(%s) param1:(%d) param2:(%d) text:(%s)\n",current->tps,current->param1,current->param2,current->text);
					f=f-1;
				}
			}
		}
	}
	y=0;
}



/*show*/
void show(void)
{
	lex[1]=strtok(NULL," ");
	lex[2]=strtok(lex[1],"\n");
	p=head;
	while(p!=NULL)
	{
		lex[3]=p->tps;
		if(strcasestr(lex[3],lex[2])!=NULL)
		{
			printf("tps[12]:(%s) param1:(%d) param2:(%d) text:(%s)\n",p->tps,p->param1,p->param2,p->text);
		}
		p=p->prev;
	}
	p=head;
}



/*strcasestr*/
/*Find the first occurrence of find in s, ignore case.*/
char *strcasestr(const char *s, const char *find)
{
	char c, sc;
	size_t len;
	if ((c = *find++)!= 0)
	{
		c = (char)tolower((unsigned char)c);
		len = strlen(find);
		do
		{
			do
			{
				if ((sc = *s++) == 0)
				{
					return (NULL);
				}
			}while ((char)tolower((unsigned char)sc) != c);
		}while (strncasecmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}



/*load*/
void load(void)
{
	int cl=0;
	char *lex2;
	/*Elegxoume an mporei na anoiksei to arxeio*/
	if(!(mystream=fopen("debug.txt","r")))
	{
		printf("Error in openning file.\n");
	}
	/*kovoume thn entolh tou xrhsth*/
	lex[1]=strtok(NULL," ");
	lex[2]=strtok(NULL," ");
	/*diatrexoume to arxeio mexri to telos tou kai vazoume ta swsta periexomena sthn stoiva*/
	while(!feof(mystream))
	{
		lex2=(char *)malloc(size*sizeof(char));
		if(atoi(lex[1])>cl)
		{
			if(lex2==NULL)
			{
				printf("Error: Not availiable memory.\n");
				exit(EXIT_FAILURE);
			}
			fscanf(mystream,"%s\n",lex2);
			if(strcmp(lex2,"\\newTitle")==0)
			{
				unc=unc+1;
				cl=cl+1;
				add_stack();
				fscanf(mystream,"%s\n",lex2);
				new_node->tps[0]='n';
				new_node->tps[1]='e';
				new_node->tps[2]='w';
				new_node->tps[3]='T';
				new_node->tps[4]='i';
				new_node->tps[5]='t';
				new_node->tps[6]='l';
				new_node->tps[7]='e';
				new_node->param1=0;
				new_node->param2=0;
				new_node->text=lex2;
			}
			else if(strcmp(lex2,"\\newAuthor")==0)
			{
				unc=unc+1;
				cl=cl+1;
				add_stack();
				fscanf(mystream,"%s\n",lex2);
				new_node->tps[0]='n';
				new_node->tps[1]='e';
				new_node->tps[2]='w';
				new_node->tps[3]='A';
				new_node->tps[4]='u';
				new_node->tps[5]='t';
				new_node->tps[6]='h';
				new_node->tps[7]='o';
				new_node->tps[8]='r';
				new_node->param1=0;
				new_node->param2=0;
				new_node->text=lex2;
			}
			else if(strcmp(lex2,"\\newAbstract")==0)
			{
				unc=unc+1;
				cl=cl+1;
				add_stack();
				fscanf(mystream,"%s\n",lex2);
				new_node->tps[0]='n';
				new_node->tps[1]='e';
				new_node->tps[2]='w';
				new_node->tps[3]='A';
				new_node->tps[4]='b';
				new_node->tps[5]='s';
				new_node->tps[6]='t';
				new_node->tps[7]='r';
				new_node->tps[8]='a';
				new_node->tps[9]='c';
				new_node->tps[10]='t';
				new_node->param1=0;
				new_node->param2=0;
				new_node->text=lex2;
			}
			else if(strcmp(lex2,"\\newTable")==0)
			{
				unc=unc+1;
				cl=cl+1;
				add_stack();
				fscanf(mystream,"%s\n",lex2);
				new_node->param1=atoi(lex2);
				fscanf(mystream,"%s\n",lex2);
				new_node->param2=atoi(lex2);
				fscanf(mystream,"%s\n",lex2);
				new_node->tps[0]='n';
				new_node->tps[1]='e';
				new_node->tps[2]='w';
				new_node->tps[3]='T';
				new_node->tps[4]='a';
				new_node->tps[5]='b';
				new_node->tps[6]='l';
				new_node->tps[7]='e';
				new_node->text=lex2;
			}
			else if(strcmp(lex2,"\\newSection")==0)
			{
				unc=unc+1;
				cl=cl+1;
				add_stack();
				fscanf(mystream,"%s\n",lex2);
				new_node->param1=atoi(lex2);
				fscanf(mystream,"%s\n",lex2);
				new_node->tps[0]='n';
				new_node->tps[1]='e';
				new_node->tps[2]='w';
				new_node->tps[3]='S';
				new_node->tps[4]='e';
				new_node->tps[5]='c';
				new_node->tps[6]='t';
				new_node->tps[7]='i';
				new_node->tps[8]='o';
				new_node->tps[9]='n';
				new_node->param2=0;
				new_node->text=lex2;
			}	
			else if(strcmp(lex2,"\\newIlist")==0)
			{
				unc=unc+1;
				cl=cl+1;
				add_stack();
				fscanf(mystream,"%s\n",lex2);
				new_node->param1=atoi(lex2);
				fscanf(mystream,"%s\n",lex2);
				new_node->tps[0]='n';
				new_node->tps[1]='e';
				new_node->tps[2]='w';
				new_node->tps[3]='I';
				new_node->tps[4]='l';
				new_node->tps[5]='i';
				new_node->tps[6]='s';
				new_node->tps[7]='t';
				new_node->param2=0;
				new_node->text=lex2;
			}	
			else if(strcmp(lex2,"\\newElist")==0)
			{
				unc=unc+1;
				cl=cl+1;
				add_stack();
				fscanf(mystream,"%s\n",lex2);
				new_node->param1=atoi(lex2);
				fscanf(mystream,"%s\n",lex2);
				new_node->tps[0]='n';
				new_node->tps[1]='e';
				new_node->tps[2]='w';
				new_node->tps[3]='E';
				new_node->tps[4]='l';
				new_node->tps[5]='i';
				new_node->tps[6]='s';
				new_node->tps[7]='t';
				new_node->param2=0;
				new_node->text=lex2;
			}
		}
		else if(atoi(lex[1])<=cl)
		{
			/*free*/
			free(lex2);
			break;
		}
	}
	/*kleinoume to arxeio*/
	fclose(mystream);
}
/******************************************************************************************************************/



/*save*/
void save(tpsStack *current1)
{
	int i,j,g;
			if((current1!=NULL) && (current1->prev==NULL))
			{
				/*newTitle*/
				if(strcmp(current1->tps,"newTitle")==0)
				{
					fprintf(myfile,"\\title{%s}\n",current1->text);
				}
			}
			else if(current1!=NULL)
			{
				save(current1->prev);
				/*newTitle*/
				if(strcmp(current1->tps,"newTitle")==0)
				{	
				  fprintf(myfile,"\\title{%s}\n",current1->text);
				}
				/*newAuthor*/
				else if(strcmp(current1->tps,"newAuthor")==0)
				{
					
					fprintf(myfile,"\\author{%s}\n",current1->text);
					fprintf(myfile,"\n");
					
				}
				/*newAbstract*/
				else if(strcmp(current1->tps,"newAbstract")==0)
				{
				  
				  fprintf(myfile,"\\begin{document}\n");
					fprintf(myfile,"\\maketitle\n");
					fprintf(myfile,"\\abstract{%s}\n",current1->text);
					
				}
				/*mynewSection*/
				else if(strcmp(current1->tps,"newSection")==0)
				{
					sec[0]=strtok(current1->text,"&");
					sec[1]=strtok(NULL,"&");
					if(current1->param1==1)
					{
						fprintf(myfile,"\\section{");
						fprintf(myfile,"%s",sec[0]);
						fprintf(myfile,"}\n");
						fprintf(myfile,"%s\n",sec[1]);
					}
					else if(current1->param1==2)
					{
						fprintf(myfile,"\\subsection{");
						fprintf(myfile,"%s",sec[0]);
						fprintf(myfile,"}\n");
						fprintf(myfile,"%s\n",sec[1]);
					}
					else if(current1->param1==3)
					{
						fprintf(myfile,"\\subsubsection{");
						fprintf(myfile,"%s",sec[0]);
						fprintf(myfile,"}\n");
						fprintf(myfile,"%s\n",sec[1]);
					}
				}
				/*newTable*/
				else if(strcmp(current1->tps,"newTable")==0)
				{
					 	fprintf(myfile,"\\begin{table}\n");
					  fprintf(myfile,"\t \\centering\n");
					  fprintf(myfile,"\t \\begin{tabular}");
					  fprintf(myfile,"{c");
					  for(i=1;i<current1->param2;i++)
					  {
						  fprintf(myfile,"|");
						  fprintf(myfile,"c");
					  }
					  fprintf(myfile,"}\n");
					  sec2[0]=strtok(current1->text,",");
					  for(i=1;i<smallsize;i++)
					  {
						  sec2[i]=strtok(NULL,",");
					  }
					  j=current1->param2;
					 	for(i=0;i<(current1->param1*current1->param2);i++)
					  {
					  	if(i==0)
					  	{
					  		 fprintf(myfile,"\t\t");
					  	}
					  	if(i==j-1)
					  	{
					  		fprintf(myfile,"%s \\\\ \n \t\t",sec2[i]);
					  		j=j+current1->param2;
					  		continue;
					  	}
					  	fprintf(myfile,"%s & ",sec2[i]);
					  }
					  fprintf(myfile,"\\end{tabular}\n");
					  fprintf(myfile,"\\end{table}\n");		
				}
				/*newIlist*/
				else if(strcmp(current1->tps,"newIlist")==0)
				{
					  fprintf(myfile,"\\begin{itemize}\n");
					  sec2[0]=strtok(current1->text,",");
					  for(i=1;i<smallsize;i++)
					  {
						  sec2[i]=strtok(NULL,",");
					  }
					  for(i=0;i<current1->param1;i++)
					  {
						  fprintf(myfile,"\t\\item %s\n",sec2[i]);
					  }
					  fprintf(myfile,"\\end{itemize}\n");
				}
				/*newElist*/
				else if(strcmp(current1->tps,"newElist")==0)
				{
				    fprintf(myfile,"\\begin{enumerate}\n");
					  sec2[0]=strtok(current1->text,",");
					  for(i=1;i<smallsize;i++)
					  {
						  sec2[i]=strtok(NULL,",");
					  }
					  for(i=1;i<=current1->param1;i++)
					  {
						  fprintf(myfile,"\t\\item %d.%s\n",i,sec2[i-1]);
					  }
					  fprintf(myfile,"\\end{enumerate}\n");
				}
		}
}



/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/



/*save_palio
void save(tpsStack *current1)
{
	int i,j,g;
			if((current1!=NULL) && (current1->prev==NULL))
			{
				//newTitle
				if(strcmp(current1->tps,"newTitle")==0)
				{
					fprintf(myfile,"\\title{%s}\n",current1->text);
				}
			}
			else if(current1!=NULL)
			{
				save(current1->prev);
				//newTitle
				if(strcmp(current1->tps,"newTitle")==0)
				{
				if(d1==1 || d22==1)
				{
				  fprintf(myfile,"\\title{%s}\n",current1->text);
				  d1=0;
				 }
				 else if(d2==1 && d22==1)
				 {
					fprintf(myfile,"\\subsection{");
					fprintf(myfile,"%s",sec[2]);
					fprintf(myfile,"}\n");
					fprintf(myfile,"%s\n",sec[3]);;
					fprintf(myfile,"\\title{%s}\n",current1->text);
					d22==0;
					d2=0;
					d1=0;
				  }
				  else if(d3==1)
				  {
				  fprintf(myfile,"\\subsubsection{");
					fprintf(myfile,"%s",sec[4]);
					fprintf(myfile,"}\n");
					fprintf(myfile,"%s\n",sec[5]);
					fprintf(myfile,"\\title{%s}\n",current1->text);
					d3=0;
				  }
				  else
				  {
				  fprintf(myfile,"\\title{%s}\n",current1->text);
				  }
				}
				//newAuthor
				else if(strcmp(current1->tps,"newAuthor")==0)
				{
					if(d1==1)
					{
						fprintf(myfile,"\\author{%s}\n",current1->text);
						fprintf(myfile,"\n");
						d1=0;
					}
					else if(d2==1 && d22==1)
					{
					fprintf(myfile,"\\subsection{");
					fprintf(myfile,"%s",sec[2]);
					fprintf(myfile,"}\n");
					fprintf(myfile,"%s\n",sec[3]);
					fprintf(myfile,"\\author{%s}\n",current1->text);
					fprintf(myfile,"\n");
					d22=0;
					d2=0;
					d1=0;
					}
					else if(d3==1)
					{
					fprintf(myfile,"\\subsubsection{");
					fprintf(myfile,"%s",sec[4]);
					fprintf(myfile,"}\n");
					fprintf(myfile,"%s\n",sec[5]);
					fprintf(myfile,"\\author{%s}\n",current1->text);
					fprintf(myfile,"\n");
					d3=0;
					}
					else
					{
					fprintf(myfile,"\\author{%s}\n",current1->text);
					fprintf(myfile,"\n");
					}
				}
				//newAbstract
				else if(strcmp(current1->tps,"newAbstract")==0)
				{
				  if(d1==1 )
				  {
				  fprintf(myfile,"\\begin{document}\n");
					fprintf(myfile,"\\maketitle\n");
				  fprintf(myfile,"\\abstract{%s}\n",current1->text);
				  d1=0;
				  }
				  else if(d2==1 && d22==1)
				  {
					fprintf(myfile,"\\subsection{");
					fprintf(myfile,"\\begin{document}\n");
					fprintf(myfile,"\\maketitle\n");
					fprintf(myfile,"%s",sec[2]);
					fprintf(myfile,"}\n");
					fprintf(myfile,"%s\n",sec[3]);
				  fprintf(myfile,"\\abstract{%s}\n",current1->text);
				  d22=0;
				  d2=0;
				  d1=0;
				  }
				  else if(d3==1)
				  { 
				  fprintf(myfile,"\\subsubsection{");
				  fprintf(myfile,"\\begin{document}\n");
					fprintf(myfile,"\\maketitle\n");
					fprintf(myfile,"%s",sec[4]);
					fprintf(myfile,"}\n");
					fprintf(myfile,"%s\n",sec[5]);
				  fprintf(myfile,"\\abstract{%s}\n",current1->text);
				  d3=0;
				  }
				  else
				  {
				  fprintf(myfile,"\\begin{document}\n");
					fprintf(myfile,"\\maketitle\n");
					fprintf(myfile,"\\abstract{%s}\n",current1->text);
					}
				}
				//newSection
				else if(strcmp(current1->tps,"newSection")==0)
				{
					sec[0]=strtok(current1->text,"&");
					for(i=1;i<6;i++)
					{
						sec[i]=strtok(NULL,"&");
					}
					fprintf(myfile,"\\section{");
					fprintf(myfile,"%s",sec[0]);
					fprintf(myfile,"}\n");
					fprintf(myfile,"%s\n",sec[1]);
					//gia x=1
					if(current1->param1==1)
					{
						d1=1;
					}
					//gia x=2
					else if(current1->param1==2)
					{
						d2=1;
						d22=1;
						d1=1;	
					}	
					//gia x=3
					else if(current1->param1==3)
					{
						d3=1;
						d2=1;
						d22=1;
						d1=1;
					}
				}
				//newTable
				else if(strcmp(current1->tps,"newTable")==0)
				{
				  if(d1==1 )
				  {
				    fprintf(myfile,"\\begin{table}\n");
					  fprintf(myfile,"\t \\centering\n");
					  fprintf(myfile,"\t \\begin{tabular}");
					  fprintf(myfile,"{c");
					  for(i=1;i<current1->param2;i++)
					  {
						  fprintf(myfile,"|");
						  fprintf(myfile,"c");
					  }
					  fprintf(myfile,"}\n");
					  sec2[0]=strtok(current1->text,",");
					  for(i=1;i<smallsize;i++)
					  {
						  sec2[i]=strtok(NULL,",");
					  }
					 j=current1->param2;
					 	for(i=0;i<(current1->param1*current1->param2);i++)
					  {
					  	if(i==0)
					  	{
					  		 fprintf(myfile,"\t\t");
					  	}
					  	if(i==j-1)
					  	{
					  		fprintf(myfile,"%s \\\\ \n \t\t",sec2[i]);
					  		j=j+current1->param2;
					  		continue;
					  	}
					  	fprintf(myfile,"%s & ",sec2[i]);
					  }
					  fprintf(myfile,"\\end{tabular}\n");
					  fprintf(myfile,"\\end{table}\n");	
					  d1=0;
				  }
				  else if(d2==1 && d22==1)
				  {
						fprintf(myfile,"\\subsection{");
						fprintf(myfile,"%s",sec[2]);
						fprintf(myfile,"}\n");
						fprintf(myfile,"%s\n",sec[3]);
					  fprintf(myfile,"\\begin{table}\n");
					  fprintf(myfile,"\t \\centering\n");
					  fprintf(myfile,"\t \\begin{tabular}");
					  fprintf(myfile,"{c");
					  for(i=1;i<current1->param2;i++)
					  {
						  fprintf(myfile,"|");
						  fprintf(myfile,"c");
					  }
					  fprintf(myfile,"}\n");
					  sec2[0]=strtok(current1->text,",");
					  for(i=1;i<smallsize;i++)
					  {
						  sec2[i]=strtok(NULL,",");
					  }
					  j=current1->param2;
					 	for(i=0;i<(current1->param1*current1->param2);i++)
					  {
					  	if(i==0)
					  	{
					  		 fprintf(myfile,"\t\t");
					  	}
					  	if(i==j-1)
					  	{
					  		fprintf(myfile,"%s \\\\ \n \t\t",sec2[i]);
					  		j=j+current1->param2;
					  		continue;
					  	}
					  	fprintf(myfile,"%s & ",sec2[i]);
					  }
					  fprintf(myfile,"\\end{tabular}\n");
					  fprintf(myfile,"\\end{table}\n");	
					  d2=0;
					  d22=0;	
					  d1=0;
					 }
					 else if(d3==1)
					 {
					 	fprintf(myfile,"\\subsubsection{");
						fprintf(myfile,"%s",sec[4]);
						fprintf(myfile,"}\n");
						fprintf(myfile,"%s\n",sec[5]);
					  fprintf(myfile,"\\begin{table}\n");
					  fprintf(myfile,"\t \\centering\n");
					  fprintf(myfile,"\t \\begin{tabular}");
					  fprintf(myfile,"{c");
					  for(i=1;i<current1->param2;i++)
					  {
						  fprintf(myfile,"|");
						  fprintf(myfile,"c");
					  }
					  fprintf(myfile,"}\n");
					  sec2[0]=strtok(current1->text,",");
					  for(i=1;i<smallsize;i=i+2)
					  {
						  sec2[i]=strtok(NULL,",");
					  }
					   j=current1->param2;
					 	for(i=0;i<(current1->param1*current1->param2);i++)
					  {
					  	if(i==0)
					  	{
					  		 fprintf(myfile,"\t\t");
					  	}
					  	if(i==j-1)
					  	{
					  		fprintf(myfile,"%s \\\\ \n \t\t",sec2[i]);
					  		j=j+current1->param2;
					  		continue;
					  	}
					  	fprintf(myfile,"%s & ",sec2[i]);
					  }
					  fprintf(myfile,"\\end{tabular}\n");
					  fprintf(myfile,"\\end{table}\n");	
					  d3=0;
					 }
					 else
					 {
					 	fprintf(myfile,"\\begin{table}\n");
					  fprintf(myfile,"\t \\centering\n");
					  fprintf(myfile,"\t \\begin{tabular}");
					  fprintf(myfile,"{c");
					  for(i=1;i<current1->param2;i++)
					  {
						  fprintf(myfile,"|");
						  fprintf(myfile,"c");
					  }
					  fprintf(myfile,"}\n");
					  sec2[0]=strtok(current1->text,",");
					  for(i=1;i<smallsize;i++)
					  {
						  sec2[i]=strtok(NULL,",");
					  }
					  j=current1->param2;
					 	for(i=0;i<(current1->param1*current1->param2);i++)
					  {
					  	if(i==0)
					  	{
					  		 fprintf(myfile,"\t\t");
					  	}
					  	if(i==j-1)
					  	{
					  		fprintf(myfile,"%s \\\\ \n \t\t",sec2[i]);
					  		j=j+current1->param2;
					  		continue;
					  	}
					  	fprintf(myfile,"%s & ",sec2[i]);
					  }
					  fprintf(myfile,"\\end{tabular}\n");
					  fprintf(myfile,"\\end{table}\n");	
					 }	
				}
				//newIlist
				else if(strcmp(current1->tps,"newIlist")==0)
				{
				  if(d1==1)
				  {

				    fprintf(myfile,"\\begin{itemize}\n");
					  sec2[0]=strtok(current1->text,",");
					  for(i=1;i<smallsize;i++)
					  {
						  sec2[i]=strtok(NULL,",");
					  }
					  for(i=0;i<current1->param1;i++)
					  {
						  fprintf(myfile,"\t\\item %s\n",sec2[i]);
					  }
					  fprintf(myfile,"\\end{itemize}\n");
					  d1=0;
				  }
				  else if(d2==1 && d22==1)
				  {
						fprintf(myfile,"\\subsection{");
						fprintf(myfile,"%s",sec[2]);
						fprintf(myfile,"}\n");
						fprintf(myfile,"%s\n",sec[3]);
					  fprintf(myfile,"\\begin{itemize}\n");
					  sec2[0]=strtok(current1->text,",");
					  for(i=1;i<smallsize;i++)
					  {
						  sec2 [i]=strtok(NULL,",");
					  }
					  for(i=0;i<current1->param1;i++)
					  {
						  fprintf(myfile,"\t\\item %s\n",sec2[i]);
					  }
					  fprintf(myfile,"\\end{itemize}\n");	
					  d22=0;
					  d2=0;
					  d1=0;
					 }
					 else if(d3==1)
					 {
					 	fprintf(myfile,"\\subsubsection{");
						fprintf(myfile,"%s",sec[4]);
						fprintf(myfile,"}\n");
						fprintf(myfile,"%s\n",sec[5]);
					  fprintf(myfile,"\\begin{itemize}\n");
					  sec2[0]=strtok(current1->text,",");
					  for(i=1;i<smallsize;i++)
					  {
						  sec2[i]=strtok(NULL,",");
					  }
					  for(i=0;i<current1->param1;i++)
					  {
						  fprintf(myfile,"\t\\item %s\n",sec2[i]);
					  }
					  fprintf(myfile,"\\end{itemize}\n");
					  d3=0;
					 }
					 else
					 {
					  fprintf(myfile,"\\begin{itemize}\n");
					  sec2[0]=strtok(current1->text,",");
					  for(i=1;i<smallsize;i++)
					  {
						  sec2[i]=strtok(NULL,",");
					  }
					  for(i=0;i<current1->param1;i++)
					  {
						  fprintf(myfile,"\t\\item %s\n",sec2[i]);
					  }
					  fprintf(myfile,"\\end{itemize}\n");
					 }
				}
				//newElist
				else if(strcmp(current1->tps,"newElist")==0)
				{
				  if(d1==1)
				  {
				    fprintf(myfile,"\\begin{enumerate}\n");
					  sec2[0]=strtok(current1->text,",");
					  for(i=1;i<smallsize;i++)
					  {
						  sec2[i]=strtok(NULL,",");
					  }
					  for(i=1;i<=current1->param1;i++)
					  {
						  fprintf(myfile,"\t\\item %d.%s\n",i,sec2[i-1]);
					  }
					  fprintf(myfile,"\\end{enumerate}\n");	
					  d1=0;
				  }
				  else if(d2==1 && d22==1)
				  {
						fprintf(myfile,"\\subsection{");
						fprintf(myfile,"%s",sec[2]);
						fprintf(myfile,"}\n");
						fprintf(myfile,"%s\n",sec[3]);
					  fprintf(myfile,"\\begin{enumerate}\n");
					  sec2[0]=strtok(current1->text,",");
					  for(i=1;i<smallsize;i++)
					  {
						  sec2[i]=strtok(NULL,",");
					  }
					  for(i=1;i<=current1->param1;i++)
					  {
						  fprintf(myfile,"\t\\item %d.%s\n",i,sec2[i-1]);
					  }
					  fprintf(myfile,"\\end{enumerate}\n");
					  d2=0;
					  d22=0;
					  d1=0;
				  }
				  else if(d3==1)
				  {
				  	fprintf(myfile,"\\subsubsection{");
						fprintf(myfile,"%s",sec[4]);
						fprintf(myfile,"}\n");
						fprintf(myfile,"%s\n",sec[5]);
					  fprintf(myfile,"\\begin{enumerate}\n");
					  sec2[0]=strtok(current1->text,",");
					  for(i=1;i<smallsize;i++)
					  {
						  sec2[i]=strtok(NULL,",");
					  }
					  for(i=1;i<=current1->param1;i++)
					  {
						  fprintf(myfile,"\t\\item %d.%s\n",i,sec2[i-1]);
					  }
					  fprintf(myfile,"\\end{enumerate}\n");
					  d3=0;
				  }
				  else
				  {
				    fprintf(myfile,"\\begin{enumerate}\n");
					  sec2[0]=strtok(current1->text,",");
					  for(i=1;i<smallsize;i++)
					  {
						  sec2[i]=strtok(NULL,",");
					  }
					  for(i=1;i<=current1->param1;i++)
					  {
						  fprintf(myfile,"\t\\item %d.%s\n",i,sec2[i-1]);
					  }
					  fprintf(myfile,"\\end{enumerate}\n");
				  }
				}
			}
}
*/








