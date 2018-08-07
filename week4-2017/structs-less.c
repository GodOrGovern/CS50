#include <stdio.h>
#include <cs50.h>
#include "stdnt.h"

#define STDNT 3

int main(void)
{
    stdnt student[STDNT];
    for (int i = 0; i < STDNT; i++)
    {
        printf("Name: ");
        student[i].name = get_string();
        printf("Dorm of %s: ", student[i].name);
        student[i].dorm = get_string();
        printf("\n");
    }

    for (int n = 0; n < STDNT; n++)
    {
        printf("%s is in %s\n", student[n].name, student[n].dorm);
    }

    return 0;
}