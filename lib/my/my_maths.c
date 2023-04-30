/*
** EPITECH PROJECT, 2020
** my_maths.c
** File description:
** Hai Diddle Dee Dee!
*/

int min(int x, int y, int z)
{
    int min = x;
    if (min > y)
        min = y;
    if (min > z)
        min = z;
    return (min);
}
