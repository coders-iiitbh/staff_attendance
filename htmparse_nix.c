#include <stdio.h>
#include <string.h>

struct data
{
	
	char ID[10];
	char name[30];
	int date,mth,yr;
	int inpTime;
	int outTime;

};

int cmt=0;
char implines[200][100];
typedef struct data dt;



int readDate(char ch[]);
long readNxtLine(long n);


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
	if(j==1)
	{
		k1=readNxtLine(ftell(fp));
		k1=readNxtLine(k1);
		k1=readNxtLine(k1);
		k1=readNxtLine(k1);
		k1=readNxtLine(k1);

	}

	}
	fclose(fp);
	for(i=0;i<150;i++)
	{
		puts(implines[i]);
	}
	return 0;
}

int readDate(char lines[])
{
	int i=0;
	while(lines[i]!='\0')
	{
		if((lines[i]=='0' || lines[i]=='1' || lines[i]=='2' || lines[i]=='3' || lines[i]=='4' || lines[i]=='5' || lines[i]=='6' || lines[i]=='7' || lines[i]=='8' || lines[i]=='9' ) && lines[++i]=='-' && (lines[i+2]=='0' || lines[i+2]=='1' || lines[i+2]=='2' || lines[i+2]=='3' || lines[i+2]=='4' || lines[i+2]=='5' || lines[i+2]=='6' || lines[i+2]=='7' || lines[i+2]=='8' || lines[i+2]=='9' ) )
		{
			//fprintf(stdout,"%s\n",lines);
			strcpy(implines[cmt++],lines);
			return 1;		
		}
		i++;
	}
}

long readNxtLine(long n)
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
	strcpy(implines[cmt++],lines);
	//printf("%s\n",lines);
	ch=getc(fp);
	return ftell(fp);
	fclose(fp);

}