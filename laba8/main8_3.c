#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **line, c;
    int wordnum = 0, letternum = 0, i, cnt, knt;

    printf("Enter the string: ");
    line = (char**)malloc(sizeof(char*));
    line[0] = (char*)malloc(sizeof(char));

    while((c = getchar()) != '\n'){
        if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')||c=='-'){
            if (letternum == 0 && wordnum != 0){
                line = (char**)realloc(line, ((++wordnum) + 1) * sizeof(char*));
                line[wordnum] = (char*)malloc(sizeof(char));
            }
            line[wordnum] = (char*)realloc(line[wordnum], letternum + 1);
            line[wordnum][letternum++] = c;
        }
        else{
            if (letternum != 0){
                line[wordnum] = (char*)realloc(line[wordnum], letternum + 1);
                line[wordnum][letternum] = '\0';
            }
            line = (char**)realloc(line, ((++wordnum)+1) * sizeof(char*));
            letternum = 0;
            line[wordnum] = (char*)malloc(2*sizeof(char));
            line[wordnum][letternum] = c;
            line[wordnum][letternum+1] = '\0';
        }
    }
    int f[wordnum];
    for(i=0; i<=wordnum; i++)
        f[i]=1;
    for(i=0; i<=(wordnum-2); i++){
        for(int k=1; k<=(wordnum-i); k++){
            for(cnt=0, knt=0, letternum=0; line[i][letternum]!='\0'&&line[i+k][letternum]!='\0'; letternum++){
                if(line[i][letternum]==line[i+k][letternum]&&line[i][letternum]!=' '&&line[i][letternum]!=','&&line[i][letternum]!=':'&&line[i][letternum]!=';'&&line[i][letternum]!='.'&&line[i][letternum]!='?'&&line[i][letternum]!='!')
                    cnt++;
                knt++;
            }
            if(cnt==knt&&line[i][letternum]=='\0'&&line[i+k][letternum]=='\0')
                f[i+k]=0;
        }
    }
    printf("Result: ");
    for(i=0; i<=wordnum; i++){
        if(f[i]==1)
            printf("%s", line[i]);
    }
    return 0;
}
