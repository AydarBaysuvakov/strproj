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
        /* Do nothing */
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

    for (int i = 0; (i < count - 1) && ((*str = getc(stream)) != EOF); i++, str++) // fgetc???
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

//todo:
//strstr
//getline
