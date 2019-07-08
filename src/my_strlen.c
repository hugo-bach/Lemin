/*
** EPITECH PROJECT, 2018
** name
** File description:
** my_strlen
*/

#include "my_lemin.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
