/*
** EPITECH PROJECT, 2018
** name
** File description:
** get path function
*/

#include "my_lemin.h"

block *get_room_by_name(char *name, block **list)
{
    for (int i = 0; list[i] != NULL; i++)
        if (my_strcmp(list[i]->nb_block, name) == 0)
            return (list[i]);
    return (NULL);
}

block **my_reverse(block **path, int size)
{
    block **result = malloc(sizeof(block *) * (size + 2));
    int counter = size;
    int i = 0;

    for (; i < size + 1; i++, counter--) {
        result[i] = path[counter];
    }
    result[i] = NULL;
    free(path);
    return (result);
}

block *get_end(block **list)
{
    block *end = NULL;

    for (int i = 0; list[i] != NULL; i++)
        if (list[i]->end == true) {
            end = list[i];
            break;
        }
    return (end);
}

block **get_path(block **list)
{
    block **result = NULL;
    block *end = NULL;
    block *tmp = NULL;
    int size = 0;
    int i = 0;

    end = get_end(list);
    tmp = end;
    for (; tmp->first != true; size++)
        tmp = get_room_by_name(tmp->at, list);
    result = malloc(sizeof(block *) * (size + 2));
    tmp = end;
    for (;tmp->first != true; i++) {
        result[i] = tmp;
        tmp = get_room_by_name(tmp->at, list);
    }
    result[i] = tmp;
    result[i + 1] = NULL;
    result = my_reverse(result, size);
    return (result);
}
