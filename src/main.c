/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** MAIN
*/

#include "my_lemin.h"

void my_freelist(block **list, char *map)
{
    for (int i = 0; list[i]; i++) {
        free(list[i]->nb_block);
        free(list[i]->links);
        free(list[i]);
    }
    free(list);
    free(map);
}

int main(void)
{
    char *map = clear_input(get_input(33554432));

    if (error_handling(map) == 84) {
        (map[0] != '\0') ? display_map(map), free(map) : free(map);
        return (84);
    }
    block **list = malloc(sizeof(block *) * (get_nb_rooms(map) + 1));
    create_rooms(map, list);
    if (error_link(map, list) == 84 || check_coord(list) == 84 ||
    check_room_name(list) == 84) {
        (1) ? display_map(map), my_freelist(list, map) : (void) 0;
        return (84);
    }
    init_algo(list, map);
    if (my_macro(0) == 84) {
        (1) ? display_map(map), my_freelist(list, map) : (void) 0;
        return (84);
    }
    my_freelist(list, map);
    return (0);
}
