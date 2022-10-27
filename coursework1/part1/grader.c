
/*
 * Template file for the solution to part 1
 * Use the included print statements in your code at appropriate times.
 * Do not adjust the format of the print statements.
 * Do not submit a final solution with additional print statements.
 */

#include <stdlib.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	FILE *fp;
	// command line arguments
	if(argc != 2)
	{
  		printf("No input file name given. Exiting.\n");
		return 0;
	}
	if(!(fopen(argv[1],"r")))
	{
  		printf("Input file does not exist. Exiting.\n");
  	}

  	// reading from file
 	printf("Input file. Opening.\n");
	fp = fopen(argv[1],"r");
	
	int* results[32];
	int i, id, score1, score2, score3, score4;
	
	for(i = 0; i < 32; i++)
	{
		arr[i] = (int*)malloc(2*sizeof(int));
	}

	for(i = 0; i < 32; i++)
	{
		fscanf(fp, "%d %d %d %d",id,score1,score2,score3,score4);
		results[i][0] = id;
		results[i][1] = round((score1+score2+score3+score4)/4); //NEED TO MAKE ROUND FUNCTION DO THAT NEXT
	}	


 	printf("Input file. Closing.\n");
	fclose(fp);

  // data processing
  printf("Checking data.\n");
  printf("Found an invalid student id: %d. Exiting.\n",id); // requires student id
  printf("Correcting student %d grade %d\n",id,grade); // requires student id and relevant grade

  // compute averages
  printf("Computing averages.\n");

  // writing to file
  printf("Output file. Opening.\n");
  printf("Output file. Closing.\n");

  return 0;
}

