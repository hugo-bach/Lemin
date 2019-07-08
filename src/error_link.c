/*
** EPITECH PROJECT, 2018
** error_link.c
** File description:
** fct who check all link of the map
*/

#include "my_lemin.h"

int nb_link(char *map, int k, char *name)
{
    int nb = 0;
    int j = 0;

    if (my_strncmp(map, name, k) == 0) {
        if (map[k + my_strlen(name)] == '-') {
            j = k + my_strlen(name);
            nb++;
        }
    } else
        for (j = k; map[j] != '-'; j++);
    j++;
    if (my_strncmp(map, name, j) == 0)
        if (map[j + my_strlen(name)] == '\n')
            nb++;
    return (nb);
}

int error_link(char *map, block **list)
{
    int i = 0;
    int nb = 0;
    int tmp = 0;

    for (; is_link(map, i) != 0; i = get_return(map, i));
    for (int j = i; map[j]; j = get_return(map, j), nb++);
    nb = nb * 2;
    for (int j = 0; list[j]; j++)
        for (int k = i; map[k]; k = get_return(map, k)) {
            tmp = nb_link(map, k, list[j]->nb_block);
            nb -= tmp;
        }
    if (nb != 0)
        return (84);
    return (0);
}
