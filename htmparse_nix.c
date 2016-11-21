#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct data
{
	
	char stat[5];// TO STORE THE STATUS OF THE DAY 
	char name[30];// TO STORE THE NAME AND ID
	char date[15];// TO STORE THE DATE
	char inpTime[20];// TO STORE THE INPUT TIME
	char toTime[20];// TO STORE THE TOTAL TIME
	char outTime[20];// TO STORE THE OUTPUT TIME

};

int cmt=0;
char implines[200][100];
char mnt[20];
typedef struct data dt;
dt ht;

int readDate(char ch[]); // TO READ THE FIRST DATA FROM HTML
long readNxtLine(long n);// TO READ NEXT LINES FROM FIRST DATA FROM HTML
int lenMLines();// TO PRODCUCE THE NUMBER OF DATA LINES
void getDate(char ch[]);// TO EXTRACT DATE 
void getIDName(); // TO EXTRACT ID AND NAME
void getinTime(); // TO EXTRACT IN TIME
void getoutTime(); // TO EXTRACT OUT TIME
void gettotalTime(); // TO EXTRACT TOTAL TIME
void getstat();// TO EXTRACT THE STATUS OF THE DAY
void nullData();// TO NULLIFY EACH ARRAY
void display();// TO DISPLAY THE DETAILS
void whichmonth(int n);// TO RETURN THE MONTH NAME


int main()
{
	FILE *fp,*fp1;
	fp1=fopen("db.dat","w");
	fp=fopen("Programme.html","r");
	char lines[5000],ch;
	int i=0,j,len;
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
	len=lenMLines();
	nullData();
	i=-1;
	while(i<125)
	{
		getDate(implines[++i]);
		fprintf(fp1,"%s\t",ht.date);
		getIDName(implines[++i]);
		//fprintf(fp1,"%s\t",ht.name);
		getinTime(implines[++i]);
		fprintf(fp1,"%s\t",ht.inpTime);
		getoutTime(implines[++i]);
		fprintf(fp1,"%s\t",ht.outTime);
		gettotalTime(implines[++i]);
		fprintf(fp1,"%s\t",ht.toTime);
		getstat(implines[++i]);
		fprintf(fp1,"%s\n",ht.stat);
		nullData();
	}
		fclose(fp1);
		display();
	return 0;
}

