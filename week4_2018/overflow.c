#include <string.h>

void foo(char *bar)
{
    // potential for buffer overflow
    char c[12];
    memcpy(c, bar, strlen(bar));
}

int main(int argc, char *argv[])
{
    foo(argv[1]);
}