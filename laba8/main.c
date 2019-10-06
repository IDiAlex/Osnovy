#include <stdio.h>
#define YES 1
#define NO 0
#define max 1000

int main(void)
{
	char text[max]; // iauyaeaiea ianneaa text
	int word; // caueoa io "ia neia"
	int flag; // i?eciae ia?aea iiaiai neiaa
	int found; // i?eciae iiaoi?a
	int cnt = 0; // eiiao oaeea
	int count = 0;
	char *in; // oeacaoaeu ia oaeouee neiaie aoiaiie no?iee
	char *out; // ...auoiaiie no?iee
	char *nach; // oeacaoaeu ia ia?aei neiaa
	char *ud;
	char *idal;

	in = text;
	out = text;
	nach = text;
	ud = text;
	idal = text;

	printf("Enter words: ");
	fgets(text, max, stdin);; // n?eouaaiea no?iee a iannea text

	while (*in != '\0')
	{

		// ia?aei caueou
			if ((*in < 'a' || *in > 'z') && (*in < 'A' || *in > 'Z') && *in != ' ' && *in != '.' && *in != ',' && *in != '\n' && *in != '\0' && *in != '\t')
		{
			word = NO;
			break;
		}
		else
		{
            word = YES;
		}

        // eiiao caueou



        if ((*in == ' ') || (*in == '.') || (*in == ',') || (*in == '\n') || (*in == '\0') || (*in == '\t'))
        {
            printf("5\n");
            in++;
            if((*in > 'a' || *in < 'z') && (*in > 'A' || *in < 'Z'))
            {
                flag = YES;
                printf("6\n");
            }
        }
        if(flag==NO)
            cnt++;

        if((flag == YES)&&(*in != '\0'))
        {
            printf("7\n");
            if(*(in-cnt) == *in)
            {
                printf("8\n");
                count++;
                if(*(in-cnt+1)=' ')
                {
                    if(*(in+1)=' ')
                    {
                        found = YES;
                        printf("10\n");
                    }
                }
                else
                {
                    printf("9\n");
                    found = NO;
                    out++;
                }
                if(found == YES)
                 {
                    printf("2\n");
                    do
                    {
                        *(in-cnt) = ' ';
                        cnt--;
                    }
                    while((in-cnt)<in);
                    found = NO;
                }
            }
            else
            {
                cnt=0;
                flag = NO;
                *out = *nach;
                printf("1\n");
            }
        }

        if(*in!='\0')
        {
           //printf("11\n");
           in++;
        }

	 }

	if (word == YES)
	{
        printf("Result: ");
        puts(text);
	}
	if (word == NO)
        printf("Sorry you entered a bad sign\n");
	return 0;
}