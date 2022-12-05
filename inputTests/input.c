#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void basicScanf();
void bufferAndFgets();
int fgetsAndValidation();

int main (void)
{
    basicScanf();
    //bufferAndFgets();
    //fgetsAndValidation();
}

void basicScanf()
{
    int x,y;
       printf("\nPleae enter two digits with one space between them\n");
    scanf("%d %d",&x,&y);
}

void bufferAndFgets()
{
    int x,y;
    char buff[4*sizeof(char)];
    printf("\nPleae enter two digits with one space between them\n");
    fgets(buff, 4*sizeof(char), stdin);
    printf("%s\n",buff);
    fgets(buff,100,stdin);
}

int fgetsAndValidation()
{
    char str[100] = {0};
    int x,y;
    int digits = 0;
    printf("Enter two numbers with a space between: ");
    fgets(str, 100, stdin);

    for(int i = 0; i < 100; i++)
    {
        if(isdigit(str[i]))
        {
            digits++;
        }
        if(!isdigit(str[i]) && (!isspace(str[i])) && (str[i] != '\0'))
        {
            if((i != 0) && (str[i - 1] != ' ') || (str[i] == ' ' && str[i-1] == ' '))
            {
                printf("'%c' is bogus! I'm self destructing!\n", str[i]);
                return -1;
            }
        }

        if((str[i] == '\n') || (str[i] == '\0'))
        {
            break;
        }
    }
    if(digits != 2)
    {
        printf("Wrong number of arguments lol.\n");
        return -1;
    }
    sscanf(str, "%d%d", &x, &y);
    printf("You entered %d and %d. Good job.  Pat yourself on the back.\n", x, y);

}