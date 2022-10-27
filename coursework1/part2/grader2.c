#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( int argc, char **argv ) 
{
	FILE *fp;

	// command line arguments
  	if(argc != 4)
	{
		printf("Incorrect arguments given. Expecting nStudents nGrades fileName. Exiting.\n");
		return 0;
	}
	
	if(atoi(argv[1]) > 100 || atoi(argv[1]) < 1)
	{
		printf("Requires 1 to 100 students. Exiting.\n");
	}

	if(atoi(argv[2]) > 8 || atoi(argv[2]) < 1)
	{
  		printf("Requires 1 to 8 grades. Exiting.\n");
	}

  	if(!(fopen(argv[3],"r")))
	{
		printf("Input file does not exist. Exiting.\n");
	}

	// reading from file
  	printf("Input file. Opening.\n");
	
	fp = fopen(argv[3],"r");
	
	int* results[atoi(argv[1])];
	int i;
	int j;

	for(i = 0; i < atoi(argv[1]); i++)
	{
		results[i] = (int*)malloc((atoi(argv[2])+2)*sizeof(int));
	}

	for(i = 0; i < atoi(argv[1]); i++)
	{
		fscanf(fp, "%d", &results[i][0]);
		for(j = 1; j < atoi(argv[2]); j++)
		{
			fscanf(fp, " %d", &results[i][j]);
		}	
	}

  	printf("Input file. Closing.\n");
	fclose(fp);

  	// data processing
  	printf("Checking data.\n");
  	printf("Found an invalid student id: %d. Exiting.\n", id ); // requires student id
  	printf("Found an invalid grade: id %d grade %d. Exiting.\n", id,grade ); // requires student id and relevant grade
  	printf("Correcting student %d grade %d\n", id,grade ); // requires student id and relevant grade
  	// compute averages
	
  	printf("Computing averages.\n");

 	// writing to file
  	printf("Output file. Opening.\n");
	printf("Output file. Closing.\n");

	return 0;
}

