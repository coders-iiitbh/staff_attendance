#include <stdio.h>
int ckline(char ch[]);
void readTime(long n);
void main()
{
    FILE *fp;
    int i,j,jh=1;
    char ch;
    char line[5000];
    fp=fopen("Programme.html","r");
    int c=0;
    char cp[1000];
    ch=getc(fp);
    while (ch != EOF) {
        i=0;
       // extract:
        while (ch != '\n')
        {
            line[i++]=ch;
            ch=getc(fp);
            if (ch == EOF)
                break;
        }
        line[i]='\0';

       // puts(line);
        if (ch == EOF)
            break;
            j=ckline(line);
          // printf("%d\n",j);
        ch=getc(fp);
        if(j==1)
        {
       readTime(ftell(fp));
       break;  	
        }
      
        }
       
    
    fclose(fp);
}
int ckline(char line[])
{
	FILE *fp;
	fp=fopen("abc.txt","a");
    int i=0;
    while(line[i]!='\0')
    {
        if(line[i]=='F' && line[++i]=='P')
        {
        	fprintf(stdout,"%s\n",line);
            return 1;
        }
        i++;
    }
    fclose(fp);
}
void readTime(long n)
{
	FILE *fp1,*fp;
	fp=fopen("abc.txt","a");
	fp1=fopen("Programme.html","r");
	char ch,line[5000];
	int i=0;
	fseek(fp1,n,0);
	ch=getc(fp1);
        i=0;
       // extract:
        while (ch != '\n')
        {
            line[i++]=ch;
            ch=getc(fp1);
            if (ch == EOF)
                break;
        }
        line[i]='\0';
        fprintf(stdout,"%s\n", line);
	fclose(fp);
	fclose(fp1);

}