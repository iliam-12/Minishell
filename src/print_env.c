/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** print_env
*/

#include "../include/my.h"


void print_env(char **tab, pos_t *pos)
{
    pos->pass = 1;
    for (int i = 0; tab[i]; i++)
        my_putstr(tab[i]);
}