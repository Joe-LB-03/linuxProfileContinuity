#include <stdio.h>

int main(void)
{
	int first[4][4];
	int second[4][4];
	int result[4][4];
	int i = 0;
	
	for(i; i<4; i++)
	{
		int j = 0;

		for(j; j<4; j++)
		{
			first[i][j] = ((2*i)-j);
			second[i][j] = (3 + j) - (2*i);
			result[i][j] = first[i][j] + second[i][j];
		}
		printf("%d %d %d %d\n",result[i][0],result[i][1],result[i][2],result[i][3]);
	}
		
	return 0;
}
