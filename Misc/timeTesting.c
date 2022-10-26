#include <stdio.h>
#include <time.h>

void delay(int number_of_seconds)
{
	int milli_seconds = CLOCKS_PER_SEC * number_of_seconds;
	clock_t start_time = clock();
	while(clock() < start_time + milli_seconds);
}

int main()
{
	int i;
	for(i = 0; i <= 10; i++)
	{
		delay(1);
		printf("%d seconds have passed\n", i + 1);
	}
	return 0;
}
