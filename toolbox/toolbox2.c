/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** toolbox2
*/

#include "../include/my.h"

int char_isnbr(char nb)
{
    if (nb >= '0' && nb <= '9')
        return (0);
    return (84);
}

int nb_line(char **env, int i)
{
    while (env[i])
        i++;
    return (i);
}

int nb_len(char **env, int i, int j)
{
    while (env[i][j])
        j++;
    return (j);
}

char *my_strcat(char *debut, char *fin)
{
    int a = 0;
    int b = 0;
    int size_d = my_strlen(debut);
    int size_fin = my_strlen(fin);
    char *total = malloc(sizeof(char) * (size_d + size_fin + 1));

    while (debut[b]) {
        while (fin[a]) {
            total[a] = fin[a];
            a++;
        }
        while (debut[b]) {
            total[a] = debut[b];
            a++;
            b++;
        }
        total[a] = '\0';
    }
    return (total);
}