/*
** EPITECH PROJECT, 2020
** bsq.c
** File description:
** BSQ Core
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my_main_funs.h"
#include "../lib/my/include/my_lib.h"
#include "algo/include/my_algo.h"
#include "algo/include/my_freeing.h"
#include <stdio.h>

void render_bsq(char *map)
{
    int x = 0;
    int y = 0;
    int width = get_width(map);
    int height = get_height(map);
    char **matrix = build_matrix(map);
    int *map_i = cast_char_map_to_int(map);
    int **matrix_i = build_int_matrix(map_i, map);

    free(map_i);
    compute_bsq(matrix_i, map, matrix);
    free_map_matrix(height, matrix);
    free(map);
}
