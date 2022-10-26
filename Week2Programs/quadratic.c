#include <stdio.h>
#include <math.h>

int main(void)
{
	float a;
	float b;
	float c;
	
	printf("Please enter the a, b and c values of the quadratic!\nThese values should match the format ax^2 + bx + c.\nPlease seperate them with a SPACE.\nThe numbers should be written with at least one decimal place for accuracy.\n");

	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	
	float r1 = ((0-b)+sqrt(pow(b,2)-((4*a)*c)))/(2*a);
	float r2 = ((0-b)-sqrt(pow(b,2)-((4*a)*c)))/(2*a);

	if(!isnan(r1) && !isnan(r2))
	{
		printf("roots: %f and %f\n",r1,r2);
	}
	else
	{
		printf("no roots L RIPBOZO\n");
	}

	return 0;
}
