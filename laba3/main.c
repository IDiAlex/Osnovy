#include <stdio.h>

#define YES 1
#define NO 0
#define MAXLINE 100

int palindrom(char buffer[], int i);

int main(void)
{
    int c;
    int counter;
    char WORD[MAXLINE];
    int found;
    int i;
    int prev_c;
    
    prev_c = ' ';
    counter = 0;
    found = NO;
    i = 0;
    
    printf("Enter some words:");
    
    while ((c = getchar()) != EOF)
    {
        if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != ' ' && c != '.' && c != ',' && c != '\n' && c != '\t')) // проверка на не слово
        {
            found = YES;
        }
        if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\t') // находим конец слова
        {
            if (prev_c == ' ' || prev_c == '.' || prev_c == ',' || prev_c == '\n' || prev_c == '\t') // защита от повтора
            {
                
            }
            else
            {
                if (found == NO)
                {
                    counter = counter + palindrom(WORD, i);
                }
                found = NO;
                i = 0;
            }
        }
        else
        {
            WORD[i] = c;
            ++i;
        }
        prev_c = c;
    }
    printf("Result:%d", counter);
    
    return 0;
}

int palindrom(char buffer[], int i) // мы проверяем на палиндром
{
    int j;
    int counter;
    int flag;
    
    flag = YES;
    counter = i;
    j = 0;
    
    while (flag == YES && counter/2 < i)
    {
        if (buffer[i-1] - 'A' == buffer[j] - 'A' || buffer[i-1] - 'A' == buffer[j] - 'a' || buffer[i-1] - 'a' == buffer[j] - 'a' || buffer[i-1] - 'a' == buffer[j] - 'A')
        {
            
        }
        else
        {
            flag = NO;
        }
        --i;
        ++j;
    }
    if (flag == YES)
    {
        counter = 1;
    }
    else
    {
        counter = 0;
    }
    return counter;
}
