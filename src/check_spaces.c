/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** check_spaces
*/

#include "../include/my.h"

int delete_before(char *str)
{
    int i = 0;

    while (str[i] == '@')
        i++;
    return (i);
}

char *delete_point(char *str)
{
    int i = 0, j = 0;
    char *new_str = malloc(sizeof(char) * my_strlen(str));

    while (str[i]) {
        if (str[i] != '@') {
            new_str[j] = str[i];
            j++;
        }
        i++;
    }
    return (new_str);
}

char *delete_end(char *str)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * my_strlen(str));

    while (str[i]) {
        new_str[i] = str[i];
        if (str[i] != ' ' && str[i + 1] == ' '
            && (str[i + 2] == ' ' || !str[i + 2]))
            return (new_str);
        i++;
    }
    return (new_str);
}

char *check_spaces(char *str)
{
    int i = 0;

    if (str[0] == '@' && str[1] == '/')
        return (str);
    while (str[i]) {
        if (str[i] == ' ' || str[i] == '\t')
            str[i] = '@';
        i++;
    }
my_putstr(str);
my_putchar('\n');
    i = delete_before(str);
    while (str[i]) {
        if (str[i] == '@' && str[i + 1] != '@')
            str[i] = ' ';
        i++;
    }
    str = let_one_space(str);
    str = delete_end(str);
my_putstr(str);
my_putchar('\n');
    return (str);
}