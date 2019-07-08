/*
** EPITECH PROJECT, 2018
** my_macro.c
** File description:
** fct who save a step of my prog
*/

int my_macro(int status)
{
    static int save = 0;

    if (status == 84)
        save = 84;
    return (save);
}
