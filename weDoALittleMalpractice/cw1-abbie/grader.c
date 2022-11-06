
/*
 * Template file for the solution to part 1
 * Use the included print statements in your code at appropriate times.
 * Do not adjust the format of the print statements.
 * Do not submit a final solution with additional print statements.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main( int argc, char **argv ){
	FILE *fp;
	// verify command line arguments
	if(argc != 2){
  		printf("No input file name given. Exiting.\n"); //checks if you have 2 arguments as specified (executable and results source file)
		return 0;
	}
	if(!(fopen(argv[1],"r"))){
  		printf("Input file does not exist. Exiting.\n"); //checks to see if the given source file exists and is readable
  	}

  	// reading from file
 	printf("Input file. Opening.\n");

	fp = fopen(argv[1],"r"); //as before, initiate pointer

	/* the idea here is you basically wanna read each record from the results file and store it in a format that lets you check the data as below
    my idea of how this should be done is basically repeat 32 times: read each line as "%d %d %d %d" and allocate each read value as it corresponds
    to a place in a big RESULTS array. I did this with an array size 32x6, so 32 records and 6 values in each. these six values were the student id,
    then the four grades, then the final average that is allocated later.*/

 	printf("Input file. Closing.\n");
	fclose(fp); //close the pointer

 	// data processing
	printf("Checking data.\n");
	for(i = 0; i < 32; i++){

        //here, i basically iterate through every record in the array and check each value as needed. so for example, first i check the IDs are valid.
		//if invalid, i print the below
            printf("Found an invalid student id: %d. Exiting.\n",id); // requires student id
        
		//then, we have to check each individual grade is both correct and amend any anomalous scores as the spec details.
        //so, we use a nested FOR loop to count from results[i][1] to results[i][4] since those are the only values we care about.
		
        //if the grade is not between 1 and 100, print the below
  				printf("Found an invalid grade: id %d grade %d. Exiting.\n", id,grade ); // requires student id and relevant grade

		//if the grade is lower than 20, print amend and print as below
				results[i][j] = 20;
				printf("Correcting student %d grade %d\n",id,grade); // requires student id and relevant grade
        
        //if the grade is greater than 90, amend and print as below
				results[i][j] = 90;
				printf("Correcting student %d grade %d\n",id,grade); // requires student id and relevant grade
	}

  	// compute averages
 	printf("Computing averages.\n");
	
	//finally, calculate the average of the corrected scores and store in the final 6th location in the results array.
    //this can be done with a function you write, or with the math.h roundf() function to round a float.
    //this of course also needs to be done for every record.

 	// writing to file
 	printf("Output file. Opening.\n");
	
	fp = fopen("averages.txt","w"); //open the new pointer for writing and specify the new filename (will overwrite!)

	for(i = 0; i < 32; i++){
		fprintf(fp,"%d %d\n",results[i][0],results[i][5]); //i'll give you this bit. basically prints out the student ID and average followed by a newline.
	}

	printf("Output file. Closing.\n");
	fclose(fp); //close the pointer once more
	
 	return 0;
}
