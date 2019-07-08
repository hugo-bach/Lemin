/*
** EPITECH PROJECT, 2018
** name
** File description:
** my_free function
*/

#include "my_lemin.h"

void my_tabfree(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void my_free(char *str)
{
    if (str != NULL)
        free(str);
}
