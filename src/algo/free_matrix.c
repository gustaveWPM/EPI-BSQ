/*
** EPITECH PROJECT, 2020
** free_matrix.c
** File description:
** Matrixes freeing
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_main_funs.h"
#include "../../lib/my/include/my_lib.h"
#include "include/my_algo.h"
#include <stdio.h>

void free_sum_matrix(int height, int **sum)
{
    int y_index = 0;

    for (y_index = 0; y_index < height; y_index++)
        free(sum[y_index]);
    free(sum);
}

void free_int_matrix(int height, int **matrix_i)
{
    int y_index = 0;

    for (y_index = 0; y_index < height; y_index++)
        free(matrix_i[y_index]);
    free(matrix_i);
}

void free_map_matrix(int height, char **map)
{
    int y_index = 0;

    for (y_index = 0; y_index < height; y_index++)
        free(map[y_index]);
    free(map);
}
