#include <stdio.h>
#define YES 1
#define NO 0
#define MAXLINE 1000

void process_LINE(char buffer[]); // объявление функции

int main(void)
{
	char LINE[MAXLINE]; // объявление массива LINE
	printf("Enter words:\n");
	gets(LINE); // считываем строки и вносим в массив LINE
	process_LINE(LINE); // выполняем функцию
	printf("Result: ");
	puts(LINE); // выводим LINE
	return 0;
}

void process_LINE(char buffer[]) // тело фукции
{
	int c; // текущий символ
	int prev_c; // предыдущий символ
	int i; // позиция символа
	int post_i; // позиция символа в конечном варианте
	int j; // позиция первого символа слова
	int k; // переменная
	int length; // длина слова
	int img_i; // мнимый текущий символ
	int img_j; // мнимое начало слова
	int counter; // счётчик букв
	int flag; //
	int found; // не слово
	int finish; //

	found = NO;
	i = 0;
	prev_c = ' ';
	post_i = -1;
	finish = NO;

	do
	{
		c = buffer[i];
		if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != ' ' && c != '.' && c != ',' && c != '\n' && c != '\0' && c != '\t')) // проверка на слово
		{
			found = YES;
		}
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '\t') // ищем конец слова
		{
			if (c == '\0')
			{
				finish = YES;
			}
			if (prev_c != ' ' && prev_c != '.' && prev_c != ',' && prev_c != '\n' && prev_c != '\t')
			{
				flag = 0;
				length = i - j;
				if (found == NO)
				{
					counter = 0;
					for (img_i = 0; buffer[img_i] != '\0'; ++img_i, ++k)
					{
						if (buffer[img_i] == ' ' || buffer[img_i] == '.' || buffer[img_i] == ',' || buffer[img_i] == '\n' || buffer[img_i] == '\t')
						{
							counter = 0;
						}
						if (counter == 0)
						{
							k = j;
						}
						if (buffer[k] == buffer[img_i])
						{
							++counter;
						}
						else
						{
							if (counter == length)
							{
								counter = 0;
							}
						}
						if ((counter == length) && (buffer[img_i+1] == ' ' || buffer[img_i+1] == '.' || buffer[img_i+1] == ',' || buffer[img_i+1] == '\n' || buffer[img_i+1] == '\t' || buffer[img_i + 1] == '\0'))
						{
							if (flag == 1)
							{
								img_j = img_i - length + 1;
							}
							++flag;
						}
					}
					if (flag == 2)
					{
						for (k = j; k < j + length; ++k)
						{
							buffer[k] = ' ';
						}
						for (k = img_j; k < img_j + length; ++k)
						{
							buffer[k] = ' ';
						}
					}
					if (flag > 2)
					{
						for (k = j; k < j + length; ++k)
						{
							buffer[k] = ' ';
						}
					}
				}
				found = NO;
			}
		}
		else
		{
			if (prev_c == ' ' || prev_c == '.' || prev_c == ',' || prev_c == '\n' || prev_c == '\t')
			{
				j = i;
			}

		}
		prev_c = c;
		++i;
		if (finish == YES)
		{
			i = 0;
			while (buffer[post_i+1] != '\0')
			{
				if (buffer[i] != ' ')
				{
					++post_i;
					buffer[post_i] = buffer[i];
					buffer[post_i + 1] = buffer[i+1];
					if (buffer[i+1] == ' ')
					{
						++post_i;
					}
				}
				++i;
			}
		}

	} while (finish != YES);
}
