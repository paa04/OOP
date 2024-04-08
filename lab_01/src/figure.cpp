#include "figure.h"

#include "io.h"
#include "point.h"
#include "edges.h"
#include "allocate.h"
#include <string.h>

figure_t &init_figure(void)
{
    static figure_t fig;
    init_edges(fig.edges);
    init_points(fig.points);
    fig.name = (char *) (alloc(MAX_NAME_LEN * sizeof(char)));
    return fig;
}

figure_t &init_figure(const char *name)
{
    static figure_t fig;
    init_edges(fig.edges);
    init_points(fig.points);
    fig.name = (char *) (alloc(MAX_NAME_LEN * sizeof(char)));
    strcpy(fig.name, name);
    return fig;
}

void destroy_figure(figure_t &figure)
{
    free_data(figure.edges);
    free_data(figure.points);
    free_mem(figure.name);
}

void destroy_name(char *name)
{
    free_mem(name);
}

int move_figure(figure_t &figure, transform_t &transform)
{
    return move_points(figure.points, transform);
}

int find_center_figure(figure_t &figure, point_t &center)
{
    return find_center_point(figure.points, center);
}

int center_figure(figure_t &figure, point_t &center)
{
    point_t cur_center;
    int status = find_center_figure(figure, cur_center);
    if (status == EXIT_SUCCESS)
    {
        transform_t center_transform;
        center_transform.kx = center.x_coord - cur_center.x_coord;
        center_transform.ky = center.y_coord - cur_center.y_coord;
        center_transform.kz = center.z_coord - cur_center.z_coord;

        status = move_figure(figure, center_transform);
    }

    return status;
}

int rotate_figure(figure_t &figure, transform_t &rotate, point_t &center)
{
    return rotate_points(figure.points, rotate, center);
}

int scale_figure(figure_t &figure, transform_t &scale, point_t &center)
{
    return scale_points(figure.points, scale, center);
}

int save_figure(figure_t &figure, const char *filename)
{
    if (!filename)
        return INCORECT_FILE_NAME;

    FILE *file = fopen(filename, "w");

    if (!file)
        return FILE_WORK_ERR;

    int status = EXIT_SUCCESS;

    status = save_points(figure.points, file);

    if (status == EXIT_SUCCESS)
        status = save_edges(figure.edges, file);

    fclose(file);

    return status;
}
