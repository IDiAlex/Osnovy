#include <stdio.h>
int main(void)
{
    float R;
    float H;
    float D;
    float V;
    float R1;
    printf("R =");
    scanf("%f" , &R);
    printf("H =");
    scanf("%f" , &H);
    printf("D =");
    scanf("%f" , &D);
    R1 = R * D / H;
    V = ( 1.0/3.0 * 3,14 * (H-D) * ( R * R + R1 * R1 + R * R1));
    printf("V = %f\n",V);
    return 0;
}
