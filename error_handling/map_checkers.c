/*
** EPITECH PROJECT, 2020
** map_checkers.c
** File description:
** Map Checkers
*/

#include "../lib/my/include/my_lib.h"
#include <stdio.h>
#include <unistd.h>

int incorrect_line_length(char *map)
{
    int index = 0;
    int expected_len = 0;
    int current_len = 0;
    while (map[index] != '\n')
        index += 1;
    index += 1;
    while (map[index + expected_len] != '\n')
        expected_len += 1;
    index += expected_len + 1;
    while (map[index] != '\0') {
        while (map[index] != '\n') {
            index += 1;
            current_len += 1;
        }
        if (current_len != expected_len)
            return (1);
        current_len = 0;
        index += 1;
    }
    return (0);
}

int incorrect_chars(char *map)
{
    int i = 0;
    const char *pattern = ".o\n";
    while (map[i] != '\n')
        i += 1;
    while (map[i] != '\0') {
        if (!str_include(pattern, map[i]))
            return (1);
        i += 1;
    }
    return (0);
}

int incorrect_lines_amount(char *map, int nlines)
{
    int i = 0;
    int counter = 0;
    while (map[i] != '\0') {
        if (map[i] == '\n')
            counter += 1;
        i += 1;
    }
    if (counter - 1 == nlines)
        return (0);
    return (1);
}

int incorrect_map_header(char *map)
{
    int end_of_first_line_index = 0;
    while (map[end_of_first_line_index] != '\n') {
        if (map[end_of_first_line_index] == '\0')
            return (1);
        if (!is_digit(map[end_of_first_line_index]))
            return (1);
        end_of_first_line_index += 1;
    }
    return (0);
}
