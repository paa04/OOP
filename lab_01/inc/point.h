#ifndef POINT_H
#define POINT_H

#include <stdlib.h>

#define EPS 0.001

#define SMALL_SCALE 7

typedef double point_type;

struct point
{
    point_type x_coord,
            y_coord,
            z_coord;
};

typedef point point_t;

struct points
{
    int amount = 0;
    point_t *array = NULL;
};

typedef points point_array_t;

typedef struct
{
    double
            kx,
            ky,
            kz;
} transform_t;

void init_points(point_array_t &arr);

void free_data(point_array_t &arr);

int alloc_points(point_t *&points, int amount);

int move_points(point_array_t &points, transform_t &data);

int find_center_point(point_array_t &points, point_t &center);

int rotate_points(point_array_t &point_array, transform_t &rotate, point_t &center);

int scale_points(point_array_t &point_array, transform_t &scale, point_t &center);

#endif