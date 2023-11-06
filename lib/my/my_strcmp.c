/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** string
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (1);
    while (s1[i]) {
        if (s1[i] != s2[i])
            return (1);
        i = i + 1;
    }
    return (0);
}
