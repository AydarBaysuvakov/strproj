#include <stdio.h>

char *strncat_(char *dest, const char *src, size_t count)
    {
    char *dest_p_copy = dest;

    while (*++dest);

    int i = 0;
    for (; (*dest++ = *src++) && i < count; ++i);
    ++i;

    for (; i < count; ++i)
        {
        *dest++ = '\0';
        }

    return dest_p_copy;
    }
