/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Entry Point
*/

#include "../include/my_main_funs.h"
#include "../lib/my/bsq/include/my_bsq.h"
#include "../lib/my/include/my_lib.h"
#include "../error_handling/include/my_error_handling.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int run(int argc, char **argv)
{
    int file_descriptor = open(argv[1], O_RDONLY);
    char *buffer = NULL;
    int first_line_nbr = 0;
    struct stat file;
    if (error_handling(argc, argv))
        return (84);
    stat(argv[1], &file);
    buffer = malloc(sizeof(char) * file.st_size + 1);
    read(file_descriptor, buffer, file.st_size);
    buffer[file.st_size + 1] = '\0';
    if (incorrect_map_header(buffer))
        return (84);
    first_line_nbr = get_first_line_nbr(buffer);
    if (incorrect_lines_amount(buffer, first_line_nbr)
        || incorrect_chars(buffer)
        || incorrect_line_length(buffer))
        return (84);
    render_bsq(buffer);
    close(file_descriptor);
    return (0);
}

int main(int argc, char **argv)
{
    return (run(argc, argv));
}
