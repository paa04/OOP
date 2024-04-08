#ifndef IO_H
#define IO_H

#include "figure.h"
#include <stdio.h>

#define FILE_DATA_ERROR 2
#define OPEN_FILE_ERROR 3

int load_figure(figure &figure ,const char* file_name);
int save_edges(edges_arr_t& edges_arr, FILE* file);
int save_points(point_array_t& point_array, FILE* file);

#endif