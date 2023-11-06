/*
** EPITECH PROJECT, 2020
** shell2
** File description:
** getenv
*/

#include "list.h"

char *my_getenv(char *str, char **env)
{
    int i = 0;
    int j = 0;
    char *str2 = NULL;

    for (int i = 0; env[i] && env; i++) {
        if (!my_strncmp(str, env[i], my_strlen(str))) {
            str2 = malloc(sizeof(char) * my_strlen(env[i]) - my_strlen(str));
            for (int x = my_strlen(str); env[i][x]; j++, x++)
                str2[j] = env[i][x];
            str2[j] = '\0';
            return (str2);
        }
    }
    return (str2);
}