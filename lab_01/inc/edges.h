#ifndef _LINKS_H_
#define _LINKS_H_

#include "point.h"
#include <stdlib.h>

#define WRONG_EDGE 6

typedef int type_id;

typedef struct
{
    type_id point_a,
            point_b;
} edge_t;

typedef struct
{
    int amount = 0;
    edge_t *array = NULL;
} edges_arr_t;

void init_edges(edges_arr_t &arr);

int alloc_edges(edge_t *&edges, int amount);

void free_data(edges_arr_t &arr);

#endif