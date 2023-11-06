/*
** EPITECH PROJECT, 2020
** list for minishella
** File description:
** should help
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "./include/my.h"
#include <errno.h>
#include <sys/wait.h>


#ifndef LIST_shell
#define LIST_shell

struct shell
{
    int line;
    int exit;
    char **env;
    int spaces;
    int no;
};

typedef struct shell shell_t;

void my_exit(shell_t *sh, char *buffer);
char *my_getenv(char *str, char **env);
void my_env(shell_t *sh);
void my_setenv(shell_t *sh, char *buffer);
char *del_backslash(char *buffer);
void my_unsetenv(shell_t *sh, char *buffer);
void my_cd(shell_t *sh, char *buffer);
void reset_env(shell_t *sh, char *new_pwd, char *old_pwd);
int errno_error(shell_t *sh, char *str);
char *del_spaces(shell_t *sh, char *buffer);
char *del_tabulation(shell_t *sh, char *buffer);
void my_path(shell_t *sh, char *buffer);

#endif