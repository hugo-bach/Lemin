/*
** EPITECH PROJECT, 2018
** name
** File description:
** simulation moves
*/

#include "my_lemin.h"

void add_move(char *str, int ant, char *room, int status)
{
    int pos = 0;

    for (; str[pos] != '\0'; pos++);
    str[pos++] = 'P';
    pos = my_put_nbr_to_str(ant, str, pos);
    str[pos++] = '-';
    for (int i = 0; room[i] != '\0'; i++)
        str[pos++] = room[i];
    if (status == 1)
        str[pos] = '\n';
    else
        str[pos] = ' ';
}

void add_back(char *str)
{
    int pos = 0;

    for (; str[pos]; pos++);
    if (pos != 0)
        str[pos - 1] = '\n';
}
