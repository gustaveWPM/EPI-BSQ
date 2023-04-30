/*
** EPITECH PROJECT, 2020
** matrix.c
** File description:
** Matrixes builders
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_main_funs.h"
#include "../../lib/my/include/my_lib.h"
#include "include/my_algo.h"
#include <stdio.h>

int **initialize_sum_matrix(int height, int width, int **map_matrix)
{
    int index = 0;
    int x_index = 0;
    int y_index = 0;
    int **sum = (int **) malloc(height * sizeof(int *));

    if (sum == NULL)
        exit(84);
    for (y_index = 0; y_index < height; y_index++) {
        sum[y_index] = malloc(width * sizeof(int));
        if (sum[y_index] == NULL)
            exit(84);
    }
    for (int i = 0; i < height; i++)
        sum[i][0] = map_matrix[i][0];
    for (int j = 0; j < width; j++)
        sum[0][j] = map_matrix[0][j];
    return (sum);
}

int **build_int_matrix(int *map, char *map_c)
{
    int width = get_width(map_c);
    int height = get_height(map_c);
    int index = 0;
    int x_index = 0;
    int y_index = 0;
    int **matrix = (int **) malloc(height * sizeof(int *));
    for (y_index = 0; y_index < height; y_index++)
        matrix[y_index] = malloc(width * sizeof(int));
    for (index = 0; map[index] != 69; index++);
    index += 1;
    y_index = 0;
    for (x_index = 0; x_index < width; x_index++) {
        matrix[y_index][x_index] = map[index];
        index += 1;
        if (map[index] == 69)
            bypass_coding_style(&x_index, &y_index, &index);
        if (y_index >= height)
            break;
    }
    return (matrix);
}

char *flatten_char_matrix(char **matrix, int height, int width)
{
    int index = 0;
    int x = 0;
    int y = 0;
    char *res;
    long long mem = 0;
    mem = width * height;
    mem += height + 2;
    res = malloc(sizeof(char) * mem);
    if (res == NULL)
        exit(84);
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            res[index] = matrix[y][x];
            index += 1;
        }
        res[index] = '\n';
        index += 1;
    }
    res[index] = '\0';
    return (res);
}

char **build_matrix(char *map)
{
    int width = get_width(map);
    int height = get_height(map);
    int index = 0;
    int x_index = 0;
    int y_index = 0;
    char **matrix = (char **) malloc(height * sizeof(char *));
    for (y_index = 0; y_index < height; y_index++)
        matrix[y_index] = malloc(width * sizeof(char));
    for (index = 0; map[index] != '\n'; index++);
    index += 1;
    y_index = 0;
    for (x_index = 0; x_index < width; x_index++) {
        matrix[y_index][x_index] = map[index];
        index += 1;
        if (map[index] == '\n')
            bypass_coding_style(&x_index, &y_index, &index);
        if (y_index >= height)
            break;
    }
    return (matrix);
}
