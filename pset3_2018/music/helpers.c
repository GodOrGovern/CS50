// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    float numerator = fraction[0] - '0';
    float denominator = fraction[2] - '0';
    float result = numerator / denominator;

    return result / 0.125;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int length = strlen(note);
    int semi[7] = {9, 11, 0, 2, 4, 5, 7};
    int pitch[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, -1};
    float buffer = semi[note[0] - 65];

    if (length == 2)
    {
        buffer += (note[1] - 49) * 12;
    }

    else
    {
        buffer += pitch[(note[1] / 7) - 5] + (note[2] - 49) * 12;
    }

    int result = round(pow(2, (buffer - 45) / 12) * 440);
    return result;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (!(strcmp(s, "")))
    {
        return true;
    }

    else
    {
        return false;
    }
}
