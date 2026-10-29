#include <stdio.h>
#include "utilities.h"

void clearInputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        /* Clear remaining input characters */
    }
}