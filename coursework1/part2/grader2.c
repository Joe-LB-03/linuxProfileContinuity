#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int roundNum(float);

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
		return 0;
	}

	if(atoi(argv[2]) > 8 || atoi(argv[2]) < 1)
	{
  		printf("Requires 1 to 8 grades. Exiting.\n");
		return 0;
	}

  	if(!(fopen(argv[3],"r")))
	{
		printf("Input file does not exist. Exiting.\n");
		return 0;
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
		for(j = 1; j <= atoi(argv[2]); j++)
		{
			fscanf(fp, " %d", &results[i][j]);
		}	
	}

  	printf("Input file. Closing.\n");
	fclose(fp);

  	// data processing
  	printf("Checking data.\n");

	for(i = 0; i < atoi(argv[1]); i++)
	{
		int id = results[i][0];
		if(id < 2022000 || id > 2022099)
		{
  			printf("Found an invalid student id: %d. Exiting.\n", id ); // requires student id
			return 0;
		}

		for(j = 1; j < atoi(argv[2]); j++)
		{
			int grade = results[i][j];
			if((grade > 100 || grade < 1)&&(grade != -1))
			{
  				printf("Found an invalid grade: id %d grade %d. Exiting.\n", id,grade ); // requires student id and relevant grade
				return 0;
			}
			if(grade < 20 && grade != -1)
			{
				results[i][j] = 20;
				printf("Correcting student %d grade %d\n", id,grade ); // requires student id and relevant grade
			}
			if(grade > 90)
			{
				results[i][j] = 90;
				printf("Correcting student %d grade %d\n", id,grade ); // requires student id and relevant grade
			}
		}
	}

  	// compute averages
  	printf("Computing averages.\n");

	for(i = 0; i < atoi(argv[1]); i++)
	{
		int itemsToCount = 0;
		int total = 0;
		for(j = 1; j <= atoi(argv[2]); j++)
		{
			if(results[i][j] != -1)
			{
				itemsToCount++;
			}
			else
			{
				results[i][j] = 0;
			}
			total = total + results[i][j];
		}
		int average = roundNum((float)total/(float)itemsToCount);
		results[i][atoi(argv[2])+1] = (int)average;

	}

 	// writing to file
  	printf("Output file. Opening.\n");

	fp = fopen("averages.txt","w");

	for(i = 0; i < atoi(argv[1]); i++)
	{
		fprintf(fp,"%d %d\n",results[i][0],results[i][atoi(argv[2])+1]);
	}

	printf("Output file. Closing.\n");
	fclose(fp);

	return 0;
}

int roundNum(float num)
{
	return (int) (num < 0 ? num - 0.5 : num + 0.5);
}

