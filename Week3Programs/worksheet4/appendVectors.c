#include <stdio.h>
#include <stdlib.h>

int *ivec_alloc(int);

int main(void)
{
	int vec1[] = {1.0,1.0,1.0,1.0};
	int vec2[] = {2.0,2.0,2.0,2.0,2.0};
	
	int total_size = (sizeof(vec1)+sizeof(vec2))/sizeof(int);
	
	int *a = (int*) calloc(total_size,sizeof(int));
	
	int i = 0;
	int topOfStack = 0;
	
	for(i; i<(sizeof(vec1)/sizeof(int));i++)
	{
		a[topOfStack] = vec1[i];
		topOfStack++;
	}
	i = 0;
	
	for(i; i<(sizeof(vec2)/sizeof(int));i++)
	{
		a[topOfStack] = vec2[i];
		topOfStack++;
	}
	i = 0;
	
	printf("sizeof(a)%d\n",(sizeof(a)));
	
	for(i;i<total_size;i++)
	{
		printf("%d\n",a[i]);
	}
}
