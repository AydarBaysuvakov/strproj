#include <stdio.h>
#include <stdlib.h>

int puts_(const char* str)
    {
    for (; *str; ++str)
        {
        if (putchar(*str) == EOF)
            {
            return EOF;
            }
        }

    putchar('\n');

    return 0;
    }

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

int strlen_( const char *str )
    {
    int size = 0;
    for (; *str; ++str, ++size)
        {
        /* Do nothing */
        }

    return size;
    }

char *strcpy_(char *dest, const char *src)
    {
    char *dest_p_copy = dest;

    while (*dest++ = *src++)
        {
        /* Do nothing */
        }

    return dest_p_copy;
    }

char *strncpy_(char *dest, const char *src, size_t count)
    {
    char *dest_p_copy = dest;

    int i = 1;
    for (; (*dest++ = *src++) && i < count; ++i)
        {
        /* Do nothing */
        }

    for (; i < count; ++i)
        {
        *dest++ = '\0';
        }

    return dest_p_copy;
    }

char *strcat_(char *dest, const char *src)
    {
    char *dest_p_copy = dest;

    dest += strlen_(dest);

    while (*dest++ = *src++)
        {
        /* Do nothing */
        }

    return dest_p_copy;
    }

char *strncat_(char *dest, const char *src, size_t count)
    {
    char *dest_p_copy = dest;

    dest += strlen_(dest);

    int i = 1;
    for (; (*dest++ = *src++) && i < count; ++i)
        {
        /* Do nothingc */
        }

    for (; i < count; ++i)
        {
        *dest++ = '\0';
        }

    return dest_p_copy;
    }

char *fgets_(char *str, int count, FILE *stream)
    {
    char* copy_str_p = str;

    for (int i = 0; (i < count - 1) && ((*str = fgetc(stream)) != EOF); i++, str++)
        {
        if (*str == '\n')
            {
            break;
            }
        }

    *(++str) = '\0';
    return copy_str_p;
    }

char *strdup_( const char *src )
    {
    return strcpy_((char*) calloc(strlen_(src), sizeof(char)), src); // K&R
    }

ssize_t getline_(char **lineptr, size_t *n, FILE *stream)
    {
    int len = 0;
    char* start = *lineptr;

    if (*lineptr == nullptr)
        {
        *lineptr = (char*) malloc(sizeof(char));
        *n = 1;
        }

    char* cur_ch_ptr = *lineptr;

    while ((*cur_ch_ptr = fgetc(stream)) != EOF)
        {
        len++;
        if (len == *n)
            {
            *lineptr = (char*) realloc(*lineptr, len * 2 * sizeof(char));
            *n *= 2;
            }
        if (*cur_ch_ptr == '\n')
            {
            cur_ch_ptr++;
            break;
            }
        cur_ch_ptr++;
        }

    *cur_ch_ptr = '\0';
    return len;
    }

const char *strstr_(const char *str, const char *substr)
    {
    if (!*substr)
        {
        return str;
        }

    const char *reset_p = substr, *last_ch_p = str, *reset_str_p = nullptr;
    while (*substr && *str)
        {
        if (!(str = strchr_(str, *substr++)))
            {
            return NULL;
            }
        if (str - last_ch_p <= 1)
            {
            if (!reset_str_p && *str == *reset_p && str - last_ch_p == 1)
                {
                reset_str_p = str;
                }
            last_ch_p = str;
            }
        else
            {
            if (substr - reset_p != 1)
                {
                substr = reset_p;
                }
            if (reset_str_p)
                {
                str = reset_str_p;
                reset_str_p = nullptr;
                }
            last_ch_p = str;
            }

        str++;
        }

    if (!*substr)
        {
        return str - strlen_(reset_p);
        }

    return NULL;
    }
