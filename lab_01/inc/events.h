//
// Created by paa04 on 19.03.24.
//

#ifndef EVENTS_H
#define EVENTS_H
#include <figure.h>

#include "draw.h"

typedef struct
{
    const char *filename;
} load_data_t;

typedef struct
{
    painter_t painter;
} draw_data_t;

typedef struct
{
    transform_t move_data;
} move_data_t;

typedef struct
{
    point_t center;
} find_center_data_t;

typedef struct
{
    point_t center;
} center_data_t;

typedef struct
{
    transform_t rotate_data;
    point_t center;
} rotate_data_t;

typedef struct
{
    transform_t scale;
    point_t center;
} scale_data_t;

typedef struct
{
    const char *filename;
} save_data_t;

void fill_load_data(load_data_t &data, const char *filename);
void fill_draw_data(draw_data_t &data, painter_t &painter);
void fill_move_data(move_data_t &data, transform_t &transform);
void fill_center_data(center_data_t &data, point_t &center);
void fill_rotate_data(rotate_data_t &data, transform_t &transform, point_t &center);
void fill_scale_data(scale_data_t &data, transform_t &scale, point_t &center);
void fill_save_data(save_data_t &data, const char *filename);
void retrieve_center_request(find_center_data_t &data, point_t &center);
int load(figure_t &figure, load_data_t &data);
int draw(figure_t &figure, draw_data_t &data);
int move(figure_t &figure, move_data_t &data);
int rotate(figure_t &figure, rotate_data_t &data);
int find_center(figure &figure, find_center_data_t &data);
int center(figure &figure, center_data_t &center_data);
int scale(figure &figure, scale_data_t &scale_data);
int save_backup_event(figure &figure);
int load_backup_event(figure& figure);
int save(figure &figure, save_data_t &data);

typedef struct
{
    int task;
    union
    {
        load_data_t load_data;
        draw_data_t draw_data;
        move_data_t move_data;
        find_center_data_t find_center_data;
        center_data_t center_data;
        rotate_data_t rotate_data;
        scale_data_t scale_data;
        save_data_t save_data;
    };
} request_t;

#endif //EVENTS_H
