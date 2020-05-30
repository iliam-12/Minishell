/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_environment
*/

#include "../include/my.h"

char **my_environment(char **env, pos_t *pos)
{
    int i = 0;
    char **my_env = env;
    int line = nb_line(my_env, 0);
    int len = _char(my_env[i], 0);
                                // allocation de mémoire du **my_env.
    if ((my_env = malloc(sizeof(char *) * (line + 9999))) == NULL)
        return (NULL);
    for (int y = 0; y != line; y++) {
        if ((my_env[y] = malloc(sizeof(char) * (len + 9999))) == NULL)
            return (NULL);
    }
    while (env[i]) {           // copie ligne par ligne le env du main.
        my_env[i] = env[i];
        my_env[i] = my_strcat("\n", my_env[i]);
        i++;
    }
    pos->toto++;
    return (my_env);
}