/*
** EPITECH PROJECT, 2020
** my_str_funs2.c
** File description:
** More str functions
*/

int str_include(const char *pattern, char c)
{
    int i = 0;
    while (pattern[i] != '\0') {
        if (pattern[i] == c)
            return (1);
        i += 1;
    }
    return (0);
}
