
#include <stdio.h>
#include <stdlib.h>

/*
 * double use of free 
 */

int main( void ) {

  int *a = (int *)calloc( 4, sizeof(int) );

  a[0] = 5; a[1] = 4; a[2] = 3; a[3] = 2;

  free(a);

  free(a); // free() now applied to unallocated pointer

  return 0;
}
