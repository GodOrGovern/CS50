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

    FILE * file = fopen("students.csv", "w");

    if (file != NULL)
    {
        for (int n = 0; n < STDNT; n++)
        {
            fprintf(file, "%s, %s\n", student[n].name, student[n].dorm);
        }

        fclose(file);
    }

    return 0;
}