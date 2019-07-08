/*
** EPITECH PROJECT, 2018
** move_ant.c
** File description:
** fct who move all ants
*/

#include "my_lemin.h"

static int size_malloc(block **path, int ants)
{
    int nb = 0;
    int len = 0;

    for (; path[nb]; nb++)
        if (my_strlen(path[nb]->nb_block) > len)
            len = my_strlen(path[nb]->nb_block);
    ants *= 5 + len;
    nb *= ants;
    return (nb);
}

static int nb_path(block **path)
{
    int nb = 0;

    for (; path[nb]; nb++);
    return (nb);
}

static void move_all(block **path)
{
    static int status = 0;
    static int nb = 0;

    (status == 0) ? nb = nb_path(path), status++ : status++;
    for (int i = nb - 1; i > 0; i--) {
        if ((path[i]->ants == 0 && path[i - 1]->ants != 0) || path[i]->
        end == true) {
            path[i]->ants = path[i- 1]->ants;
            path[i - 1]->ants = 0;
        }
    }
}

static void add_all_moves(block **path, char *mv)
{
    static int status = 0;
    static int nb = 0;

    (status == 0) ? nb = nb_path(path), status++ : status++;
    for (int i = nb - 1; i > 0; i--)
        if (path[i]->ants != 0)
            add_move(mv, path[i]->ants, path[i]->nb_block, 0);
}

char *move_ants(block **path, int nb_ants)
{
    char *mv = my_calloc((size_malloc(path, nb_ants)));
    int nb = 1;

    for (; nb < nb_path(path) + nb_ants + 1; nb++) {
        move_all(path);
        if (nb <= nb_ants)
            path[0]->ants = nb;
        add_all_moves(path, mv);
        add_back(mv);
    }
    return (mv);
}
