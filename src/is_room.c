/*
** EPITECH PROJECT, 2018
** is_room.c
** File description:
** fct who check if the string is a room
*/

#include "my_lemin.h"

int is_digit(char c)
{
    if (c < '0' || c > '9')
        return (84);
    return (0);
}

int is_room(char *str, int i)
{
    int space = 0;
    int error = 0;

    for (int j = i; str[j] != '\n' && str[j]; j++) {
        if (space > 0 && str[j] != ' ')
            error = is_digit(str[j]);
        (str[j] == ' ') ? space++ : 0;
        if (space > 2 || error == 84)
            return (84);
    }
    return (space != 2) ? 84 : 0;
}
