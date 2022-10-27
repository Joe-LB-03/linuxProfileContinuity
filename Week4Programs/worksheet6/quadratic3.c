#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/*
 * Complete the code so that 3 command line values are given defining a quadratic equation.
 *   a x^2 + b x + c = 0
 * Find the roots of the equation and display the results
 *
 * Do not alter the print statements - the autograder expects them
 * You should use them at appropriate places in your program 
 */

int main( int argc, char *argv[] ) 
{
	if(argc != 4)
	{	 
 		printf(" Error: Usage:  ./quadratic3 a b c\n");
		return 0;
	}
	
	float a = atof(argv[1]);
	float b = atof(argv[2]);
	float c = atof(argv[3]);
	
 	// display the equation using the provided coefficients
 	printf(" Solutions for: (%5.2f) x^2 + (%5.2f) x + (%5.2f) = 0\n",a,b,c);
	
	float d = (b*b)-((4*a)*c);

	if(d<0||((a==0)&&(b==0)&&(c==0)))
	{
 		// when there are 0 roots
 		printf("0 roots\n");
	}
	else if(d==0)
	{
 		// when there is 1 root
 		float root1 = (0-b)/(2*a);
  		printf("1 root: %8.3f\n", root1 );
	}
	else if(d>0)
	{
 		// when there are 2 roots
 		float root1 = ((0-b)+(sqrt((b*b)-((4*a)*c))))/(2*a);
		float root2 = ((0-b)-(sqrt((b*b)-((4*a)*c))))/(2*a);
 		printf("2 roots: %8.3f %8.3f\n", root1,root2 );
	}
 	return 0;
}
