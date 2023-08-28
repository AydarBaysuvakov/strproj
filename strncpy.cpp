char *strncpy_(char *dest, const char *src, size_t count)
    {
    int i = 0;
    for (; src[i] && i < count; ++i)
        {
        dest[i] = src[i];
        }
    for (; i < count; ++i)
        {
        dest[i] = '\0';
        }

    return dest;
    }
