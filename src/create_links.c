/*
** EPITECH PROJECT, 2018
** create_links
** File description:
** create links of room
*/

#include "my_lemin.h"

int check_cmp(char *tmp, block **list, int nb_room, int x)
{
    for (int j = 0; list[j] != NULL; j++)
        if (my_strcmp(list[j]->nb_block, tmp) == 0) {
            list[nb_room]->links[x] = list[j];
            x++;
        }
    return (x);
}

int verif_all(char *tmp, block **list, int nb_room, int x)
{
    if (verif_it(tmp, list, nb_room, x) != 0)
        return (check_cmp(tmp, list, nb_room, x));
    return (x);
}

int check_room_right(char *map, block **list, int nb_room, int x)
{
    int i = go_to_links(map);
    char *tmp = NULL;

    while (i <= my_strlen(map)) {
        if (is_this_str(map, list[nb_room]->nb_block, i) == 1 &&
        map[i - 1] == '\n') {
            i += my_strlen(list[nb_room]->nb_block) + 1;
            tmp = cpy_str(map, i);
            x = verif_all(tmp, list, nb_room, x);
            free(tmp);
        }
        for (; map[i] && map[i] != '\n'; i++);
        i++;
    }
    return (x);
}

int check_room_left(char *map, block **list, int nb_room, int x)
{
    int i = go_to_links(map);
    char *tmp = NULL;

    while (i < my_strlen(map)) {
        tmp = cpy_str(map, i);
        i += my_strlen(tmp) + 1;
        if (is_this_str(map, list[nb_room]->nb_block, i) == 1 &&
        map[i - 1] == '-') {
            x = verif_all(tmp, list, nb_room, x);
        }
        for (; map[i] && map[i] != '\n'; i++);
        (map[i] != '\0') ? i++ : 0;
        free(tmp);
    }
    return (x);
}

void get_links(char *map, block **list, int nb_room)
{
    int nb_links = get_nb_links(map, list[nb_room]->nb_block);
    int x = 0;

    list[nb_room]->links = malloc(sizeof(block) * (nb_links + 1));
    x = check_room_right(map, list, nb_room, x);
    x = check_room_left(map, list, nb_room, x);
    list[nb_room]->links[x] = NULL;
}
