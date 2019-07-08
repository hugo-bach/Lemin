/*
** EPITECH PROJECT, 2018
** set_algo.c
** File description:
** fct who set the struct
*/

#include "my_lemin.h"

void set_algo(block *list)
{
    if (list->first == true)
        list->weight = 0;
    else
        list->weight = -1;
    list->status = 0;
    list->at = NULL;
}