int readDate(char lines[])
{
	int i=0;
	while(lines[i]!='\0')
	{
		if((lines[i]=='0' || lines[i]=='1' || lines[i]=='2' || lines[i]=='3' || lines[i]=='4' || lines[i]=='5' || lines[i]=='6' || lines[i]=='7' || lines[i]=='8' || lines[i]=='9' ) && lines[++i]=='-' && (lines[i+2]=='0' || lines[i+2]=='1' || lines[i+2]=='2' || lines[i+2]=='3' || lines[i+2]=='4' || lines[i+2]=='5' || lines[i+2]=='6' || lines[i+2]=='7' || lines[i+2]=='8' || lines[i+2]=='9' ) )
		{
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
	ch=getc(fp);
	return ftell(fp);
	fclose(fp);

}
int lenMLines()
{
	int i=0,c=0;
	while(implines[i][0])
	{
		c++;
		i++;
	}
	return c;
}


void getDate(char ch[])
{
	int k=0,j=0,i=0,h=0;
	int len=strlen(ch);
	for(i=1;i<len;i++)
	{
		if(ch[i]=='<')
		{
			while(1)
			{
				if(ch[i]=='>')
				{
					break;
				}
				i++;
			}
			i++;
			while(1)
			{
				if(ch[i]=='<')
					break;
				ht.date[k]=ch[i];
				i++;
				k++;
			}
			break;
		}

	}
	
}

void getIDName(char ch[])
{
	int k=0,j=0,i=0,h=0;
	int len=strlen(ch);
	for(i=1;i<len;i++)
	{
		if(ch[i]=='<')
		{
			while(1)
			{
				if(ch[i]=='>')
				{
					break;
				}
				i++;
			}
			i++;
			while(1)
			{
				if(ch[i]=='<')
					break;
				ht.name[k]=ch[i];
				i++;
				k++;
			}
			break;
		}

	}
	
}

void getinTime(char ch[])
{
	int k=0,j=0,i=0,h=0;
	int len=strlen(ch);
	for(i=1;i<len;i++)
	{
		if(ch[i]=='<')
		{
			while(1)
			{
				if(ch[i]=='>')
				{
					break;
				}
				i++;
			}
			i++;
			while(1)
			{
				if(ch[i]=='<')
					break;
				ht.inpTime[k]=ch[i];
				i++;
				k++;
			}
			break;
		}

	}
}

void getoutTime(char ch[])
{
	int k=0,j=0,i=0,h=0;
	int len=strlen(ch);
	for(i=1;i<len;i++)
	{
		if(ch[i]=='<')
		{
			while(1)
			{
				if(ch[i]=='>')
				{
					break;
				}
				i++;
			}
			i++;
			while(1)
			{
				if(ch[i]=='<')
					break;
				ht.outTime[k]=ch[i];
				i++;
				k++;
			}
			break;
		}

	}
}


void gettotalTime(char ch[])
{
	int k=0,j=0,i=0,h=0;
	int len=strlen(ch);
	for(i=1;i<len;i++)
	{
		if(ch[i]=='<')
		{
			while(1)
			{
				if(ch[i]=='>')
				{
					break;
				}
				i++;
			}
			i++;
			while(1)
			{
				if(ch[i]=='<')
					break;
				ht.toTime[k]=ch[i];
				i++;
				k++;
			}
			break;
		}

	}
}

void getstat(char ch[])
{
	int k=0,j=0,i=0,h=0;
	int len=strlen(ch);
	for(i=1;i<len;i++)
	{
		if(ch[i]=='<')
		{
			while(1)
			{
				if(ch[i]=='>')
				{
					break;
				}
				i++;
			}
			i++;
			while(1)
			{
				if(ch[i]=='<')
					break;
				ht.stat[k]=ch[i];
				i++;
				k++;
			}
			break;
		}

	}
}


void nullData()
{
	int i;
	for(i=0;i<20;i++)
	{
		ht.inpTime[i]='\0';
		ht.outTime[i]='\0';
		ht.toTime[i]='\0';
	}
	for(i=0;i<5;i++)
		ht.stat[i]='\0';
	for(i=0;i<15;i++)
		ht.date[i]='\0';
	for(i=0;i<30;i++)
		ht.name[i]='\0';
}


void display()
{
	getIDName(implines[1]);
	int i=0;
	printf("NAME: ");
	while(ht.name[i]!='\0')
	{
		if(ht.name[i]=='-')
		{
			i++;
			while(ht.name[i]!='\0')
			{
				printf("%c",ht.name[i]);
				i++;
			}
			break;
		}
		i++;
	}
	printf("\n");
	i=0;
	int j=0;
	char a[3];
	getDate(implines[0]);
	
	while(ht.date[i]!='\0')
	{
		if(ht.date[i]=='-')
		{
			i++;
			while(ht.date[i]!='-')
			{
				a[j]=ht.date[i];
				i++;
				j++;
			}
			whichmonth(atoi(a));
			break;
		}
		i++;
	}
	printf("MONTH:%s\n",mnt);
}

void whichmonth(int d)
{
	switch(d)
	{
		case 1: strcpy(mnt,"JANUARY");
					break;
		case 2: strcpy(mnt,"FEBRUARY");
					break;
		case 3: strcpy(mnt,"MARCH");
					break;
		case 4: strcpy(mnt,"APRIL");
					break;
		case 5: strcpy(mnt,"MAY");
					break;
		case 6: strcpy(mnt,"JUNE");
					break;
		case 7: strcpy(mnt,"JULY");
					break;
		case 8: strcpy(mnt,"AUGUST");
					break;
		case 9: strcpy(mnt,"SEPTEMBER");
					break;
		case 10: strcpy(mnt,"OCTOBER");
					break;
		case 11: strcpy(mnt,"NOVEMBER");
					break;
		case 12: strcpy(mnt,"DECEMBER");
					break;
	}
}