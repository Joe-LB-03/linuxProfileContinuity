#include <stdio.h>
#include <math.h>

int main(void)
{
	int input;
	int result = 1;	

	printf("Please enter the number to be factorial-ized.\n");
	scanf("%d",&input);

	for(input-1; input > 1; input--)
	{
		result = result*input;
	} 
	printf("%d",result);
}
