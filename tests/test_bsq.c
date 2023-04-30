/*
** EPITECH PROJECT, 2020
** test_bsq.c
** File description:
** BSQ Unit Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../lib/my/include/my_lib.h"
#include "../lib/my/bsq/include/my_bsq.h"
#include "../error_handling/include/my_error_handling.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(filesystem_open, successful)
{
    int file_ok = 0;
    file_ok = file_exists("tests/.map_001");
    cr_assert(file_ok);
}

Test(filesystem_open, epic_fail)
{
    int file_ok = 0;
    file_ok = file_exists("HAAAAAAAAAAAAAAA");
    cr_assert(!file_ok);
}

Test(boostix, my_putstr_test_debile, .init = redirect_all_std)
{
    my_putstr("oui pat'on vous êtes bien mon pat'on");
    cr_assert_stdout_eq_str("oui pat'on vous êtes bien mon pat'on");
}

Test(boostix, usage_error_return_value_when_its_true)
{
    int haaaaaaaaaaaaaaaaaaaa = usage_error(3);
    cr_assert(haaaaaaaaaaaaaaaaaaaa);
}

Test(boostix, usage_error_return_value_when_its_false)
{
    int haaaaaaaaaaaaaaaaaaaa = usage_error(2);
    cr_assert(!haaaaaaaaaaaaaaaaaaaa);
}

Test(boostix, file_does_not_exist_msg, .init = redirect_all_std)
{
    show_file_does_not_exist_error("coucou");
    cr_assert_stderr_eq_str("coucou does not exist.\n");
}

Test(error_handling, file_does_not_exist, .init = redirect_all_std)
{
    char *dummy_args[] = {"./bsq", "arg1", "arg2", "arg3", NULL};
    char **argv = dummy_args;
    error_handling(2, argv);
    cr_assert_stderr_eq_str("arg1 does not exist.\n");
}

Test(boostix, show_usage, .init = redirect_all_std)
{
    char *bsq = "./bsq";
    show_usage(bsq);
    cr_assert_stderr_eq_str("Usage: ./bsq {mapfile}\n");
}

Test(error_handling, wrong_usage, .init = redirect_all_std)
{
    char *dummy_args[] = {"./bsq", "arg1", "arg2", "arg3", NULL};
    char **argv = dummy_args;
    error_handling(1, argv);
    cr_assert_stderr_eq_str("Usage: ./bsq {mapfile}\n");
}

Test(error_handling, when_all_goes_fine, .init = redirect_all_std)
{
    char *dummy_args[] = {"./bsq", "tests/.map_001", "arg2", "arg3", NULL};
    char **argv = dummy_args;
    int ret = error_handling(2, argv);
    cr_assert(ret == 0);
}

Test(boostix, test_my_atoi)
{
    int my_nbr = 0;
    my_nbr = my_atoi("123");
    cr_assert(my_nbr == 123);
    my_nbr = my_atoi("1239");
    cr_assert(my_nbr == 1239);
    my_nbr = my_atoi("123456789");
    cr_assert(my_nbr == 123456789);
    my_nbr = my_atoi("123339");
    cr_assert(my_nbr == 123339);
}

Test(boostix, test_is_digit)
{
    int ass = 0;
    ass = is_digit('9');
    cr_assert(ass);
    ass = is_digit('A');
    cr_assert(!ass);
}

Test(test_my_revstr, palindroms)
{
    cr_expect_str_eq(my_revstr(strdup("SOS")), "SOS");
    cr_expect_str_eq(my_revstr(strdup("KAYAK")), "KAYAK");
}

Test(test_my_revstr, test_on_five_chars)
{
    cr_expect_str_eq(my_revstr(strdup("PpAvVa")), "aVvApP");
    cr_expect_str_eq(my_revstr(strdup("Mm8aAa")), "aAa8mM");
}

Test(test_my_revstr, test_on_seven_chars)
{
    cr_expect_str_eq(my_revstr(strdup("AaAaAaa")), "aaAaAaA");
    cr_expect_str_eq(my_revstr(strdup("BBbBBbb")), "bbBBbBB");
}

Test(test_my_revstr, test_on_eight_chars)
{
    cr_expect_str_eq(my_revstr(strdup("+++AAAAA")), "AAAAA+++");
    cr_expect_str_eq(my_revstr(strdup("\\/xyzXYZ")), "ZYXzyx/\\");
}

Test(test_str_include, naive_test)
{
    char c = 'A';
    char *str = "AAAAAAAAAAA";
    int b = str_include(str, c);
    cr_assert(b);
    c = 'B';
    b = str_include(str, c);
    cr_assert(!b);
}

Test(boostix, test_invalid_map_error_msg, .init = redirect_all_std)
{
    show_invalid_map_error();
    cr_assert_stderr_eq_str("Invalid map\n");
}

Test(map_checkers, right_line_length)
{
    char *map = "12\n..\n..\no.\no.\n..\n.o\n..\no.\n..\n.o\n..\n..\n";
    int test = incorrect_line_length(map);
    cr_assert(!test);
}

Test(map_checkers, invalid_line_length)
{
    char *map = "12\n..\n..\no.\no.\n....\n.o\n..\no.\n..\n";
    int test = incorrect_line_length(map);
    cr_assert(test);
}

Test(map_checkers, incorrect_map_file)
{
    char *map = "..";
    int test = incorrect_line_length(map);
    cr_assert(!test);
}

Test(map_checkers, incorrect_chars)
{
    char *map = "12\n..\n..\no.\nox\n.a\n.o\nx.\no.\n..\n.o\n..\n..\n";
    int test = incorrect_chars(map);
    cr_assert(test);
}

Test(map_checkers, right_chars)
{
    char *map = "12\n..\n..\no.\no.\n..\n.o\n..\no.\n..\n.o\n..\n..\n";
    int test = incorrect_chars(map);
    cr_assert(!test);
}

Test(map_checkers, invalid_lines_amount)
{
    char *map = "12\n..\n..\no.\no.\n..\n.o\n..\no.\n..\n";
    int test = incorrect_lines_amount(map, 12);
    cr_assert(test);
}

Test(map_checkers, right_lines_amount)
{
    char *map = "4\n.o.o...o..........oo..o....o......o....o........o.............o..o.................o.............o..\n...........oo..o.o......o..............o...oo..o...o......o.o..oo...............o..oo.........o.....\n....o.o.....o....o..oo...................o...oo......o.....o.o........................o......o......\n........oo.............o......o..........o.....o..o......o...o.......o...o....o.....................\n";
    int test = incorrect_lines_amount(map, 4);
    cr_assert(!test);
}

Test(map_checkers, incorrect_map_header)
{
    char *map = "-12qsdqs2323\n..\n..\no.\no.\n..\n.o\n..\no.\n..\n.o\n..\n..\n";
    int test = incorrect_map_header(map);
    cr_assert(test);
}

Test(map_checkers, incorrect_map_header2)
{
    char *map = "12";
    int test = incorrect_map_header(map);
    cr_assert(test);
}

Test(map_checkers, right_map_header)
{
    char *map = "12\n..\n..\no.\no.\n..\n.o\n..\no.\n..\n.o\n..\n..\n..\n";
    int test = incorrect_map_header(map);
    cr_assert(!test);
}

Test(my_maths, stupid_test)
{
    int x = 4;
    int y = 0;
    int z = 0;
    int res = min(x, y, z);
    cr_assert(res == 0);
}

Test(my_maths, another_stupid_test)
{
    int x = 4;
    int y = 3;
    int z = 0;
    int res = min(x, y, z);
    cr_assert(res == 0);
}

Test(my_maths, one_more_stupid_test)
{
    int x = 0;
    int y = 2;
    int z = 4;
    int res = min(x, y, z);
    cr_assert(res == 0);
}
