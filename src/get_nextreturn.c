/*
** EPITECH PROJECT, 2018
** name
** File description:
** get next n
*/

#include "my_lemin.h"

int get_return(char *str, int pos)
{
    for (; str[pos] && str[pos] != '\n'; pos++);
    if (str[pos] == '\n')
        pos++;
    return (pos);
}
