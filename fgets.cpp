#include <stdio.h>

char *fgets_(char *str, int count, FILE *stream)
    {
    char* copy_str_p = str;

    for (int i = 0; (i < count - 1) && ((*str = getc(stream)) != EOF);i++, str++)
        {
        if (*str == '\n')
            {
            break;
            }
        }

    *++str = '\0';
    return copy_str_p;
    }
