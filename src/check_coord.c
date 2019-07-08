/*
** EPITECH PROJECT, 2018
** name
** File description:
** check room coord
*/

#include "my_lemin.h"

int check_coord(block **list)
{
    for (int i = 0; list[i]; i++)
        for (int j = 0; list[j]; j++) {
            if (list[i]->coord_x == list[j]->coord_x &&
            list[i]->coord_y == list[j]->coord_y && i != j) {
                return (84);
            }
        }
    return (0);
}
