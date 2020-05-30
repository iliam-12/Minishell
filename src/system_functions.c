/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** fonction_system
*/

#include "../include/my.h"

void errno_messages(char **avv)
{
    if (errno == EACCES) {
        my_putstr(avv[0]);
        my_putstr(": Permission denied.\n");
    }
    if (errno == ENOEXEC) {
        my_putstr(avv[0]);
        my_putstr(": Exec format error. Wrong Architecture.\n");
    }
    if (errno == ENOENT) {
        my_putstr(avv[0]);
        my_putstr(": Command not found.\n");
    }
}

int suite(char **avv, char **env, pos_t *pos)
{
    pos->path = pos->tab[pos->y];
    pos->total = my_strcat(my_strcat(avv[0], "/"), pos->path);
    if (access(pos->total, X_OK) == -1)
        pos->mult++;
    if (access(pos->total, X_OK) == 0) {
        int child = 0;
        if (fork() == 0)
            execve(pos->total, avv, env);
        else wait(&child);
        pos->action_man++;
        return (0);
    }
    if (pos->mult == pos->total_db + 1) {
        my_putstr(avv[0]);
        my_putstr(": Command not found.\n");
        return (1);
    }
    return (0);
}

int check_path_exist(char **env)
{
    int i = 0;
    char **tabe = tab_e(env);

    while (tabe[i]) {
        if (my_strcmp(tabe[i], "PATH") == 0)
            return (0);
        i++;
    }
    return (1);
}

int execve_slash(char **avv, char **env)
{
    pid_t pid;

    if (avv[0][0] == '/' || avv[0][0] == '.') {
        if ((pid = fork()) == 0) {
            execve(avv[0], avv, env);
            errno_messages(avv);
            kill(pid, SIGCHLD);
            exit(0);
        }
        else wait(pid);
        return (1);
    }
    return (0);
}

pos_t *fsystem(pos_t *pos, char **env, char **avv)
{
    if (execve_slash(avv, env) == 1)
        return (pos);
    while (pos->action_man == 0) {
        initialized_value2(pos);
        if (check_path_exist(env) == 1
        || my_getenv_sys(env, "PATH", pos) == 1) {
            my_putstr(avv[0]);
            my_putstr(": Command not found.\n");
            return (pos);
        }
        if (suite(avv, env, pos) == 1)
            return (pos);
    }
    return (pos);
}