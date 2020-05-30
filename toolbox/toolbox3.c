/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** toolbox3
*/

#include "../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (my_strlen(s1) < n || my_strlen(s2) < n) return (84);
    while (my_strlen(s1) <= n && my_strlen(s2) <= n) {
        if (s1[i] == s2[i])
            i++;
        else
            return (84);
        n++;
    }
    return (0);
}