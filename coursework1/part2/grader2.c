#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int roundNum(float); //header for custom round function

int main( int argc, char **argv ) 
{
	FILE *fp;
	// command line arguments
	//verify the correct number of arguments has been provided
  	if(argc != 4)
	{
		printf("Incorrect arguments given. Expecting nStudents nGrades fileName. Exiting.\n");
		return 0;
	}
	//verify the arguments provided are valid
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
	//verify the specidfied input file is accessible
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
	//create the array required to store the data using the quantities provided in the command line arguments
	for(i = 0; i < atoi(argv[1]); i++)
	{
		results[i] = (int*)malloc((atoi(argv[2])+2)*sizeof(int));
	}
	//read data from file
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
		//verify student ids are valid
		if(id < 2022000 || id > 2022099)
		{
  			printf("Found an invalid student id: %d. Exiting.\n", id ); // requires student id
			return 0;
		}
		//verify each grade is valid and correct where needed
		for(j = 1; j < atoi(argv[2]); j++)
		{
			int grade = results[i][j];
			if((grade > 100 || grade < 0)&&(grade != -1)) //account for possible -1 case
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
	//compute average grade for each student
	for(i = 0; i < atoi(argv[1]); i++)
	{
		int itemsToCount = 0;
		int total = 0;
		int average = 0;
		//count the number of grades to include in the average calculation (non -1 cases)
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
		if(itemsToCount == 0) //if no valid grades, average 0.
		{
			average = 0;
		}
		else //otherwise, calculate average with total divided by the number of valid grades
		{
			average = roundNum((float)total/(float)itemsToCount);
		}
		results[i][atoi(argv[2])+1] = (int)average;
	}

 	// writing to file
  	printf("Output file. Opening.\n");

	fp = fopen("averages.txt","w");
	//write the student ids and associated averages to the output file
	for(i = 0; i < atoi(argv[1]); i++)
	{
		fprintf(fp," %d %d\n",results[i][0],results[i][atoi(argv[2])+1]);
	}

	printf("Output file. Closing.\n");
	fclose(fp);

	return 0;
}
//custom round function
int roundNum(float num)
{
	return (int) (num < 0 ? num - 0.5 : num + 0.5);
}
