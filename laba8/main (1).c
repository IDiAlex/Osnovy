#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, cnt, n, f[n],*m;
    printf("Enter the number of lines: ");
    scanf("%d", &n);
    char **a;
    for(i=0; i<n; i++)
        f[i]=1;
    a = (char**)malloc(n * sizeof(char*));
    m = (char*)malloc(n * sizeof(char)); // массив кол-ва элеменов в строках массива a
    for(i = 0; i<n; i++)
    {
        printf("Enter the number of row columns %d: ", i);
        scanf("%d", &m[i]);
        a[i]=(char*)malloc(m[i] * sizeof(char));
        for(j=0; j<m[i]; j++)
        {
            printf("a[%d][%d]= ", i, j);
            scanf("%s", &a[i][j]);
        }
    }
    for(i=0; i<(n-1); i++)
    {
        for(int k=1; k<=(n-i-1); k++)
        {
            for(cnt=0 ,j=0; j<m[i]; j++)
            {
                if(a[i][j]==a[i+k][j])
                    cnt++;
            }
            if((cnt==j)&&(m[i]==m[i+k]))
                f[i+k]=0;
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m[i]; j++)
        {
            if(f[i]==1)
                printf("%c", a[i][j]);
        }
        printf(" ");
    }
    return 0;
}
