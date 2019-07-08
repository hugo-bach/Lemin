/*
** EPITECH PROJECT, 2018
** name
** File description:
** create room
*/

#include "my_lemin.h"

int get_size_malloc(int i, char *map)
{
    int size_of_malloc = 0;

    for (; map[i] != ' '; i++, size_of_malloc++);
    return (size_of_malloc);
}

char *get_nb_block(char *map, int i)
{
    char *str = malloc(sizeof(char) * get_size_malloc(i, map) + 1);
    int x = 0;

    for (; map[i] != ' '; x++, i++)
        str[x] = map[i];
    str[x] = '\0';
    return (str);
}

int get_coord_x(char *map, int i)
{
    for (; map[i] != ' '; i++);
    i++;
    map += i;
    return (my_getnbr(map));
}

int get_coord_y(char *map, int i)
{
    for (; map[i] != ' '; i++);
    i++;
    for (; map[i] != ' '; i++);
    i++;
    map += i;
    return (my_getnbr(map));
}
