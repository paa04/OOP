//
// Created by paa04 on 19.03.24.
//
#include "draw.h"

static void draw_line(painter_t &painter, screen_point &first, screen_point &second)
{
    painter.scene->addLine(first.x_coord, first.y_coord, second.x_coord, second.y_coord);
}

static screen_point set_screen_point(painter_t &painter, point_t &point)
{
    screen_point screenPoint;

    screenPoint.x_coord = painter.width / 2 + point.x_coord;
    screenPoint.y_coord = painter.height / 2 - point.y_coord;

    return screenPoint;
}

static int check_index(int index, int size)
{
    return index >= 0 && index < size;
}

static int draw_edge(painter_t &painter, point_array_t &points, edge_t &edge)
{
    if (points.array == nullptr || !check_index(edge.point_a, points.amount) ||
        !check_index(edge.point_a, points.amount))
        return EXIT_FAILURE;

    point_t point_a = points.array[edge.point_a], point_b = points.array[edge.point_b];

    screen_point
            first = set_screen_point(painter, point_a),
            second = set_screen_point(painter, point_b);

    draw_line(painter, first, second);

    return EXIT_SUCCESS;
}

static int draw_edges(painter_t &painter, point_array_t &points, edges_arr_t &edges)
{
    if (edges.array == nullptr)
        return EXIT_FAILURE;

    int status = EXIT_SUCCESS;

    for (int i = 0; status == EXIT_SUCCESS && i < edges.amount; ++i)
    {
        status = draw_edge(painter, points, edges.array[i]);
    }
    return status;
}

int draw_figure(painter_t &painter, figure_t &figure)
{
    int status = EXIT_SUCCESS;
    status = draw_edges(painter, figure.points, figure.edges);
    return status;
}
