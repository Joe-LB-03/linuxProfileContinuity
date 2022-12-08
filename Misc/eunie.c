#include <stdio.h>
#include <time.h>
#define MAX_LEN 128

void print_image(FILE *fptr);

void delay(int number_of_seconds);

int main(void)
{
	printf("EUNIE'S DA BOSS!\n");
	delay(1);
	char *filename = "image.txt";
	FILE *fptr = NULL;
	
	if((fptr = fopen(filename,"r")) == NULL)
	{
		fprintf(stderr,"error opening %s\n",filename);
		return 1;
	}

	print_image(fptr);
	fclose(fptr);
	delay(1);
	printf("\nHear that, Noah? Lanz wants something a bit meatier.\n");
	return 0;
}

void print_image(FILE *fptr)
{
	char read_string[MAX_LEN];

	while(fgets(read_string,sizeof(read_string),fptr) != NULL)
	{
		printf("%s",read_string);
	}
}

void delay(int number_of_seconds)
{
	int milli_seconds = CLOCKS_PER_SEC * number_of_seconds;
	clock_t start_time = clock();
	while(clock() < start_time + milli_seconds);
}
