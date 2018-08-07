#include <cs50.h>
#include <stdio.h>

#include "struct.h"

bool search(int n, node *tree);

int main(void)
{

}

bool search(int n, node *tree)
{
    if (tree == NULL)
    {
        return false;
    }

    else if (n < tree->n)
    {
        return search(n, tree->left);
    }

    else if (n > tree->n)
    {
        return search(n, tree->right);
    }

    else
    {
        return true;
    }
}