/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

/* ___ INCLUDES ___ */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libgnl/gnl.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <errno.h>

/* ___ STRUCTURES ___ */

struct pos
{
    int i;
    int j;
    int y;
    int x;
    int no_path;
    int mult;
    int pass;
    int action_man;
    int setenv;
    int toto;
    int correct_path;
    char **tab;
    char *path;
    char *total;
}; typedef struct pos pos_t;

/* ___ FONCTIONS ___ */

void my_putchar(char);
char *my_putstr(char const *);
int my_strlen(char const *);
int my_env(char **);
int my_ls(char *);
void initialized_value(pos_t *);
char *treatment_path(char **, pos_t *);
int minishell2(int, char **, char **);
int my_strcmp(char const *, char const *);
char **arguments(char const *);
void fsystem(pos_t *pos, char **env, char **avv);
char **tab_equal(char **env);
char **my_environment(char **my_env, char **env, char **avv, pos_t *pos);
int _line(char const *str);
int _len(char const *str, int i);
int nb_line(char **env, int i);
int nb_len(char **env, int i, int j);
char *my_strcat(char *debut, char *fin);
char **printtab(char **tab, char **avv, pos_t *pos);
int check_avv_exist(char **tabe, char **tab, char **avv);
char **print_env(char **tab, char **env, char **avv, pos_t *pos);
int char_isnbr(char nb);
int my_strncmp(char const *s1, char const *s2, int n);
int check_path_exist(char **tabe, char **env, char *avv);
int path_is_empty(char **env, char *avv);
void suite(char **avv, char **env, pos_t *pos, char *fsystem);

#endif /* !MY_H_ */
