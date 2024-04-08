//
// Created by paa04 on 20.03.24.
//
#include "math_f.h"

double max(double a, double b)
{
    return a > b ? a : b;
}

double min(double a, double b)
{
    return a < b ? a : b;
}

double to_radians(double degree)
{
    return degree * PI / 180;
}