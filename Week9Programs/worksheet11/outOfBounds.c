
#include <stdio.h>

/*
 * typical out-of-bounds access
 */

int main( void ) {

  int a[] = { 1, 2, 3, 4 };
  int j = 3;

  printf( "%i\n", a[4] );  // accessing a[4] off the end of the array a[0]-a[3]

  return 0;
}
