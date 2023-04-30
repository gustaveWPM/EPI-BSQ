/*
** EPITECH PROJECT, 2020
** getters.c
** File description:
** Getters
*/

#include "../include/my_main_funs.h"
#include "../lib/my/include/my_lib.h"
#include <stdlib.h>

int get_height(char *map)
{
    return (get_first_line_nbr(map));
}

int get_width(char *map)
{
    int i = 0;
    int width = 0;

    while (map[i] != '\n')
        i += 1;
    i += 1;
    while (map[i + width] != '\n')
        width += 1;
    return (width);
}

int get_first_line_nbr(char *map)
{
    int i = 0;
    char *nbr;
    int result = 0;

    while (map[i] != '\n' && map[i] != '\r')
        i += 1;
    nbr = malloc(sizeof(char) * i + 1);
    if (nbr == NULL)
        exit(84);
    i = 0;
    while (map[i] != '\n' && map[i] != '\r') {
        nbr[i] = map[i];
        i += 1;
    }
    nbr[i] = '\0';
    result = my_atoi(nbr);
    free(nbr);
    return (result);
}
