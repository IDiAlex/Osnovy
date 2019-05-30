#include <stdio.h>
int main(void)
{
    unsigned long int N; // dlinnyoe chislo N
    int i; // ���������� ��� �������� ������
    int k; // ���������� ��� �������� �����
    int n; // ���������� ��� ����������� ������� ����
    int counter; // ������� ������
    unsigned long int mask; // � ��� �� ������� �������� �����
    printf("Enter N\nN = ");
    scanf("%d", &N);
    mask = 0;
    i = 0; 
    k = 31; // �������� ����� ������� � ������������� ��������� ���� ����� �� ����� 

    while (i != 4) // � ���� ��� 4 �����
    {
        for (n = 0, counter = 0; n != 8; ++n, --k) // � ������ ����� 8 ���
        {
            if (N >> k & 01) // �������� N �� k �������� ������ � ���������� ��������� ��� � ��������
                             // ���� ����������� ������� ����������� �������
                             // & - ���������� ���������
            {
                ++counter;
            }
        }
        if (counter >= 4) // ������� ������ �������� ��� �����, ��� �������� � ���� ����� 4-� ������
        {
            mask = mask << 8 | 0xff; // �������� ����� �� 8 �����
                                     // ��������� �������������� ���� ���������
                                     // | - ���������� ��������
        }
        else
        {
            mask = mask << 8; // �������� ����� �� 8 ����� � ������ �� ���������
        }
        ++i;
    }

    N = N & mask; // �������� �������� �����

    printf("Result: %lu", N); // lu - long unsigned ��-������� ��������� �� ��������� ��������
    return 0;
}
