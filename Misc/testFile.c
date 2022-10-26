#include<stdio.h>

int main()
{
	printf("\nHello World!\n\n");

	int number1, number2, sum;
	
	printf("\nPlease enter two integers: ");
	scanf("%d %d", &number1, &number2);

	sum = number1 + number2;
	
	printf("%d + %d = %d\n\n", number1, number2, sum);
	
	
	return 0;
}
