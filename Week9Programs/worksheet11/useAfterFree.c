
#include <stdio.h>
#include <stdlib.h>

/*
 * accessing heap memory after free()
 */

int main( void ) {

  int *a = (int *)calloc( 4, sizeof(int) );

  a[0] = 5; a[1] = 4; a[2] = 3; a[3] = 2;

  free(a); // deallocate heap memory

  printf( "%i\n", a[1] ); // now try and access a value from the array

  return 0;
}
