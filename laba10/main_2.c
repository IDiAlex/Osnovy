#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
int main(){
    char **line=NULL, c;
    int linenum=0, letternum=0, nword=0, j, i=0;
    FILE *fpin, *fpout;

	fpin=fopen("file.txt", "rt");
    if(fpin==NULL)
        return;
    fpout=fopen("result.txt", "wt");
    if(fpout==NULL)
        return;

    line=(char**)malloc(sizeof(char*));
    line[0]=(char*)malloc(sizeof(char));

    while((c=fgetc(fpin))!=EOF){
        line[linenum] = (char*)realloc(line[linenum], letternum + 1);
        line[linenum][letternum++] = c;
        if (c=='\n'){
            line[linenum] = (char*)realloc(line[linenum], letternum + 1);
            line[linenum][letternum] = '\0';
            line = (char**)realloc(line, ((++linenum) + 1) * sizeof(char*));
            line[linenum] = (char*)malloc(sizeof(char));
            letternum = 0;
        }
    }
    line[linenum] = (char*)realloc(line[linenum], letternum + 1);
    line[linenum][letternum] = '\n';
    line[linenum] = (char*)realloc(line[linenum], letternum );
    line[linenum][letternum] = '\0';

    for(i=0;i<=linenum;i++){
        for(j=0;line[i][j]!='\0';j++){
            printf("%c", line[i][j]);
        }
    }
    printf("\n");
    int num[2][linenum+1], tmp, min;
    for(i=0;i<=linenum;i++){
        num[0][i]=i;
        for(j=0, nword=0;line[i][j]!='\0';j++){
            if((line[i][j+1]==' '||line[i][j+1]==','||line[i][j+1]=='.'||line[i][j+1]=='!'||line[i][j+1]=='?'||line[i][j+1]=='\n')&&((line[i][j]>='a'&&line[i][j]<='z')||(line[i][j]>='A'&&line[i][j]<='Z'))&&(line[i][j]<'0'||line[i][j]>'9')){
                nword++;
            }
            num[1][i]=nword;
        }
    }

    printf("\n");
    for(j=0;j<=linenum;j++)
        printf("\n[%d]%d", num[0][j], num[1][j]);

    fclose(fpin);
	fclose(fpout);
	return 0;
}