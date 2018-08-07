#include <cs50.h>
#include <stdio.h>
#include <string.h>

#include "struct.h"

int main(void)
{
    // initialize array for students
    int enrollment = get_int("Enrollment: ");
    student students[enrollment];

    // prompt for student information
    for (int i = 0; i < enrollment; i++)
    {
        students[i].name = get_string("Name: ");
        students[i].dorm = get_string("Dorm: ");
    }

    // print student information
    for (int i = 0; i < enrollment; i++)
    {
        print("%s is in %s\n", students[i].name, students[i].dorm);
    }
}