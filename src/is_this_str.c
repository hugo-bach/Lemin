/*
** EPITECH PROJECT, 2018
** is_this_str
** File description:
** check if str is in this str
*/

#include "my_lemin.h"

int is_this_str(char *map, char *str, int i)
{
    int x = 0;

    for (; x != my_strlen(str); x++, i++) {
        if (map[i - 1] == '\0')
            return (0);
        if (map[i] != str[x])
            return (0);
    }
    if (map[i] == '\n' || map[i] == '-')
        return (1);
    return (0);
}
