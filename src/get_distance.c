/*
** EPITECH PROJECT, 2018
** name
** File description:
** get_distance function
*/

#include "my_lemin.h"

float my_sqrt(float nbr)
{
    float result = 0;

    for (; result * result <= nbr; result += 0.1);
    return (result);
}

int my_pow(int nbr)
{
    return (nbr * nbr);
}

int get_distance(block *start, block *end)
{
    int result = 0;
    int x1 = start->coord_x;
    int x2 = end->coord_x;
    int y1 = start->coord_y;
    int y2 = end->coord_y;

    result = my_sqrt(my_pow(x2 - x1) + my_pow(y2 - y1));
    return (result);
}
