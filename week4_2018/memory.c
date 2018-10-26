#include <stdlib.h>

void f(void)
{
    // buffer overflow and memory leak
    int *x = malloc(10 * sizeof(int));
    x[10] = 0;
}

int main(void)
{
    f();
    return 0;
}