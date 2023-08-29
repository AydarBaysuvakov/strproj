#include <stdlib.h>
#include "strlen.h"
#include "strcpy.h"

char *strdup_( const char *src )
    {
    return strcpy_((char*) calloc(strlen_(src), sizeof *src), src);
    }
