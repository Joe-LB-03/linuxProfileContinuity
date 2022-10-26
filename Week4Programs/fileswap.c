#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc == 5 && fopen(argv[1],"r"))
	{
		FILE *fpr;
		fpr = fopen(argv[1],"r");
		FILE *fpw;
		fpw = fopen(argv[4],"w");
		
		int i,j = 0;
		int newCol = atoi(argv[2]);
		int newRow = atoi(argv[3]);

		int *arr[newRow];
		for(i=0;i<newRow;i++)
		{
			arr[i] = (int*)malloc(newCol * sizeof(int));
		}
		printf("Array created with %d rows and %d columns.\n",newRow,newCol);
		
		for(i = 0;i<newCol;i++)
		{
			for(j=0;j<newRow;j++)
			{
				char buffer[4];
				fgets(buffer,4,fpr);
				printf("%s added to Array at row %d column %d.\n",buffer,j,i);
				arr[j][i] = atoi(buffer);
			}	
		}

		for(i=0;i<newRow;i++)
		{
			for(j=0;j<newCol;j++)
			{
				fprintf(fpw," %d ",arr[i][j]);
			}
			fprintf(fpw,"\n");
		}
	}
	else
	{
		printf("Incorrect number of arguments. Please try again.\n");
	}	
			
}
