/*
** EPITECH PROJECT, 2020
** errors_msg.c
** File description:
** Error messages
*/

#include "../lib/my/include/my_lib.h"

void show_invalid_map_error(void)
{
    my_puterr("Invalid map\n");
}

void show_usage(char *filename)
{
    my_puterr("Usage: ");
    my_puterr(filename);
    my_puterr(" {mapfile}\n");
}

void show_file_does_not_exist_error(char *filename)
{
    my_puterr(filename);
    my_puterr(" does not exist.\n");
}
