/*
** EPITECH PROJECT, 2018
** init_algo.c
** File description:
** fct who init algo of dijkstra
*/

#include "my_lemin.h"

block *check_min(block **list)
{
    int nb = 0;
    block *temp = NULL;

    for (int i = 0, j = 0; list[i]; i++) {
        list[i]->ants = 0;
        if (list[i]->weight != -1 && list[i]->status != 1) {
            (j == 0) ? nb = list[i]->weight, j++ : 0;
            if (nb >= list[i]->weight) {
                nb = list[i]->weight;
                temp = list[i];
            }
        }
    }
    return (temp);
}

void check_son(block *list)
{
    for (int i = 0; list->links[i]; i++) {
        if (list->links[i]->status == 1)
            continue;
        if (list->links[i]->weight == -1 || list->links[i]->weight >
        (get_distance(list, list->links[i]))) {
            list->links[i]->weight = get_distance(list, list->links[i]);
            list->links[i]->at = list->nb_block;
        }
    }
    list->status = 1;
}

void init_algo(block **list, char *map)
{
    block *first = NULL;
    block **test = NULL;
    int nb = 0;
    char *mv = NULL;
    int ants = my_getnbr(map);

    for (; list[nb]->end != true; nb++);
    for (; list[nb]->weight == -1;) {
        first = check_min(list);
        if (first == NULL) {
            my_macro(84);
            return;
        }
        check_son(first);
    }
    test = get_path(list);
    mv = move_ants(test, ants);
    display_map(map);
    my_putstr(mv);
    (1) ? free(test), free(mv) : (void) 0;
}
