#include "point.h"
#include "allocate.h"
#include "error.h"
#include "math_f.h"

void init_points(point_array_t &arr)
{
    arr.amount = 0;
    arr.array = NULL;
}

int alloc_points(point_t *&points, int amount)
{
    points = (point_t *)(alloc(amount * sizeof(point_t)));

    if (points == NULL)
        return ALLOCATE_ERROR;

    return EXIT_SUCCESS;
}

static void move_point(point_t &point, transform_t &data)
{
    point.x_coord += data.kx;
    point.y_coord += data.ky;
    point.z_coord += data.kz;
}

int move_points(point_array_t &points, transform_t &data)
{
    if (points.amount < 1)
        return NOT_ENOUGH_POINTS;

    for (int i = 0; i < points.amount; ++i)
        move_point(points.array[i], data);

    return EXIT_SUCCESS;
}

static point_t find_max(point_array_t &points)
{
    double
            x_s = points.array[0].x_coord,
            y_s = points.array[0].y_coord,
            z_s = points.array[0].z_coord;

    for (int i = 1; i < points.amount; ++i)
    {
        x_s = max(x_s, points.array[i].x_coord);
        y_s = max(y_s, points.array[i].y_coord);
        z_s = max(z_s, points.array[i].z_coord);
    }

    point_t max_point;

    max_point.x_coord = x_s;
    max_point.y_coord = y_s;
    max_point.z_coord = z_s;

    return max_point;
}

void to_center(point_t &point, point_t &center)
{
    point.x_coord -= center.x_coord;
    point.y_coord -= center.y_coord;
    point.z_coord -= center.z_coord;
}

void from_center(point_t &point, point_t &center)
{
    point.x_coord += center.x_coord;
    point.y_coord += center.y_coord;
    point.z_coord += center.z_coord;
}

static point_t find_min(point_array_t &points)
{
    double
            x_s = points.array[0].x_coord,
            y_s = points.array[0].y_coord,
            z_s = points.array[0].z_coord;

    for (int i = 1; i < points.amount; ++i)
    {
        x_s = min(x_s, points.array[i].x_coord);
        y_s = min(y_s, points.array[i].y_coord);
        z_s = min(z_s, points.array[i].z_coord);
    }

    point_t min_point;

    min_point.x_coord = x_s;
    min_point.y_coord = y_s;
    min_point.z_coord = z_s;

    return min_point;
}

int find_center_point(point_array_t &points, point_t &center)
{
    if (points.amount < MIN_POINTS)
    {
        return NOT_ENOUGH_POINTS;
    }

    point_t
    max_point = find_max(points),
    min_point = find_min(points);


    center.x_coord = (max_point.x_coord + min_point.x_coord) / 2;
    center.y_coord = (max_point.y_coord + min_point.y_coord) / 2;
    center.z_coord = (max_point.z_coord + min_point.z_coord) / 2;

    return EXIT_SUCCESS;
}

static void rotate_point_z(point_t &point, double degree)
{
    double
            x = point.x_coord,
            y = point.y_coord,
            d_r = to_radians(degree),
            cos_r = cos(d_r),
            sin_r = sin(d_r);

    //x' = x*cos q - y*sin q
    //y' = x*sin q + y*cos q

    point.x_coord = x * cos_r - y * sin_r;
    point.y_coord = x * sin_r + y * cos_r;
}

static void rotate_point_y(point_t &point, double degree)
{
    double
            z = point.z_coord,
            x = point.x_coord,
            d_r = to_radians(degree),
            cos_r = cos(d_r),
            sin_r = sin(d_r);

    //z' = z*cos q - x*sin q
    //x' = z*sin q + x*cos q

    point.z_coord = z * cos_r - x * sin_r;
    point.x_coord = z * sin_r + x * cos_r;
}


static void rotate_point_x(point_t &point, double degree)
{
    double
            z = point.z_coord,
            y = point.y_coord,
            d_r = to_radians(degree),
            cos_r = cos(d_r),
            sin_r = sin(d_r);

    //y' = y*cos q - z*sin q
    //z' = y*sin q + z*cos q

    point.y_coord = y * cos_r - z * sin_r;
    point.z_coord = y * sin_r + z * cos_r;
}

static int scale_point_x(point_t &point, double kx)
{
    if (fabs(kx) < EPS)
        return SMALL_SCALE;

    point.x_coord = point.x_coord * kx;

    return EXIT_SUCCESS;
}

static int scale_point_y(point_t &point, double ky)
{
    if (fabs(ky) < EPS)
        return SMALL_SCALE;

    point.y_coord = point.y_coord * ky;

    return EXIT_SUCCESS;
}

static int scale_point_z(point_t &point, double kz)
{
    if (fabs(kz) < EPS)
        return SMALL_SCALE;

    point.z_coord = point.z_coord * kz;

    return EXIT_SUCCESS;
}

int scale_points(point_array_t &point_array, transform_t &scale, point_t &center)
{
    if (point_array.amount < 1 || point_array.array == nullptr)
        return NOT_ENOUGH_POINTS;

    int status = EXIT_SUCCESS;

    for (int i = 0; i < point_array.amount && status == EXIT_SUCCESS; ++i)
    {
        to_center(point_array.array[i], center);
        status = scale_point_x(point_array.array[i], scale.kx);
        if (status == EXIT_SUCCESS)
        {
            status = scale_point_y(point_array.array[i], scale.ky);
            if (status == EXIT_SUCCESS)
                status = scale_point_z(point_array.array[i], scale.kz);
        }
        from_center(point_array.array[i], center);
    }

    return status;
}

int rotate_points(point_array_t &point_array, transform_t &rotate, point_t &center)
{
    if (point_array.amount < 1 || point_array.array == nullptr)
        return NOT_ENOUGH_POINTS;

    for (int i = 0; i < point_array.amount; ++i)
    {
        to_center(point_array.array[i], center);

        rotate_point_x(point_array.array[i], rotate.kx);
        rotate_point_y(point_array.array[i], rotate.ky);
        rotate_point_z(point_array.array[i], rotate.kz);

        from_center(point_array.array[i], center);
    }

    return EXIT_SUCCESS;
}

void free_data(point_array_t &arr)
{
    arr.amount = 0;
    free_mem(arr.array);
}