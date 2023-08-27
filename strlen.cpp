int strlen_( const char *str )
    {
    int size = 0;
    for (; *str; ++str, ++size);

    return size;
    }
