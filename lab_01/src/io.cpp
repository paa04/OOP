#include "io.h"

#include "allocate.h"

#include  "point.h"

static int read_amount(int &amount, FILE *file)
{
    if (!file)
        return FILE_WORK_ERR;

    if (fscanf(file, "%d", &amount) != 1)
        return FILE_DATA_ERROR;

    return EXIT_SUCCESS;
}

static int read_point(point_t &point, FILE *f)
{
    int status = EXIT_SUCCESS;

    if (fscanf(f, "%lf%lf%lf", &point.x_coord, &point.y_coord,
               &point.z_coord) != 3)
        status = FILE_DATA_ERROR;

    return status;
}

static int read_edge(edge_t &edge, FILE *f)
{
    int status = EXIT_SUCCESS;

    if (fscanf(f, "%d%d", &edge.point_a, &edge.point_b) != 2)
        status = FILE_DATA_ERROR;

    return status;
}

static int read_points_array(point_t *points, int amount, FILE *file)
{
    int status = EXIT_SUCCESS;

    for (int i = 0; status == EXIT_SUCCESS && i < amount; ++i)
        status = read_point(points[i], file);

    return status;
}

static int read_points(point_array_t &point_array, FILE *file)
{
    int status = read_amount(point_array.amount, file);
    if (status == EXIT_SUCCESS)
    {
        status = alloc_points(point_array.array, point_array.amount);
        if (status == EXIT_SUCCESS)
        {
            status = read_points_array(point_array.array, point_array.amount, file);
            if (status != EXIT_SUCCESS)
                free_mem(point_array.array);
        }
    }
    return status;
}

static int read_edges_array(edge_t *edges, int amount, FILE *file)
{
    int status = EXIT_SUCCESS;
    for (int i = 0; status == EXIT_SUCCESS && i < amount; ++i)
    {
        status = read_edge(edges[i], file);
    }
    return status;
}

static int read_edges(edges_arr_t &edges, FILE *file)
{
    int status = read_amount(edges.amount, file);

    if (status == EXIT_SUCCESS)
    {
        status = alloc_edges(edges.array, edges.amount);
        if (status == EXIT_SUCCESS)
        {
            status = read_edges_array(edges.array, edges.amount, file);

            if (status != EXIT_SUCCESS)
                free_mem(edges.array);
        }
    }
    return status;
}

static int load_buff_figure(figure_t &figure, FILE *file, const char *figure_name)
{
    figure = init_figure(figure_name);

    int status = read_points(figure.points, file);
    if (status == EXIT_SUCCESS)
    {
        status = read_edges(figure.edges, file);
        if (status != EXIT_SUCCESS)
        {
            free_data(figure.points);
            destroy_name(figure.name);
        }
    }
    else
    {
        destroy_name(figure.name);
    }

    return status;
}

int load_figure(figure_t &figure, const char *file_name)
{
    FILE *file = fopen(file_name, "r");

    if (!file)
        return OPEN_FILE_ERROR;

    int status = EXIT_SUCCESS;

    figure_t buff_figure;

    status = load_buff_figure(buff_figure, file, file_name);

    fclose(file);

    if (status == EXIT_SUCCESS)
    {
        destroy_figure(figure);
        figure = buff_figure;
    }

    return status;
}

static void save_point(point_t &point, FILE *file)
{
    fprintf(file, "%lf %lf %lf\n", point.x_coord, point.y_coord, point.z_coord);
}

int save_points(point_array_t &point_array, FILE *file)
{
    if (!file)
        return FILE_WORK_ERR;

    fprintf(file, "%d\n", point_array.amount);

    for (int i = 0; i < point_array.amount; ++i)
    {
        save_point(point_array.array[i], file);
    }

    return EXIT_SUCCESS;
}

static void save_edge(edge_t &edge, FILE *file)
{
    fprintf(file, "%d %d\n", edge.point_a, edge.point_b);
}

int save_edges(edges_arr_t &edges_arr, FILE *file)
{
    if (!file)
        return FILE_DATA_ERROR;

    fprintf(file, "%d\n", edges_arr.amount);

    for (int i = 0; i < edges_arr.amount; ++i)
    {
        save_edge(edges_arr.array[i], file);
    }

    return EXIT_SUCCESS;
}
