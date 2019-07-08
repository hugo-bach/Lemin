/*
** EPITECH PROJECT, 2018
** my_calloc.c
** File description:
** fct who malloc and fill the string with 0
*/

#include "my_lemin.h"

char *my_calloc(int size)
{
    char *result = malloc(sizeof(char) * (size + 1));

    if (result == NULL)
        return (NULL);
    for (int i = 0; i <= size; i++)
        result[i] = '\0';
    return (result);
}
