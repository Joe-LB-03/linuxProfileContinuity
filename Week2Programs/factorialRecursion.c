#include <stdio.h>
#include <math.h>

int main(void)
{
	int num;
	int result = 1;
	printf("Please enter the number to be factorialized.\n");
	scanf("%d",&num);
	printf("%d\n",factorialize(num, result));
	return 0;	
}

int factorialize(int num, int result)
{
	result = result*num;	
	num--;
	if(num == 1)
	{
		return result;
	}
	else
	{
		factorialize(num, result);
	}	
}
