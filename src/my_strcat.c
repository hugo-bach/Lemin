/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** fct strcat
*/

#include "my_lemin.h"

char *my_strcat(char *str1, char *str2)
{
    char *result = my_calloc(my_strlen(str1) + my_strlen(str2));
    int c = 0;

    if (result == NULL)
        return (NULL);
    for (int i = 0; str1[i] != '\0'; i++, c++)
        result[c] = str1[i];
    for (int i = 0; str2[i] != '\0'; i++, c++)
        result[c] = str2[i];
    free(str1);
    free(str2);
    return (result);
}
