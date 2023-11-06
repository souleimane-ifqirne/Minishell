/*
** EPITECH PROJECT, 2020
** mysh
** File description:
** unsetenv
*/

#include "list.h"

void delete_env(char *str, shell_t *sh)
{
    char **temp_env = sh->env;
    int line = 0;
    sh->line -= 1;
    sh->env = malloc(sizeof(char *) * sh->line + 1);
    for (; temp_env[line]; line++) {
        if (!my_strncmp(my_strcat(str, "="),
        temp_env[line], my_strlen(str) + 1)) break;
    }
    for (int i = 0, j = 0; temp_env[i]; i++) {
        if (i != line) {
            sh->env[j] = temp_env[i];
            j++;
        }
    }
    sh->env[sh->line] = NULL;
    return;
}

void check_env(char **str, shell_t *sh)
{
    char **temp_env = sh->env;

    for (int i = 1; str[i]; i++) {
        if (my_getenv(str[i], sh->env))
            delete_env(str[i], sh);
    }
    return;
}

void my_unsetenv(shell_t *sh, char *buffer)
{
    char **str = NULL;
    int nb = 0;

    buffer = del_backslash(buffer);
    str = my_str_to_word_array(buffer, ' ');
    for (; str[nb]; nb++);
    if (nb == 1) write(2, "unsetenv: Too few arguments.\n", 30);
    else
        check_env(str, sh);
    return;
}