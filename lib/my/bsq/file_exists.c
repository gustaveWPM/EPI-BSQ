/*
** EPITECH PROJECT, 2020
** file_exists.c
** File description:
** Checks if the file exists. Returns 0 if it's not the case, otherwise 1.
*/

#include <fcntl.h>
#include <unistd.h>
#include "../include/my_lib.h"

int file_exists(char const *filepath)
{
    int file_descriptor = open(filepath, O_RDONLY);
    if (file_descriptor != -1) {
        close(file_descriptor);
        return (1);
    }
    close(file_descriptor);
    return (0);
}
