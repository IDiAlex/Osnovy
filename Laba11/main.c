#include <stdio.h>
#include <Windows.h>
enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};
int main(){
    char c;
    int strconst=0;
    FILE *fpin;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("color F0");
	fpin=fopen("file.txt", "rt");
    if(fpin==NULL)
        return;
    while((c=fgetc(fpin))!=EOF){
        if(c=='\\'){
            printf("%c",c);
            if((c=fgetc(fpin))=='"')
                strconst--;
        }
        if(c=='"')
            strconst++;
        if((strconst%2)!=1)
            SetConsoleTextAttribute(hConsole, White<<4 | Black);
        printf("%c",c);
        if((strconst%2)!=0)
            SetConsoleTextAttribute(hConsole, Cyan<<4 | White);
        if(c=='/'){
            if((c=fgetc(fpin))=='/'){
                printf("%c",c);
                while((c=fgetc(fpin))!='\n')
                    printf("%c",c);
            }
            printf("%c",c);
            if(c=='*'){
                c=fgetc(fpin);
                printf("%c",c);
                while(c!='*'&&(c=fgetc(fpin))!='/')
                    printf("%c",c);
            }
        }
    }
    fclose(fpin);
	return 0;
}
