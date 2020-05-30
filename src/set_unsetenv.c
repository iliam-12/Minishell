/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_setenv
*/

#include "../include/my.h"

char **delete_line(char **tabe, char **tab, char **avv)
{
    int i = 0;
    int word = 1;

    while (tabe[i]) {
        if (avv[word] && my_strcmp(tabe[i], avv[word]) == 0) {
            tab[i] = "\0";
            word++;
            i = -1;
        }
        i++;
    }
    return (tab);
}

int check_avv_exist(char **tabe, char **tab, char **avv)
{
    for (int i = 0; tabe[i]; i++) {
        if (my_strcmp(tabe[i], avv[1]) == 0) {
            if (!avv[2])
                tab[i] = my_strcat("=\n", tabe[i]);
            if (avv[2])
                tab[i] = my_strcat
                ("\n", my_strcat(avv[2], my_strcat("=", avv[1])));
            return (1);
        }
        i++;
    }
    return (0);
}

char **tab_e(char **tab)
{
    int i = 0, j = 0;
    char **tab_e = tab;
    int line = nb_line(tab_e, 0);
    int len = _char(tab_e[i], 0);

    if ((tab_e = malloc(sizeof(char *) * (line + 999))) == NULL)
        return (NULL);
    for (int y = 0; y != line; y++) {
        if ((tab_e[y] = malloc(sizeof(char) * (len + 999))) == NULL)
            return (NULL);
    }
    while (tab[i]) {
        tab_e[i][j] = tab[i][j];
        j++;
        if (tab[i][j] == '=') {
            tab_e[i][j+1] = '\n';
            i++;
            j = 0;
        }
    }
    return (tab_e);
}

char **add_end(char **tab, char **avv)
{
    int y = 0;

    while (tab[y])
        y++;
    if (!tab[y] && avv[1]) {
        if (char_isnbr(avv[1][0]) == 0) {
            return (tab);
        }
        tab[y] = avv[1];
        tab[y] = my_strcat("=", tab[y]);
        if (!avv[2])
            tab[y] = my_strcat("\n", tab[y]);
        if (avv[2])
            tab[y] = my_strcat("\n", my_strcat(avv[2], tab[y]));
    }
    return (tab);
}

char **printtab(char **tab, char **avv, pos_t *pos)
{
    char **tabe = tab_e(tab);

    pos->pass = 1;
    if (!avv[1])
        return (tab);
    if (check_alphanum(avv[1], avv[0]) == 84)
        return (tab);
    if (my_strcmp(avv[0], "unsetenv") == 0) {
        tab = delete_line(tabe, tab, avv);
        return (tab);
    }
    if (check_avv_exist(tabe, tab, avv) == 0)
        tab = add_end(tab, avv);
    return (tab);
}