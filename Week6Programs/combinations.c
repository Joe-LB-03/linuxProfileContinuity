#include <stdio.h>
#include <stdlib.h>

int factorial(int);
int combinations( int n, int k );

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Incorrect usage. Correct usage: ./combinations nTotal nSample\n");
        return 0;
    }

    int nTotal = atoi(argv[1]);
    int nSample = atoi(argv[2]);

    if(nTotal<nSample)
    {
        printf("Error. Exiting.\n");
        return 0;
    }

    printf("Combination: %d\n", combinations(nTotal,nSample));
}

int factorial( int n ) 
{
        int i;
        int f = 1; // initialise f
        for( i=2; i<=n; ++i ) 
        {
            f = f*i; // accumulate f
        }
        return f; // return the result
}

int combinations( int n, int k )
{
    int comb;
    comb = factorial(n)/(factorial(k)*factorial(n-k));
    return comb;
}