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
	
	float d = (b*b)-((4*a)*c);
	printf("Discriminant: %f\n",d);	
	if(d<0)
	{
		printf("There are no roots\n");
	}
	else if(d==0)
	{
		printf("There is one root.\n");
		float root = (0-b)/(2*a);
		printf("Root: %f\n",root); 
	}
	else if(d>0)
	{
		printf("There are two roots.\n");
		float r1 = ((0-b)+(sqrt((b*b)-((4*a)*c))))/(2*a);
		float r2 = ((0-b)-(sqrt((b*b)-((4*a)*c))))/(2*a);
		printf("Root 1: %f\nRoot 2: %f\n",r1,r2);
	}
	return 0;
}
