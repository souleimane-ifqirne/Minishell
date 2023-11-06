/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenates two strings
*/

#include "stdlib.h"

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int i2 = 0;
    char *tmp = dest;

    dest = malloc(sizeof(char) * my_strlen(tmp) + my_strlen(src));
    for (int i = 0; tmp[i]; i++) dest[i] = tmp[i];
    while (dest[i2] != '\0')
        i2 = i2 + 1;
    while (src[i] != '\0') {
        dest[i2 + i] = src[i];
        i = i + 1;
    }
    dest[i2 + i] = '\0';
    return (dest);
}
