
#include <stdio.h>

int main( void ) 
{
	int data[] = { 5, 7, 3, 8, 15, 12, 6,
                      10, 25, 7, 23, 18, 5, 2, 
                      18, 5, 2, 16, 35, 107, 13, 
                      15, 12, 15, 7, 83, 98, 16 };
	
	int odd[28];
	int i = 0;
	int even[28];
	int numberOfOdds = 0;
	int numberOfEvens = 0;
	for(i; i<28; i++)
	{
		if((data[i]%2)==0)
		{
			even[i] = data[i];
			numberOfEvens++;
		}
		else
		{
			odd[i] = data[i];
			numberOfOdds++;
		}
	}
	printf("There are %d Odds and %d Evens\n",numberOfOdds,numberOfEvens);
	return 0;
}
