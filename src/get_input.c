/*
** EPITECH PROJECT, 2018
** name
** File description:
** get_input function
*/

#include "my_lemin.h"

char *get_input(int read_size)
{
    char *result = my_calloc(0);
    char *line = my_calloc(read_size);

    if (result == NULL || line == NULL)
        return (NULL);
    while (read(0, line, read_size) > 0) {
        result = my_strcat(result, line);
        line = my_calloc(read_size);
        if (result == NULL || line == NULL)
            return (NULL);
    }
    free(line);
    return (result);
}
