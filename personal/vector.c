#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float sum_array(float array[], int elements);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./vector [path to file] [# of dimensions]\n");
        return 1;
    }
    
    FILE *data;
    data = fopen(argv[1], "r");

    if (data == NULL)
    {
        printf("Error Reading File\n");
        return 2;
    }

    // counts number of lines in file (equal to number of vectors)
    int ch = 0;
    int number = 0;
    while(!feof(data))
    {
        ch = fgetc(data);
        if(ch == '\n')
        {
            number++;
        }
    }

    int dimension = atoi(argv[2]);
    int crosses = ((number-1)*(number))/2;
    float vector[number][dimension];
    float magnitude[crosses];
    float dot_prod[crosses];
    float results[crosses];
    float buffer[dimension];
    float store_mag[number];

    // stores the vectors in an array
    rewind(data);
    for (int i=0; i < number; i++)
    {
        for (int j=0; j < dimension; j++)
        {
            fscanf(data, "%f,", &vector[i][j]);
        }
    }

    // stores the square of each vector's magnitude in an array
    for (int i=0; i < number; i++)
    {
        for (int j=0; j < dimension; j++)
        {
            buffer[j] = vector[i][j] * vector[i][j];
        }

        store_mag[i] = sum_array(buffer, dimension);
    }

    /* finds all possible dot products and magnitude multiplications (with two vectors)
     uses them to find inner angle, which is stored in an array and immediately printed */
    for (int i=0; i < number; i++)
    {
        for (int j=i+1; j < number; j++)
        {
            int temp = i+j-1;
            for (int k=0; k < dimension; k++)
            {
                buffer[k] = vector[i][k] * vector[j][k];
            }
            
            dot_prod[temp] = sum_array(buffer, dimension);
            magnitude[temp] = sqrtf(store_mag[i]) * sqrtf(store_mag[j]);
            results[temp] = acosf(dot_prod[temp] / magnitude[temp]);

            printf("%i - %i: %f\n", i+1, j+1, results[temp]);
        }
    }

    fclose(data);
    return 0;
}

float sum_array(float array[], int elements)
{
   float sum = 0;
   for (int i=0; i < elements; i++)
   {
	 sum = sum + array[i];
   }

   return(sum);
}