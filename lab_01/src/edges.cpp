#include "edges.h"
#include "allocate.h"


void init_edges(edges_arr_t &arr)
{
    arr.amount = 0;
    arr.array = NULL;
}

int alloc_edges(edge_t *&edges, int amount)
{
    edges = static_cast<edge_t *>(alloc(amount * sizeof(edge_t)));

    if (edges == NULL)
        return ALLOCATE_ERROR;

    return EXIT_SUCCESS;
}

void free_data(edges_arr_t &arr)
{
    arr.amount = 0;
    free_mem(arr.array);
}