#include <stdio.h>

int main()
{
	int n, i, flag = 0;
	printf("Enter a positive integer: ");
	scanf("%d", &n);

	//As 0 and 1 are not prime numbers, manually set flag to 1.
	if(n == 0 || n == 1)
	{
		flag = 1;
	}

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
		printf("%d is prime.\n", n);
	}
	else
	{
		printf("%d is not a prime.\n", n);
	}
	
	return 0;
}
