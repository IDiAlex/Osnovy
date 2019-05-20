#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#define N 3
#define K 5

int main(void)
{
int x[N][K]; // ������ �� N �� K ���������
int min; // ����������� �������
int i = 0; // ������
int j = 0; // �������
int z; // �������
int c; // ������
int rem_c = 0; // ��� ����������� ������ ������ ������������ ��������
int rem_z = 0; // ��� ����������� ������ ������� ������������ ��������

printf("Enter counter:\n");

// ���� �������

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

// ����������

for (i=0; i < N; ++i)
{
    for (j=0; j < K; ++j)
    {
        min = x[i][j];//��������� ������������ ��� ������������ ��-��
        rem_c = i;
        rem_z = j;
        for (c = i; c < N; ++c)
        {
            int sm_j = j; // ����� ���-�� ��������������� �� ����������� �������� �� �������, � ������ ���������� � �������� ��������������� � ������� ��������
            if (c != i)
            {
                sm_j = 0;
            }
            for (z = sm_j; z < K; ++z)
            {
                if (min > x[c][z])
                {
                    min = x[c][z]; //���������� �������� ������������ ��������
                    rem_c = c;//� ��� "����������" ��� ����������� swap(����)
                    rem_z = z;
                }

            }
        }
        x[rem_c][rem_z] = x[i][j];//�������� ����
        x[i][j]=min ;
    }
}

// ����� �������

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
