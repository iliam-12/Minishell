/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_getenv
*/

#include "../include/my.h"

pos_t *total_double_point(char *env, pos_t *pos)
{
    pos->total_db = 0;
    for (int i = 0; env[i]; i++) {
        if (env[i] == ':')
            pos->total_db++;
    }
    return (pos);
}

int treatment_path(char **env, pos_t *pos)
{
    int line = nb_line(env, 0);
    int len = nb_len(env, 0, 0);

    pos->x = 0, pos->y = 0;
    total_double_point(env[pos->i], pos);
    pos->tab = malloc(sizeof(char *) * (line + 1));
    pos->tab[pos->y] = malloc(sizeof(char) * (len + 1));
    while (env[pos->i][pos->j] != ':') {
        pos->tab[pos->y][pos->x] = env[pos->i][pos->j];
        if (env[pos->i][pos->j + 1]) {
            pos->x++;
            pos->j++;
        }
        if (!env[pos->i][pos->j + 1])
            return (0);
    }
    return (0);
}

int search_path(char **env, char *name, pos_t *pos)
{
    int size = my_strlen(name);
    int banane = 0, db = 0;

    while (env[pos->i][0] == 'P' && env[pos->i][pos->j] == name[pos->j]) {
        pos->j++;
        banane++;
    }
    while (banane == my_strlen(name) && db != pos->mult) {
        pos->j++;
        if (env[pos->i][pos->j] == ':')
            db++;
    }
    if (size == banane) {
        pos->j++;
        if (treatment_path(env, pos) == 1)
            return (1);
    }
    return (0);
}

int my_getenv_sys(char **env, char *name, pos_t *pos)
{
    while (env[pos->i][pos->j]) {
        if (search_path(env, name, pos) == 1)
            return (1);
        pos->j++;
        if (!env[pos->i][pos->j + 1] && env[pos->i + 1]) {
            pos->i++;
            pos->j = 0;
        }
    }
    return (2);
}