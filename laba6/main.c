#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#define N 3
#define K 5

int main(void)
{
int x[N][K]; // массив из N на K элементов
int min; // минимальный элемент
int i = 0; // строка
int j = 0; // столбец
int z; // столбец
int c; // строка
int rem_c = 0; // для запоминания номера строки минимального элемента
int rem_z = 0; // для запоминания номера столбца минимального элемента

printf("Enter counter:\n");

// ввод массива

srand(time(NULL));
for (i = 0; i < N; i++)
{
    for (j = 0; j < K; j++)
    {
        x[i][j] = rand() % 100 - 25;
        printf("%4.d", x[i][j]);
    }
    printf("\n");
}

// сортировка

for (i=0; i < N; ++i)
{
    for (j=0; j < K; ++j)
    {
        min = x[i][j];//начальные присваивания для минимального эл-та
        rem_c = i;
        rem_z = j;
        for (c = i; c < N; ++c)
        {
            int sm_j = j; // чтобы эле-ты просматривались от предыдущего элемента на строчке, а дальше переходили и начинали рассматриваться с первого элемента
            if (c != i)
            {
                sm_j = 0;
            }
            for (z = sm_j; z < K; ++z)
            {
                if (min > x[c][z])
                {
                    min = x[c][z]; //запоминаем значение минимального элемента
                    rem_c = c;//и его "координаты" для дальнейшего swap(инга)
                    rem_z = z;
                }

            }
        }
        x[rem_c][rem_z] = x[i][j];//своппинг гыгы
        x[i][j]=min ;
    }
}

// вывод массива

printf("Result:\n");
for (i = 0; i < N; i++)
{
for (j = 0; j < K; j++)
{
printf("%4.d ", x[i][j]);
}
printf("\n");
}
return 0;
}
