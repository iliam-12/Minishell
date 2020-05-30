/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** minishell2
*/

#include "../include/my.h"

pos_t *fonctions(char **avv, char **my_env, pos_t *pos, char *str)
{
    if (my_strcmp(avv[0], "setenv") == 0 && avv[1])
        printtab(my_env, avv, pos);
    if (my_strcmp(avv[0], "unsetenv") == 0)
        printtab(my_env, avv, pos);
    if (my_strcmp(str, "setenv") == 0 || my_strcmp(str, "env") == 0)
        print_env(my_env, pos);
    if (my_strcmp(avv[0], "cd") == 0)
        my_cd(my_env, avv, pos);
    return (pos);
}

int minishell2(char **env, pos_t *pos)
{
    char **avv = NULL, *str = NULL, **my_env = NULL;

    while (1) {
        initialized_value(pos);
        str = get_next_line(0);
        if (str == NULL || my_strcmp(str, "exit") == 0) {
            write(0, "exit\n", 5);
            return (0);
        }
        str = check_spaces(str);
        avv = arguments(str);
        if (my_strlen(avv[0]) == 0)
            pos->pass = 1;
        if (pos->toto == 0)
            my_env = my_environment(env, pos);
        fonctions(avv, my_env, pos, str);
        if (pos->pass == 0)
            fsystem(pos, my_env, avv);
    }
    return (0);
}