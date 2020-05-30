/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_cd
*/

#include "../include/my.h"

char *delete_slash_n(char *str)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * 999);

    while (str[i]) {
        if (str[i] != '\n')
            new_str[i] = str[i];
        i++;
    }
    return (new_str);
}

char **reset_pwd(char **env, char **avv, char *my_home)
{
    int i = 0;

    while (env[i] && !avv[1]) {
        if (my_strncmp(env[i], "PWD=", 4) == 0) {
            env[i] = delete_slash_n(env[i]);
            env[i] = my_strcat(my_home, "PWD=");
            env[i] = my_strcat("\n", env[i]);
        }
        i++;
    }
    while (env[i]) {
        if (my_strncmp(env[i], "PWD=", 4) == 0) {
            env[i] = my_strcat(getcwd(NULL, 400), "PWD=");
            env[i] = my_strcat("\n", env[i]);
        }
        i++;
    }
    return (env);
}

char *find_home(char **env)
{
    int i = 0;
    char *str = NULL;

    while (env[i]) {
        if (my_strncmp(env[i], "HOME=", 5) == 0) {
            str = env[i];
            str = delete_slash_n(str);
            return (str);
        }
        i++;
    }
    return (NULL);
}

char *delete_home_start(char *str)
{
    int i = 5, j = 0;
    char *new_str = malloc(sizeof(char) * my_strlen(str));

    while (str[i]) {
        new_str[j] = str[i];
        j++;
        i++;
    }
    return (new_str);
}

pos_t *my_cd(char **env, char **avv, pos_t *pos)
{
    char *my_home = NULL;

    if (my_strcmp(avv[0], "cd") == 84 || avv[2])
        return (pos);
    if (my_strcmp(avv[0], "cd") == 0 && !avv[1]) {
        my_home = find_home(env);
        my_home = delete_home_start(my_home);
        chdir(my_home);
        pos->pass = 1;
    }
    if (chdir(avv[1]) == -1 && avv[1]) {
        my_putstr(avv[1]);
        my_putstr(": No such file or directory.\n");
        pos->pass = 1;
        return (pos);
    }
    reset_pwd(env, avv, my_home);
    pos->pass = 1;
    return (pos);
}