/*
** EPITECH PROJECT, 2020
** algo.c
** File description:
** Algorithm used to retrieve the biggest square
*/

#include <stdio.h>
#include "../../lib/my/include/my_lib.h"
#include "../../include/my_main_funs.h"
#include "include/my_structs.h"
#include "include/my_algo.h"
#include "include/my_freeing.h"
#include <stdlib.h>
#include <unistd.h>

void show(struct Max_s max, int **map_matrix, char **matrix, struct Rect_s rect)
{
    char *output;
    for (int w = max.y; w > max.y - max.sum; w--) {
        for (int x = max.z; x > max.z - max.sum; x--) {
            matrix[w][x] = 'x';
        }
    }
    free_int_matrix(rect.height, map_matrix);
    output = flatten_char_matrix(matrix, rect.height, rect.width);
    my_putstr(output);
    free(output);
}

void populate_sum_matrix(int **sum, int **map_matrix, char *map)
{
    int y = 0;
    int z = 0;
    int height = get_height(map);
    int width = get_width(map);

    for (y = 1; y < height; y++) {
        for (z = 1; z < width; z++) {
            if (map_matrix[y][z] == 1)
                sum[y][z] = min(sum[y][z-1], sum[y-1][z],
                                sum[y-1][z-1]) + 1;
            else
                sum[y][z] = 0;
        }
    }
}

void compute_bsq(int **map_matrix, char *map, char **matrix)
{
    struct Max_s max = {.y = 0, .z = 0, .sum = 0};
    struct Rect_s rect = {.width = get_width(map), .height = get_height(map)};
    int **sum = initialize_sum_matrix(rect.height, rect.width, map_matrix);

    populate_sum_matrix(sum, map_matrix, map);
    max.sum = sum[0][0];
    for (int y = 0; y < rect.height; y++) {
        for (int z = 0; z < rect.width; z++) {
            if (max.sum < sum[y][z]) {
                max.sum = sum[y][z];
                max.y = y;
                max.z = z;
            }
        }
    }
    show(max, map_matrix, matrix, rect);
    free_sum_matrix(rect.height, sum);
}
