/*
** EPITECH PROJECT, 2018
** name
** File description:
** clear input str
*/

#include "my_lemin.h"

int get_size(char *input)
{
    int tmp = 0;
    int i = 0;

    for (; input[i] != '\0'; i++)
        if (input[i] == ' ') {
            for (tmp = i; input[tmp] == ' '; tmp++);
            i = (input[tmp] == '\n') ? tmp : i;
            tmp = i;
        }
    return (i);
}

char *remove_trailling_space(char *input)
{
    char *result = NULL;
    int tmp = 0;
    int i = 0;
    int j = 0;
    int counter = 0;

    i = get_size(input);
    result = my_calloc(i);
    tmp = 0;
    for (; input[j] != '\0'; j++, counter++) {
        if (input[j] == ' ') {
            for (tmp = j; input[tmp] == ' '; tmp++);
            j = (input[tmp] == '\n') ? tmp : j;
            tmp = j;
        }
        result[counter] = input[j];
    }
    free(input);
    return (result);
}

void clear_input_bis(char *input, char *result)
{
    int count = 0;

    for (int i = 0; input[i] != '\0'; i++)
        if (input[i] == '#' && input[i + 1] != '#' && i == 0)
            i = (i == 0 || input[i - 1] == '\n') ? get_return(input, i) - 1 :
            get_return(input, i) - 2;
        else if (input[i] == '#' && input[i + 1] != '#' && input[i - 1] != '#')
            i = (i == 0 || input[i - 1] == '\n') ? get_return(input, i) - 1 :
            get_return(input, i) - 2;
        else
            result[count++] = input[i];
    free(input);
}

char *clear_input(char *input)
{
    char *result = NULL;
    int size = 0;

    for (int i = 0; input[i] != '\0'; i++)
        if (input[i] == '#' && input[i + 1] != '#' && i == 0)
            i = (i == 0 || input[i - 1] == '\n') ? get_return(input, i) - 1 :
            get_return(input, i) - 2;
        else if (input[i] == '#' && input[i + 1] != '#' && input[i - 1] != '#')
            i = (i == 0 || input[i - 1] == '\n') ? get_return(input, i) - 1 :
            get_return(input, i) - 2;
        else
            size++;
    result = my_calloc(size);
    clear_input_bis(input, result);
    return (remove_trailling_space(result));
}
