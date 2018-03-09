#include <stdio.h>
#include <cs50.h>

void print_name(string name);

int main(void)
{
    printf("What is your name? ");
    string s = get_string();
    print_name(s);
}

void print_name(string name)
{
    printf("Hello %s\n", name);
}