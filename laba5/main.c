#include <stdio.h> 
#include <stdlib.h>
#define N 10 
int main(void)
{
int x[N]; // массив из N элементов
float aver; // среднее арифметическое 
int cnt = 0; // сумма цифр 
int i = 0; // номер элемента
float n = 0; // количество цифр 

printf("Enter counter:\n");

// ввод массива 
srand(time(NULL)) ;
for (i = 0; i < N; i++)
{
x[i] = rand()%100-33;
printf("%d ", x[i]);
}

for (i = 0; i < N; i++)
{
do
{
cnt += abs(x[i] % 10); // суммируем цифры, складывая остатки от деления на 10 модуля числа i-го элемента 
x[i] = x[i] / 10; // делим на 10, чтобы убрать то, что уже прибавили 
n++; // увеличиваем счётчик цифр на 1
} while (x[i] != 0); 
}
// вычисление среднего арифметического значения 
aver = cnt / n; // делим сумму цифр на их количество 
printf("\naver = %.1f\n", aver);
return 0;
}