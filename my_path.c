/*
** EPITECH PROJECT, 2020
** sh
** File description:
** PATH exec
*/

#include "list.h"

void path_exec(shell_t *sh, char **str, int test, char *command)
{
    pid_t pid = 0;

    if (test == 1) {
        if (fork() == 0)
            execve(command, str, sh->env);
        else
            wait(&pid);
    } else {
        write(2, str[0], my_strlen(str[0]));
        write(2, ": Command not found.\n", 22);
        return;
    }
    return;
}

void my_path(shell_t *sh, char *buffer)
{
    char **str = NULL;
    char **tmp_path = NULL;
    char *command = NULL;
    int test = 0;
    char *rien = NULL;

    buffer = del_backslash(buffer);
    str = my_str_to_word_array(buffer, ' ');
    if (!my_getenv("PATH=", sh->env)) return;
    rien = my_getenv("PATH=", sh->env);
    tmp_path = my_str_to_word_array(rien, ':');
    for (int i = 0; tmp_path[i]; i++) {
        command = my_strcat(tmp_path[i], my_strcat("/", str[0]));
        if (!access(command, X_OK)) {
            test = 1;
            break;
        }
    }
    path_exec(sh, str, test, command);
    return;
}