#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#include <time.h>

void nooflines();

int main()
{
	nooflines();
	return 0;
}

void nooflines()
{
	char ch[1000];
	FILE *fp,*f1;

	fp = fopen("Programme.html","r");
	f1 = fopen("ds.txt","w");
	int c=0,i=0;
	while(getc(fp)!=EOF)
	{
		if(getc(fp)=='\n')
			c++;
		else
		{
			ch[i]=getc(fp);
			fprintf(f1, "%c\n", ch[i]);
			i++;
		}
		
	}
	printf("%d\n",c);
	fclose(fp);
	fclose(f1);
}
