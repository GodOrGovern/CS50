#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("Usage: ./prime [number]\n");
        return 1;  
    }

    int end = atoi(argv[1]);

    for(int i=2; i <= end; i++)
    {
        bool prime = true;
        for(int j=2; j <= (i/2); j++)
        {
            if(i%j == 0)
            {
                prime = false; 
                break;
            }
        }

        if(prime == true)
        {
            printf("%i\n", i);
        }
    }

    return 0;
}