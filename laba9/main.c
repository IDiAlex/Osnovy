#include <stdio.h>
#define maxletter 1024
int main()
{
    char line[maxletter],*p,*c;
    int flag,j,i;
	FILE *fpin, *fpout;
	fpin = fopen( "file.txt", "rt" );
    if( fpin == NULL )
        return;
    fpout = fopen("result.txt", "wt" );
    if( fpout == NULL )
        return;
	while (!feof(fpin)){
		p = fgets(line, maxletter, fpin);
        c = line;
		if (p == NULL)
			break;
        for(i=0, j=0, flag=0; p[i]!='\0'; i++){
            if(p[i]=='/')
                flag=1;
            if(flag==1&&p[i+1]=='/'){
                p[i] ='\0';
                break;
            }
            if(flag==1&&p[i+1]=='*')
                flag=2;
            if(flag==1&&p[i]!='*'&&p[i]!='/')
                flag=0;
            if(flag==2&&p[i]=='*')
                flag=3;
            if(flag==3&&p[i]=='/')
                flag=0;
            if(flag==0)
                c[j++]=p[i];
            if(p[i+1]=='\0')
                c[j]='\0';
        }
        fputs(line, fpout);
	}
	fclose(fpin);
	fclose(fpout);
	return 0;
}
