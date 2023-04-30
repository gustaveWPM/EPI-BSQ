/*
** EPITECH PROJECT, 2020
** error_handling.c
** File description:
** Error handling driver and subfunctions
*/

#include "include/my_error_handling.h"
#include "../lib/my/bsq/include/my_bsq.h"
#include "../lib/my/include/my_lib.h"
#include <stdio.h>

int usage_error(int argc)
{
    if (argc != 2)
        return (1);
    return (0);
}

int error_handling(int argc, char **argv)
{
    int file_ok = 0;
    if (usage_error(argc)) {
        show_usage(argv[0]);
        return (1);
    }
    file_ok = file_exists(argv[1]);
    if (!file_ok) {
        show_file_does_not_exist_error(argv[1]);
        return (1);
    }
    return (0);
}
