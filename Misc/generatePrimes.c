#include <stdio.h>
#include <time.h>

void delay(int number_of_seconds);

int main()
{
	printf("2\n");
	delay(1);
	int n = 3;
	while(1 == 1)
	{
		int flag = 0;
		int i = 0;
		for(i=2; i<=n/2; i++)
		{
			//if n is divisible by i, then n is not prime.
			if(n % i == 0)
			{
				flag = 1;
				break;
			}
		}
		//flag will be 0 if number is prime.
		if(flag == 0)
		{
			printf("%d\n", n);
			delay(1);
		}
	n++;
	}
	return 0;
}

void delay(int number_of_seconds)
{
	int milli_seconds = CLOCKS_PER_SEC * number_of_seconds;
	clock_t start_time = clock();
	while(clock() < start_time + milli_seconds);
}
