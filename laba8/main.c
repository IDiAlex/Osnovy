#include <stdio.h>
#define YES 1
#define NO 0
#define MAXLINE 1000

int main(void)
{
	char LINE[MAXLINE]; // ���������� ������� LINE
	int word; // ������ �� "�� ����"
	int c; // �������  ������
	int prev_c = NO; // ���������� ������
	int flag = NO; // ������� ������ ������ �����
	int found = NO; // ������� �������
	int finish = NO; // ����� �����
	int d; // ��� ����������� ������ �����
	int e; // ��� ��������
	int len = 0;

	char *in_ptr; // ��������� �� ������� ������ ������� ������
	char *out_ptr; // ...�������� ������
	char *word_ptr; // ��������� �� ������ �����
	char *dword_ptr;

	in_ptr = LINE;
	out_ptr = LINE;
	word_ptr = LINE;
	dword_ptr = LINE;

	printf("Enter words: ");
	gets(LINE); // ���������� ������ � ������ LINE

	do
	{
		c = *in_ptr;
		d = *word_ptr;
        e = *dword_ptr;

		// ������ ������
			if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && c != ' ' && c != '.' && c != ',' && c != '\n' && c != '\0' && c != '\t')
		{
			word = NO;
			break;
		}
		else
		{
            word = YES;
            break;
		}

        // ����� ������

        if ((c == ' ') && (c == '.') && (c == ',') && (c == '\n') && (c == '\0') && (c == '\t'))
        {
            in_ptr++;
            if((c > 'a' || c < 'z') && (c > 'A' || c < 'Z'))
                flag = YES;
        }

        if((flag == YES)&&(c != '\0'))
        {
            if(c == e)
            {
                dword_ptr++;
                in_ptr++;
                if((c == ' ') && (c == '.') && (c == ',') && (c == '\n') && (c == '\0') && (c == '\t')||(e == ' ') && (e == '.') && (e == ',') && (e == '\n') && (e == '\0') && (e == '\t'))
                    found = YES;
                else
                    found = NO;
            }
            else
            {
                flag = NO;
                e = d;
            }
        }

        //if()
        in_ptr++;
	}
	while ( e != '\0');

	if (word == YES)
	{
        printf("Result: ");
        puts(LINE);
	}
	if (word == NO)
        printf("Sorry you entered a bad sign\n");
	return 0;
}
