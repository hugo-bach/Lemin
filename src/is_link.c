/*
** EPITECH PROJECT, 2018
** name
** File description:
** check the syntax of the link
*/

#include "my_lemin.h"

int is_link(char *str, int pos)
{
    int count_link = 0;

    for (int i = pos; str[i] && str[i] != '\n'; i++) {
        if (str[i] == ' ')
            return (84);
        if (str[i] == '-')
            count_link++;
    }
    if (count_link != 1)
        return (84);
    return (0);
}
