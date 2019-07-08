/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** fct who return 1 if the string is equal string two
*/

#include "my_lemin.h"

int my_strncmp(char *str1, char *str2, int i)
{
    for (int j = 0; str1[i] && j != my_strlen(str2); j++, i++)
        if (str1[i] != str2[j])
            return (-1);
    return (0);
}
