char *strcat_(char *dest, const char *src)
    {
    char *dest_p_copy = dest;

    while (*++dest);

    while (*dest++ = *src++);

    return dest_p_copy;
    }
