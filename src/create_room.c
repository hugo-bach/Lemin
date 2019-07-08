/*
** EPITECH PROJECT, 2018
** name
** File description:
** create room
*/

#include "my_lemin.h"

bool is_first_room(char *map, int i)
{
    if (map[i-2] == 't')
        return (true);
    return (false);
}

bool is_end_room(char *map, int i)
{
    if (map[i-2] == 'd')
        return (true);
    return (false);
}

int get_nb_links(char *map, char *str)
{
    int count = 0;
    int i = 0;

    for (; map[i] != '-'; i++);
    for (; map[i] && map[i] != '\n'; i--);
    i++;
    while (map[i] != '\0') {
        count += is_this_str(map, str, i);
        i++;
    }
    return (count);
}

int get_size_str(char *map, int i)
{
    int count = 0;
    for (; map[i] && map[i] != '\n' && map[i] != '-'; i++, count++);
    return (count);
}

void create_rooms(char *map, block **list)
{
    int i = get_return(map, 0);
    int nb_room = 0;

    while (is_link(map, i) != 0) {
        if (map[i] != '#') {
            list[nb_room] = malloc(sizeof(block));
            list[nb_room]->nb_block = get_nb_block(map, i);
            list[nb_room]->coord_x = get_coord_x(map, i);
            list[nb_room]->coord_y = get_coord_y(map, i);
            list[nb_room]->first = is_first_room(map, i);
            list[nb_room]->end = is_end_room(map, i);
            set_algo(list[nb_room]);
            nb_room++;
        }
        i = get_return(map, i);
    }
    list[nb_room] = NULL;
    for (int x = 0; list[x] != NULL; x++)
        get_links(map, list, x);
}
