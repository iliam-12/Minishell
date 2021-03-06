/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** toolbox
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

char *my_putstr(char const *str)
{
    int i = 0;

    while (str[i])
        my_putchar(str[i++]);
    return (str);
}

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL) return (0);
    for (i = 0; str[i]; i++);
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2)) return (84);
    while (s1[i] && s2[i]) {
        if (s1[i] == s2[i])
            i++;
        else
            return (84);
    } return (0);
}