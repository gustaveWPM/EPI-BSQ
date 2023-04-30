/*
** EPITECH PROJECT, 2020
** my_str_funs.c
** File description:
** String Functions
*/

#include <unistd.h>

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int my_strlen(char const *str)
{
    int len = 0;
    while (str[len] != '\0')
        len += 1;
    return (len);
}

char *my_revstr(char *str)
{
    int index = 0;
    int rev_index = my_strlen(str) - 1;
    char memo_char;

    while (index < rev_index) {
        memo_char = str[rev_index];
        str[rev_index] = str[index];
        str[index] = memo_char;
        index += 1;
        rev_index -= 1;
    }
    return (str);
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_puterr(char const *err)
{
    write(2, err, my_strlen(err));
}
