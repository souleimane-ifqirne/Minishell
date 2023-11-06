/*
** EPITECH PROJECT, 2020
** mysh
** File description:
** cd2
*/

#include "list.h"

int errno_error(shell_t *sh, char *str)
{
    if (errno == ENOENT) {
        write(2, str, my_strlen(str));
        write(2, ": No such file or directory.\n", 29);
        return (1);
    } if (errno == ENOTDIR) {
        write(2, str, my_strlen(str));
        write(2, ": Not a directory.\n", 20);
        return (1);
    }
    return (0);
}

int change_oldpwd(shell_t *sh, char *old_pwd)
{
    int line = 0;

    for (; sh->env[line]; line++) {
        if (!my_strncmp("OLDPWD=", sh->env[line], 7)) {
            break;
        }
    }
    sh->env[line] = old_pwd;
    return (line);
}

int change_pwd(shell_t *sh, char *new_pwd)
{
    int line = 0;

    for (; sh->env[line]; line++) {
        if (!my_strncmp("PWD=", sh->env[line], 4)) {
            break;
        }
    }
    sh->env[line] = new_pwd;
    return (line);
}

void reset_env(shell_t *sh, char *new_pwd, char *old_pwd)
{
    if (my_getenv("PWD=", sh->env)) {
        change_pwd(sh, new_pwd);
    } if (my_getenv("OLDPWD=", sh->env)) {
        change_oldpwd(sh, old_pwd);
    }
    return;
}
