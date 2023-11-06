/*
** EPITECH PROJECT, 2020
** mysh
** File description:
** setenv
*/

#include "list.h"

int setenv_alpha(char **str)
{
    int test_error = 0;

    for (int i = 0; str[1] && str[1][i] != '\0'; i++) {
        if (str[1][i] != '.' && str[1][i] != '_' && str[1][i] != ';')
            test_error += 1;
        if (str[1][i] > 54 || str[1][i] < 48) test_error += 1;
        if (str[1][i] > 122 || str[1][i] < 97) test_error += 1;
        if (str[1][i] > 90 || str[1][i] < 65) test_error += 1;
        if (test_error == 4) return (1);
        else test_error = 0;
    } return (0);
}

void setenv_new(shell_t *sh, char **str)
{
    char **temp_env = sh->env;
    char *new_line = NULL;
    int tab_arguments = 0;

    for (; str && str[tab_arguments]; tab_arguments++);
    if (tab_arguments == 3)
        new_line = my_strcat(str[1], my_strcat("=", str[2]));
    if (tab_arguments == 2) new_line = my_strcat(str[1], "=");
    for (sh->line = 0; sh->env[sh->line]; sh->line++);
    sh->line += 1;
    sh->env = malloc(sizeof(char *) * (sh->line + 1));
    for (int i = 0; temp_env[i] && temp_env; i++)
        sh->env[i] = temp_env[i];
    sh->env[sh->line - 1] = malloc(sizeof(char) * my_strlen(new_line));
    for (int i = 0; new_line[i] && new_line; i++)
        if (new_line[i] != '\n') sh->env[sh->line - 1][i] = new_line[i];
    sh->env[sh->line] = NULL;
}

void setenv_exist(shell_t *sh, char **str)
{
    int i = 0;

    for (; sh->env[i]; i++) {
        if (!my_strncmp(my_strcat(str[1], "="),
        sh->env[i], my_strlen(str[1]) + 1))
            break;
    } if (str[2])
        sh->env[i] = my_strcat(str[1], my_strcat("=", str[2]));
    else
        sh->env[i] = my_strcat(str[1], "=");
    return;
}

void env_edit(char **str, shell_t *sh)
{
    char **temp_env = sh->env;

    if (my_getenv(str[1], sh->env)) {
        setenv_exist(sh, str);
    } else
        setenv_new(sh, str);
    return;
}

void my_setenv(shell_t *sh, char *buffer)
{
    char **str = NULL;
    int nb = 0;

    buffer = del_backslash(buffer);
    str = my_str_to_word_array(buffer, ' ');
    for (; str[nb]; nb++);
    if (nb == 1) my_env(sh);
    else if (nb < 4) {
        if (setenv_alpha(str) == 1) {
            write(2, "setenv: Variable name must contain", 34);
            write(2, " only alphanumeric characters.\n", 31);
            return;
        }
        env_edit(str, sh);
    } if (nb > 3) {
        write(2, "setenv: Too many arguments.\n", 29);
    } return;
}