#include <stdio.h> 
#include <stdlib.h>
#define N 10 
int main(void)
{
int x[N]; // ������ �� N ���������
float aver; // ������� �������������� 
int cnt = 0; // ����� ���� 
int i = 0; // ����� ��������
float n = 0; // ���������� ���� 

printf("Enter counter:\n");

// ���� ������� 
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
cnt += abs(x[i] % 10); // ��������� �����, ��������� ������� �� ������� �� 10 ������ ����� i-�� �������� 
x[i] = x[i] / 10; // ����� �� 10, ����� ������ ��, ��� ��� ��������� 
n++; // ����������� ������� ���� �� 1
} while (x[i] != 0); 
}
// ���������� �������� ��������������� �������� 
aver = cnt / n; // ����� ����� ���� �� �� ���������� 
printf("\naver = %.1f\n", aver);
return 0;
}