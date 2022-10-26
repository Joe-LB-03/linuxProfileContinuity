#include<stdio.h>
#include<math.h>

int main(void)
{
	long Ndays = 0;
	int Day = 1;
	int Month = 1;
	int Year = 2000;
	int x;
	
	scanf("%d",&x);
	Ndays += 20L * 20L * 18L * 20L * (x-13L);

	scanf("%d",&x);
	Ndays += 20L * 18L * 20L * (x-20L);

	scanf("%d",&x);
	Ndays += 18L * 20L * (x-7L);

	scanf("%d",&x);
	Ndays += 20L * (x-16L);

	scanf("%d",&x);
	Ndays += (x-3L);

	printf("Number of days since 1 1 2000: %ld\n", Ndays);

	do
	{
		if(Ndays >= 31)
		{
			Ndays -= 31;
			Month++;
		}
		if(Year%4 == 0)
		{
			if(Ndays >= 29)
			{
				Ndays -= 29;
				Month++;
			}
		}
		else
		{
			if(Ndays >= 28)
			{
				Ndays -= 28;
				Month++;
			}
		}
		if( Ndays >= 31 ) 
		{
			Ndays -= 31; Month++; 
		}			/* Mar */
		if( Ndays >= 30 ) 
		{ 
			Ndays -= 30; Month++; }			/* Apr */
		if( Ndays >= 31 ) 
		{
			 Ndays -= 31; Month++; 
		}			/* May */
		if( Ndays >= 30 ) 
		{
			 Ndays -= 30; Month++; 
		}			/* Jun */
		if( Ndays >= 31 ) 
		{
			Ndays -= 31; Month++; 
		}			/* Jul */
		if( Ndays >= 31 ) 
		{
			Ndays -= 31; Month++; 
		}			/* Aug */
		if( Ndays >= 30 ) 
		{
			Ndays -= 30; Month++; 
		}			/* Sept */
		if( Ndays >= 31 ) 
		{
		Ndays -= 31; Month++; 
		}			/* Oct */
		if( Ndays >= 30 ) 
		{ 
			Ndays -= 30; Month++; 
		}			/* Nov */
		if( Ndays >= 31 ) 
		{ 
			Ndays -= 31; Month = 1; Year++; 
		}			/* Dec */
	} while( Ndays >= 31 );
	Day += Ndays;
	printf("%d %d %d\n", Day, Month, Year);
}
