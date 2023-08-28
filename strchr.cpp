const char *strchr_(const char *str, int ch)
    {
    for (; *str; ++str)
        {
        if (*str == ch)
            {
            return str;
            }
        }

    return NULL;
    }
