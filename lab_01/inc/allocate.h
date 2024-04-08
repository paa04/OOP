#ifndef ALLOCATE_H
#define ALLOCATE_H

#define ALLOCATE_ERROR 1

void *alloc(int bytes);

void free_mem(void *p);

#endif