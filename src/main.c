/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** main
*/

#include "../include/my.h"

int main(int ac, char **av, char **env)
{
    pos_t *pos = malloc(sizeof(pos_t));

    if (ac != 1)
        return (0);
    if (minishell2(env, pos) == 84)
        return (84);
    return (0);
}