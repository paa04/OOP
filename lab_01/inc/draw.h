//
// Created by paa04 on 19.03.24.
//

#ifndef DRAW_H
#define DRAW_H

#include <figure.h>
#include <QGraphicsScene>

#define MIN_POINTS 2
#define NOT_ENOUGH_POINTS 5

typedef QGraphicsScene *scene_t;

typedef struct
{
    scene_t scene;
    double height;
    double width;
} painter_t;

typedef struct
{
    double x_coord;
    double y_coord;
} screen_point;

int draw_figure(painter_t &painter, figure_t &figure);

#endif //DRAW_H
