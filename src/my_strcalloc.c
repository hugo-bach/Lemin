/*
** EPITECH PROJECT, 2018
** my_strcalloc.c
** File description:
** fct who malloc and fill strings with 0
*/

#include "my_lemin.h"

char **my_strcalloc(int size)
{
    char **result = malloc(sizeof(char *) * (size + 1));

    if (result == NULL)
        return (NULL);
    for (int i = 0; i <= size; i++)
        result[i] = NULL;
    return (result);
}
