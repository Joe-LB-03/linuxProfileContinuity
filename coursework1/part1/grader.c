
/*
 * Template file for the solution to part 1
 * Use the included print statements in your code at appropriate times.
 * Do not adjust the format of the print statements.
 * Do not submit a final solution with additional print statements.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int roundNo(float);

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
		return 0;
  	}

  	// reading from file
 	printf("Input file. Opening.\n");
	fp = fopen(argv[1],"r");
	int* results[32];
	int i, j;
	int reading[5];
	for(i = 0; i < 32; i++)
	{
		results[i] = (int*)malloc(6*sizeof(int));
	}
	for(i = 0; i < 32; i++)
	{
		fscanf(fp, " %d %d %d %d %d", &reading[0], &reading[1], &reading[2], &reading[3], &reading[4]);
		results[i][0] = reading[0];
		results[i][1] = reading[1];
		results[i][2] = reading[2];
		results[i][3] = reading[3];
		results[i][4] = reading[4];
	}

 	printf("Input file. Closing.\n");
	fclose(fp);

 	// data processing
	printf("Checking data.\n");
	for(i = 0; i < 32; i++)
	{
		int id = results[i][0];	
		if(id < 2022000 || id > 2022099)
		{
 			printf("Found an invalid student id: %d. Exiting.\n",id); // requires student id
			return 0;
		}
		
		for(j = 1; j < 5; j++)
		{
			int grade = results[i][j];

			if((grade > 100 || grade < 1))
			{
  				printf("Found an invalid grade: id %d grade %d. Exiting.\n", id,grade ); // requires student id and relevant grade
				return 0;
			}

			if(grade<20)
			{	
				results[i][j] = 20;
				printf("Correcting student %d grade %d\n",id,grade); // requires student id and relevant grade
			}
			if(grade>90)
			{
				results[i][j] = 90;
				printf("Correcting student %d grade %d\n",id,grade); // requires student id and relevant grade
			}
		}
	}
  	// compute averages
 	printf("Computing averages.\n");
	
	for(i = 0; i < 32; i++)
	{
		int average = roundNo(((float)results[i][1]+(float)results[i][2]+(float)results[i][3]+(float)results[i][4])/4);
		results[i][5] = average;
	}

 	// writing to file
 	printf("Output file. Opening.\n");
	
	fp = fopen("averages.txt","w");

	for(i = 0; i < 32; i++)
	{
		fprintf(fp," %d %d\n",results[i][0],results[i][5]);
	}

	printf("Output file. Closing.\n");
	fclose(fp);
	
 	return 0;
}

int roundNo(float num)
{
	return (int) (num < 0 ? num - 0.5 : num + 0.5);
}
