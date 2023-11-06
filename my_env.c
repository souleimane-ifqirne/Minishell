/*
** EPITECH PROJECT, 2020
** minishell 2
** File description:
** my_env
*/

#include "list.h"

char *last_spaces(shell_t *sh, char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
    return (str);
}

char *change_spaces(shell_t *sh, char *str)
{
    int i = 0;

    sh->spaces = 0;
    for (; str[i] == ' ' || str[i] == '\t'; i++) {
        str[i] = 27;
        sh->spaces += 1;
    } for (; str[i] != '\n' && str[i]; i++) {
        if ((str[i] == ' ' || str[i] == '\t')
        && (str[i + 1] == ' ' || str[i + 1] == '\t')) {
            str[i] = 27;
            sh->spaces += 1;
        }
        if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] == '\n') {
            str[i] = 27;
            sh->spaces += 1;
        }
    }
    return (last_spaces(sh, str));
}

char *del_spaces(shell_t *sh, char *buffer)
{
    char *tmp = buffer;
    char *new_buffer;

    tmp = change_spaces(sh, tmp);
    new_buffer = malloc(sizeof(char) * my_strlen(buffer) - sh->spaces + 1);

    for (int i = 0, j = 0; tmp[i]; i++) {
        if (tmp[i] != 27) {
            new_buffer[j] = tmp[i];
            j++;
        }
    }
    return (new_buffer);
}

void my_env(shell_t *sh)
{
    int i = 0;

    while (sh->env && sh->env[i]) {
        my_printf("%s\n", sh->env[i]);
        i++;
    }
}