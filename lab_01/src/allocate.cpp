#include <malloc.h>
#include "allocate.h"

void *alloc(int bytes)
{
    void *p = malloc(bytes);

    return p;
}

void free_mem(void *p)
{
    free(p);
}