/*
** EPITECH PROJECT, 2020
** mysh
** File description:
** cd
*/

#include "list.h"

int errno_error_straight(shell_t *sh)
{
    if (errno == ENOENT) {
        write(2, my_getenv("HOME=", sh->env),
        my_strlen(my_getenv("HOME=", sh->env)));
        write(2, ": No such file or directory.\n", 29);
        return (1);
    } if (errno == ENOTDIR) {
        write(2, my_getenv("HOME=", sh->env),
        my_strlen(my_getenv("HOME=", sh->env)));
        write(2, ": Not a directory.\n", 20);
        return (1);
    }
    return (0);
}

void cd_straight(shell_t *sh, char *old_pwd)
{
    char *new_pwd = NULL;

    if (chdir(my_getenv("OLDPWD=", sh->env)) == -1
    && my_getenv("OLDPWD=", sh->env)) {
        if (errno_error_straight(sh) == 1) return;
    }
    if (my_getenv("OLDPWD=", sh->env)) {
        new_pwd = my_strcat("PWD=", my_getenv("OLDPWD=", sh->env));
        reset_env(sh, new_pwd, old_pwd);
    } return;
}

void cd_two_arg(shell_t *sh, char **str)
{
    char *new_pwd = NULL;
    char *old_pwd = NULL;

    if (my_getenv("PWD=", sh->env))
        old_pwd = my_strcat("OLDPWD=", my_getenv("PWD=", sh->env));
    if (!my_strcmp(str[1], "-")) {
        cd_straight(sh, old_pwd);
        return;
    } if (chdir(str[1]) == -1)
        if (errno_error(sh, str[1]) == 1) return;
    new_pwd = my_strcat("PWD=", getcwd(NULL, 500));
    reset_env(sh, new_pwd, old_pwd);
    return;
}

void cd_one_arg(shell_t *sh)
{
    char *new_pwd = NULL;
    char *old_pwd = NULL;

    if (my_getenv("HOME=", sh->env))
        new_pwd = my_strcat("PWD=", my_getenv("HOME=", sh->env));
    if (my_getenv("PWD=", sh->env))
        old_pwd = my_strcat("OLDPWD=", my_getenv("PWD=", sh->env));
    if (chdir(my_getenv("HOME=", sh->env)) == -1
    && my_getenv("HOME=", sh->env)) {
        if (errno == ENOENT) {
            write(2, my_getenv("HOME=", sh->env),
            my_strlen(my_getenv("HOME=", sh->env)));
            write(2, ": No such file or directory.\n", 29);
        } if (errno == ENOTDIR) {
            write(2, my_getenv("HOME=", sh->env),
            my_strlen(my_getenv("HOME=", sh->env)));
            write(2, ": Not a directory.\n", 20);
        } return;
    } reset_env(sh, new_pwd, old_pwd);
    return;
}

void my_cd(shell_t *sh, char *buffer)
{
    char **str = NULL;
    int nb = 0;

    sh->no = 1;
    buffer = del_backslash(buffer);
    str = my_str_to_word_array(buffer, ' ');
    for (; str[nb]; nb++);
    if (nb == 1) cd_one_arg(sh);
    if (nb == 2) cd_two_arg(sh, str);
    if (nb > 2) write(2, "cd: Too many arguments.\n", 24);
    return;
}