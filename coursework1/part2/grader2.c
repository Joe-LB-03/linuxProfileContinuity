
#include <stdio.h>

int main( int argc, char **argv ) {

  // command line arguments
  printf("Incorrect arguments given. Expecting nStudents nGrades fileName. Exiting.\n");
  printf("Requires 1 to 100 students. Exiting.\n");
  printf("Requires 1 to 8 grades. Exiting.\n");
  printf("Input file does not exist. Exiting.\n");

  // reading from file
  printf("Input file. Opening.\n");
  printf("Input file. Closing.\n");

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

