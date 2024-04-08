//
// Created by paa04 on 19.03.24.
//
#include "events.h"
#include "figure.h"
#include "io.h"
#include "backup.h"

void fill_load_data(load_data_t &data, const char *filename)
{
    data.filename = filename;
}

void fill_draw_data(draw_data_t &data, painter_t &painter)
{
    data.painter = painter;
}

void fill_move_data(move_data_t &data, transform_t &transform)
{
    data.move_data = transform;
}

void fill_center_data(center_data_t &data, point_t &center)
{
    data.center = center;
}

void fill_rotate_data(rotate_data_t &data, transform_t &transform, point_t &center)
{
    data.rotate_data = transform;
    data.center = center;
}

void fill_scale_data(scale_data_t &data, transform_t &scale, point_t &center)
{
    data.scale = scale;
    data.center = center;
}

void fill_save_data(save_data_t &data, const char *filename)
{
    data.filename = filename;
}


void retrieve_center_request(find_center_data_t &data, point_t &center)
{
    center = data.center;
}

int center(figure &figure, center_data_t &center_data)
{
    return center_figure(figure, center_data.center);
}

int find_center(figure &figure, find_center_data_t &data)
{
    return find_center_point(figure.points, data.center);
}

int load(figure_t &figure, load_data_t &data)
{
    return load_figure(figure, data.filename);
}

int draw(figure_t &figure, draw_data_t &data)
{
    return draw_figure(data.painter, figure);
}

int move(figure_t &figure, move_data_t &data)
{
    return move_figure(figure, data.move_data);
}

int rotate(figure_t &figure, rotate_data_t &data)
{
    return rotate_figure(figure, data.rotate_data, data.center);
}

int scale(figure &figure, scale_data_t &scale_data)
{
    return scale_figure(figure, scale_data.scale, scale_data.center);
}

int save_backup_event(figure &figure)
{
    return save_backup(figure);
}

int load_backup_event(figure &figure)
{
    return load_backup(figure);
}

int save(figure &figure, save_data_t &data)
{
    return save_figure(figure, data.filename);
}
