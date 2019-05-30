#include <stdio.h>
int main(void)
{
	int i;
	int cnt = 0;
	int j;
	unsigned long int temp;
	unsigned long int mask = 0;
	unsigned long int mask1 = 0;
	unsigned long int N = 0;
	unsigned long int res;

	printf("Count:");
	scanf("%lu",&N);
	printf("Count:");
	res = N;

	for( i = 0; i < 32; i++ )
	{
		temp = res;
		res <<= 1;
		res >>= 1;
		if(res == temp)
		{
			printf("0");
		}
		else
		{
			printf("1");
			cnt++;
			mask1 = mask1 | ( 1 << ( 31 - i ) );
		}
		if( ( i + 1 ) %8 == 0 )
		{
			printf(" ");
			if( cnt > 3 )
			{
				mask = mask | mask1;
			}
			else
			{
				for( j = 31 - i; j < ( 31 - i + 8 ); j++ )
				{
					mask1  = mask1 & ( 0 << j );
				}
			}
			cnt = 0;
		}
		res <<= 1;
	}

	N = mask;
	res = N;
	printf("\nResult:");

	for( i = 0; i < 32; i++)
    {
        temp = res;
        res <<= 1;
        res >>= 1;
        if( res == temp )
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
        if(( i + 1 ) %8 == 0 )
        {
            printf(" ");
        }
        res <<= 1;
    }
    printf("\nResult:%lu",N);
	return 0;
}
