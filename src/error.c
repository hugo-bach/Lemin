/*
** EPITECH PROJECT, 2018
** name
** File description:
** bad input, check error
*/

#include "my_lemin.h"

int error_room(char *str, int i)
{
    static int status = 0;
    static int room = 0;

    if (status != 84) {
        status = is_room(str, i);
        (status != 84) ? room++ : 0;
    }
    if (status == 84)
        if (is_link(str, i) == 84 || room <= 1)
            return (84);
    return (0);
}

int error_formating(char *str, int i)
{
    int ed = 0;
    int st = 0;
    int er = 0;

    for (int j = i; str[j]; j = get_return(str, j)) {
        if (my_strncmp(str, "##start", j) == 0)
            st += 1;
        else if (my_strncmp(str, "##end", j) == 0)
            ed += 1;
        else
            er = error_room(str, j);
        if (st >= 2 || ed >= 2 || er == 84)
            return (84);
    }
    if (st == 0 || ed == 0)
        return (84);
    return (0);
}

int check_room_name(block **list)
{
    int result = 0;

    for (int i = 0; list[i] != NULL; i++)
        for (int j = 0;list[j] != NULL; j++)
            if (my_strcmp(list[i]->nb_block, list[j]->nb_block) == 0 && i != j)
                result = 84;
    return (result);
}

int error_handling(char *str)
{
    int i = 0;
    int error = 0;

    for (int j = 0; str[j] && (error = is_link(str, j)) != 0;
    j = get_return(str, j));
    if (error == 84 || str[0] == '\0')
        return (84);
    if (str[0] == '#' && str[1] == '#')
        return (84);
    for (int a = 0; str[i] && str[i] != '\n'; i++, a++)
        if (a == 0 && !(str[i] > '0' && str[i] <= '9'))
            return (84);
        else if (str[i] < '0' || str[i] > '9')
            return (84);
    i++;
    return (i != 1) ? error_formating(str, i) : 84;
}
