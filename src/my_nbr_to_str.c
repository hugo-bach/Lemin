/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** write a number
*/

#include "my_lemin.h"

int my_put_nbr_to_str(int nb, char *str, int pos)
{
    int pow = 1;
    int nbcpy = nb;
    int lon = 0;
    char result;

    while (nbcpy > 9) {
        pow = pow * 10;
        nbcpy = nbcpy / 10;
        lon = lon + 1;
    }
    while (lon > 0) {
        result = (nb / pow) + 48;
        str[pos++] = result;
        nb = nb % pow;
        pow = pow / 10;
        lon = lon - 1;
    }
    result = nb + '0';
    str[pos++] = result;
    return (pos);
}
