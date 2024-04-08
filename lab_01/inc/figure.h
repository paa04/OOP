#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"
#include "edges.h"

#define MAX_NAME_LEN 128

#define INCORECT_FILE_NAME 10
#define FILE_WORK_ERR 11

struct figure
{
    char *name;
    point_array_t points;
    edges_arr_t edges;
};

typedef figure figure_t;

figure_t &init_figure(void);

figure_t &init_figure(const char *name);

void destroy_figure(figure_t &figure);

void destroy_name(char *name);

int move_figure(figure_t &figure, transform_t &transform);

int center_figure(figure_t &figure, point_t &center);

int rotate_figure(figure_t &figure, transform_t &rotate, point_t &center);

int scale_figure(figure_t &figure, transform_t &scale, point_t &center);

int save_figure(figure_t &figure, const char *filename);

#endif