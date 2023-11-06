/*
** EPITECH PROJECT, 2020
** minishell1 project
** File description:
** command interpret
*/

#include "./list.h"

char *del_backslash(char *buffer)
{
    char *tmp = malloc(sizeof(char) * my_strlen(buffer));

    for (int i = 0, j = 0; buffer[i]; i++) {
        if (buffer[i] != '\n') {
            tmp[j] = buffer[i];
            j++;
        }
    }
    return (tmp);
}

char *read_prompt(shell_t *sh)
{
    char *buffer = NULL;
    size_t lenght = 2;
    size_t size = 0;

    my_printf("%s$> ", getcwd(NULL, 500));
    size = getline(&buffer, &lenght, stdin);
    if (size == -1) {
        my_putstr("exit\n");
        exit(0);
    }
    return (buffer);
}

void command_list(shell_t *sh, char *buffer)
{
    if (!my_strncmp("env", buffer, 3)
    && (buffer[3] == ' ' || buffer[3] == '\n')) {
        my_env(sh);
        sh->no = 1;
    } if (!my_strncmp("exit", buffer, 4)
    && (buffer[4] == ' ' || buffer[4] == '\n')) {
        my_exit(sh, buffer);
        sh->no = 1;
    } if (!my_strncmp("setenv", buffer, 6)
    && (buffer[6] == ' ' || buffer[6] == '\n')) {
        my_setenv(sh, buffer);
        sh->no = 1;
    } if (!my_strncmp("unsetenv", buffer, 8)
    && (buffer[8] == ' ' || buffer[8] == '\n')) {
        my_unsetenv(sh, buffer);
        sh->no = 1;
    } if (!my_strncmp("cd", buffer, 2)
    && (buffer[2] == ' ' || buffer[2] == '\n'))
        my_cd(sh, buffer);
    if (sh->no == 2) my_path(sh, buffer);
}

int main(int ac, char **av, char **env)
{
    struct shell *sh = malloc(sizeof(shell_t));
    char *buffer = NULL;

    if (ac > 1)
        return (0);
    sh->env = env;
    for (sh->line = 0; sh->env[sh->line]; sh->line++);
    while (1) {
        sh->no = 2;
        buffer = read_prompt(sh);
        buffer = del_spaces(sh, buffer);
        command_list(sh, buffer);
    }
    return (0);
}
