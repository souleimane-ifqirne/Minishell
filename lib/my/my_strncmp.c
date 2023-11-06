/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** string
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (n > 0) {
        if (s1[i] != s2[i])
            return (1);
        n = n - 1;
        i = i + 1;
    }
    return (0);
}
