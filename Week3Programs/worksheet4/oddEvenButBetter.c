
#include <stdio.h>
#include <stdlib.h>

int main( void ) 
{
	int data[] = { 5, 7, 3, 8, 15, 12, 6,
                      10, 25, 7, 23, 18, 5, 2, 
                      18, 5, 2, 16, 35, 107, 13, 
                      15, 12, 15, 7, 83, 98, 16 };
	
	int i = 0;
	int *e = (int*)calloc(1,sizeof(int));
	int *o = (int*)calloc(1,sizeof(int));
	int sizeOfE = 0;
	int sizeOfO = 0;
	
	printf("data[0] for testing: %d\n\n",data[0]);

	for(i = 0;i<(sizeof(data)/sizeof(int));i++)
	{
		printf("Sorting item %d of data[]: %d\n\n",i, data[i]);

		if((data[i]%2)==0)
		{
			printf("%d added to Evens\n\n",data[i]);
			e = (int*)realloc(e,(sizeOfE+1));
			e[sizeOfE] = data[i];
			sizeOfE++;				
		}	
		else
		{
			printf("%d added to Odds\n\n",data[i]);
			o = (int*)realloc(o,(sizeOfO+1));
			o[sizeOfO] = data[i];
			sizeOfO++;
		}
	}

	printf("There are %d Odds:\n",sizeOfO);
	printf("There are %d Evens:\n",sizeOfE);
 	return 0;
}
