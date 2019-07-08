/*
** EPITECH PROJECT, 2018
** name
** File description:
** my_strdup
*/

#include "my_lemin.h"

char *my_strdup(char *str)
{
    char *result = my_calloc(my_strlen(str));

    for (int i = 0; str[i] != '\0'; i++)
        result[i] = str[i];
    return (result);
}
