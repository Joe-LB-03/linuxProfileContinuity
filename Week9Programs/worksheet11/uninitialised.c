
#include <stdio.h>

/*
 * using uninitialised data values
 */

int main( void ) {

  int i, j;  // i and j are declared but not intialised

  j = i + 3;  // assign value to j using (uninitialised) value of i

  printf( "%i\n", j );

  return 0;
}
