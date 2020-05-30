/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** arguments
*/

#include "../include/my.h"

int _line(char const *str)
{
    int i = 0;
    int line = 0;

    while (str[i] != '\0') {
        i++;
        if (str[i] == ' ')
            line++;
    }
    return (line + 1);
}

int _char(char const *str, int i)
{
    while (str[i] != '\0')
        i++;
    return (i + 1);
}

char **arguments(char const *str)
{
    int line = _line(str), len = 0, i = 0, x = 0, y = 0;
    char **tab;

    if ((tab = malloc(sizeof(char *) * (line + 1))) == NULL)
        return (NULL);
    x = 0;
    y = 0;
    for (; y != line; y++) {
        len = _char(str, i);
        if ((tab[y] = malloc(sizeof(char) * (len + 1))) == NULL)
            return (NULL);
        while (str[i] != ' ' && str[i] != '\0') {
            tab[y][x] = str[i];
            x++;
            i++;
        }
        i++;
        tab[y][x] = '\0';
        x = 0;
    }
    return (tab);
}