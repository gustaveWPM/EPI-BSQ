/*
** EPITECH PROJECT, 2020
** my_error_handling.h
** File description:
** Error handling functions prototypes
*/

int incorrect_line_length(char *map);
int incorrect_chars(char *map);
int incorrect_lines_amount(char *map, int nlines);
int incorrect_map_header(char *map);
int usage_error(int argc);
int error_handling(int argc, char **argv);
void show_usage(char *filename);
void show_file_does_not_exist_error(char *filename);
void show_invalid_map_error(void);
