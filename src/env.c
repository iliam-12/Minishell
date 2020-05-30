/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** env
*/

#include "../include/my.h"

int my_env(char **env)
{
    int i = 0;

    while (env[i]) {
        my_putstr(env[i++]);
        my_putchar('\n');
    }
    return (0);
}