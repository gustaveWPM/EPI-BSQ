/*
** EPITECH PROJECT, 2020
** my_casting_funs.c
** File description:
** Casting functions
*/

#include "include/my_lib.h"

int my_atoi(char *nbr_str)
{
    int i = 0;
    int result = 0;

    while (nbr_str[i] != '\0') {
        result *= 10;
        result += (nbr_str[i] - 48);
        i += 1;
    }
    return (result);
}
