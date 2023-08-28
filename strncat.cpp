#include <stdio.h>

char *strncat_(char *dest, const char *src, size_t count)
    {
    int i = 0;
    for (; dest[i]; ++i);

    int j = 0;
    for (; src[j] && j < count; ++i, ++j)
        {
        dest[i] = src[j];
        }

    for (; j < count; ++j, ++i)
        {
        dest[i] = '\0';
        }

    dest[i] = '\0';

    return dest;
    }
