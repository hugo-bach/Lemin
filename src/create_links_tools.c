/*
** EPITECH PROJECT, 2018
** create_links
** File description:
** tools
*/

#include "my_lemin.h"

int verif_it(char *tmp, block **list, int nb_room, int x)
{
    if (my_strcmp(tmp, list[nb_room]->nb_block) == 0)
        return (0);
    for (int i = 0; i != x; i++)
        if (tmp != NULL &&
            my_strcmp(tmp, list[nb_room]->links[i]->nb_block) == 0)
            return (0);
    return (1);
}

int go_to_links(char *map)
{
    int i = 0;

    for (; map[i] != '-'; i++);
    for (; map[i] != '\n'; i--);
    i++;
    return (i);
}

int get_nb_rooms(char *map)
{
    int i = 0;
    int nb_rooms = 0;

    for (; map[i] != '\n'; i++);
    i++;
    while (map[i] != '-') {
        if (map[i] == '\n' && map[i+1] != '#')
            nb_rooms++;
        i++;
    }
    return (nb_rooms);
}

char *cpy_str(char *map, int i)
{
    int x = 0;
    char *str = malloc(sizeof(char) * (get_size_str(map, i) + 1));

    for (; map[i] && map[i] != '\n' && map[i] != '-'; i++, x++)
        str[x] = map[i];
    str[x] = '\0';
    return (str);
}
