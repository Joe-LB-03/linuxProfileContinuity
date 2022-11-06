
#include <stdio.h>

int main( void )
{
	int data[] = { 0, 4, 4, 4, 0,
                       1, 0, 1, 2, 1,
                       2, 2, 1, 2, 4,
                       1, 4, 4, 0, 2,
                       2, 2, 2, 4, 4 };
	
	int frequency[] = {0, 0, 0, 0, 0};

	int i = 0;
	for(i;i<25;i++)
	{
		frequency[data[i]]++;
	}
	
	printf("There are %d 0s, %d 1s, %d 2s, %d 3s and %d 4s.\n", frequency[0], frequency[1], frequency[2], frequency[3], frequency[4]);
	
 	return 0;
}
