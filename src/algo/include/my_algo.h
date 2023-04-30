/*
** EPITECH PROJECT, 2020
** my_algo.h
** File description:
** Algo functions prototypes
*/

void bypass_coding_style(int *x_index, int *y_index, int *index);
int *cast_char_map_to_int(char *map);
char **build_matrix(char *map);
int **build_int_matrix(int *map, char *map_c);
int **initialize_sum_matrix(int height, int width, int **matrix);
void compute_bsq(int **map_matrix, char *map, char **matrix);
char *flatten_char_matrix(char **matrix, int height, int width);
