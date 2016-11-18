#include <stdio.h>
#include <string.h>

struct data
{
	
	char ID[10];
	char name[30];
	int date,mth,yr;

};

int cmt=0;
char implines[200][100];
typedef struct data dt;



int readDate(char ch[]);
void readNxtLine(long n);
void readTime(long n );


int main()
{
	FILE *fp;

	fp=fopen("Programme.html","r");
	char lines[5000],ch;
	int i=0,j;
	long k1;
	ch=getc(fp);
	while(ch!=EOF)
	{
		i=0;
		while(ch!='\n')
		{
			lines[i++]=ch;
			ch=getc(fp);
			if(ch==EOF)
				break;
		}
		lines[i]='\0';
		if(ch==EOF)
			break;
		j=readDate(lines);
		ch=getc(fp);
		//if(j==1)
		//{
	//		readNxtLine(ftell(fp));
	//		break;
	//	}

	}
	fclose(fp);
	return 0;
}

int readDate(char lines[])
{
	int i=0;
	while(lines[i]!='\0')
	{
		if(lines[i]=='2' && lines[++i]=='-')
		{
			fprintf(stdout,"%s\n",lines);
			//strcpy(implines[cmt++],lines);
			return 1;		
		}
		i++;
	}
}

/*void readNxtLine(long n)
{
	FILE *fp;
	fp=fopen("Programme.html","r");
	fseek(fp,n,0);
	int i=0;
	char ch,lines[5000];
	ch=getc(fp);
	while(ch!='\n')
	{
		lines[i++]=ch;
        ch=getc(fp);
        if (ch == EOF)
       	    break;
	}
	lines[i]='\0';
	//strcpy(implines[cmt++],lines);
	printf("%s\n",lines);
	fclose(fp);
}*/