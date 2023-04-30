/*
** EPITECH PROJECT, 2020
** magic.c
** File description:
** Bypasses and other ugly stuff
*/

#include "include/my_algo.h"
#include "../../lib/my/include/my_lib.h"
#include <stdlib.h>

void bypass_coding_style(int *x_index, int *y_index, int *index)
{
    *y_index += 1;
    *index += 1;
    *x_index = -1;
}

int *cast_char_map_to_int(char *map)
{
    int *map_i;
    int i = 0;
    int len = my_strlen(map);

    map_i = malloc(sizeof(int) * len);
    while (i < len) {
        map_i[i] = 0;
        i += 1;
    }
    i = 0;
    while (i < len) {
        if (map[i] == '.')
            map_i[i] = 1;
        if (map[i] == 'o')
            map_i[i] = 0;
        if (map[i] == '\n')
            map_i[i] = 69;
        i += 1;
    }
    return (map_i);
}
