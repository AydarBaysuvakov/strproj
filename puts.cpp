#include <stdio.h>

int puts_(const char* str)
    {
    for (; *str; ++str)
        {
        if (putchar(*str) == EOF)
            {
            perror("puts_()");
            return EOF;
            }
        }

    putchar('\n');

    return 0;
    }
