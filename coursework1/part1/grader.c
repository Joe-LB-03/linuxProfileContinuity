
/*
 * Template file for the solution to part 1
 * Use the included print statements in your code at appropriate times.
 * Do not adjust the format of the print statements.
 * Do not submit a final solution with additional print statements.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
	int i;
	int id, score1, score2, score3, score4;
	for(i = 0; i < 32; i++)
	{
		results[i] = (int*)malloc(6*sizeof(int));
	}

	for(i = 0; i < 32; i++)
	{
		fscanf(fp, "%d %d %d %d %d", &id, &score1, &score2, &score3, &score4);
		results[i][0] = id;
		results[i][1] = score1;
		results[i][2] = score2;
		results[i][3] = score3;
		results[i][4] = score4;
	}

 	printf("Input file. Closing.\n");
	fclose(fp);

 	// data processing
	printf("Checking data.\n");
	int j;
	for(i = 0; i < 32; i++)
	{
		id = results[i][0];	
		if(id < 2022000 || id > 2022099)
		{
 			printf("Found an invalid student id: %d. Exiting.\n",id); // requires student id
			return 0;
		}

		for(j = 1; i <5; i++)
		{
			int grade = results[i][j];
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
		float average = roundf(((float)results[i][1]+(float)results[i][2]+(float)results[i][3]+(float)results[i][4])/4);
		results[i][5] = (int)average;
	}

 	// writing to file
 	printf("Output file. Opening.\n");
	
	fp = fopen("averages.txt","w");

	for(i = 0; i < 32; i++)
	{
		fprintf(fp,"%d %d\n",results[i][0],results[i][5]);
	}

	printf("Output file. Closing.\n");
	fclose(fp);
	
 	return 0;
}
