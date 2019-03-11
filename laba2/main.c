#include <stdio.h>
int main( void )
{
    float S;
    float a;
    float c;
    float b;
    float x;
    float eps;
    int i;
    int sign;
    printf("eps =");
    scanf("%f", &eps);
    printf("x =");
    scanf("%f", &x);
    S = 0.0;
    sign = 1.0;
    i = 0.0;
    c = 1.0;
    b = 1.0;
    a = c / b;
    while( a > eps )
    {
        S = S + a * sign;
        i = i + 1.0;
        sign = - sign;
        c = c * x * x;
        b = b * (2.0 * i - 1.0) * 2.0 * i;
        a = c / b;
    }
    printf("n = %d, S = %f\n", i, S);
    return 0;
}

