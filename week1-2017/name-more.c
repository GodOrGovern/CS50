#include <stdio.h>
#include <cs50.h>

void print_name(char *name);

int main(void)
{
    printf("What is your name? ");
    char *name = get_string();
    print_name(name);
}

void print_name(char *name)
{
    printf("Hello %s\n", name);
}