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

//so yeah, this one is autograded. no debug prints, just the ones they gave us in the starting file. I'll point these out as we go.

int quadraticSolver(float, float, float);

int main( int argc, char *argv[] ) 
{
	if(argc != 4) //same as before, if the user got the format wrong, just tell em and quit the program.
	{	 
 		printf(" Error: Usage:  ./quadratic3 a b c\n"); //this print is given, you just need to wrap it with the if statement.
		return 0;
	}
	
	float a = atof(argv[1]); //created these as a variable to store the given a, b and c numbers for calculations.
	float b = atof(argv[2]); //they are stored at the 1,2 and 3 locations in argv as strings, so i used atof to convert them to floats
	float c = atof(argv[3]); //remember arrays start from 0, so the executable name is stored there, thus the a b c values are [1][2][3] respectively
	
 	// display the equation using the provided coefficients
 	printf(" Solutions for: (%5.2f) x^2 + (%5.2f) x + (%5.2f) = 0\n",a,b,c); //this is given too, just prints what calculation is being done.
																			 //only thing to be aware of here is matching the a,b,c variable names
	printf("There is/are %d roots.\n", quadraticSolver(a,b,c));
 	return 0;
}

int quadraticSolver(float a, float b, float c)
{
	float d = (b*b)-((4*a)*c); //the rest of the program is basically the same as the last quadratic assignment. here i calculate the discriminant.

	//i think the rest is fairly self-explainatory! good luck :)

	if(d<0||((a==0)&&(b==0)&&(c==0)))
	{
 		// when there are 0 roots
		return 0;
	}
	else if(d==0)
	{
 		// when there is 1 root
 		float root1 = (0-b)/(2*a);
  		printf("%8.3f\n", root1 );
		return 1;
	}
	else if(d>0)
	{
 		// when there are 2 roots
 		float root1 = ((0-b)+(sqrt((b*b)-((4*a)*c))))/(2*a);
		float root2 = ((0-b)-(sqrt((b*b)-((4*a)*c))))/(2*a);
 		printf("%8.3f %8.3f\n", root1,root2 );
		return 2;
	}
}
