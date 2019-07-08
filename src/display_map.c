/*
** EPITECH PROJECT, 2018
** display_map.c
** File description:
** fct who display the map
*/

#include "my_lemin.h"

void display_map(char *map)
{
    int i = 0;

    my_putstr("#number_of_ants\n");
    for (; map[i] && map[i] != '\n'; i++)
        write(1, &map[i], 1);
    write(1, &map[i++], 1);
    my_putstr("#rooms\n");
    for (; map[i] && is_link(map, i) != 0; i++)
        write(1, &map[i], 1);
    my_putstr("#tunnels\n");
    for (; map[i]; i++)
        write(1, &map[i], 1);
    my_putstr("#moves\n");
}
