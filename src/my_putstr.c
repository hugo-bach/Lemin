/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** fct who display a string
*/

#include "my_lemin.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
