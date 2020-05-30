/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** initialized_value
*/

#include "../include/my.h"

pos_t *initialized_value2(pos_t *pos)
{
    pos->y = 0;
    pos->x = 0;
    pos->i = 0;
    pos->j = 0;
    return (pos);
}

pos_t *initialized_value(pos_t *pos)
{
    write(0, "$\e[31m>\e[0m", 12);
    pos->mult = 0;
    pos->action_man = 0;
    pos->tab = NULL;
    pos->path = NULL;
    pos->total = NULL;
    pos->pass = 0;
    return (pos);
}