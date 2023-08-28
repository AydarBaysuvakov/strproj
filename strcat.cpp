char *strcat_(char *dest, const char *src)
    {
    int i = 0;
    for (; dest[i]; ++i);

    int j = 0;
    for (; src[j]; ++i, ++j)
        {
        dest[i] = src[j];
        }

    dest[i] = '\0';

    return dest;
    }
