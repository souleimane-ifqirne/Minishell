/*
** EPITECH PROJECT, 2020
** mysh
** File description:
** str to word array
*/

#include "my.h"
#include "stdlib.h"

int count_char(int i, char *str, char c)
{
    int n = 0;

    while (str[i] != c && str[i] != '\0') {
        i = i + 1;
        n = n + 1;
    }
    return (n);
}

char **malloc_line(char c, char **buffer, char *str)
{
    int i = 0;
    int n = 0;

    while (str[i]) {
        if (str[i] == c)
            n = n + 1;
        i = i + 1;
    }
    buffer = malloc(sizeof(char *) * n + 2);
    return (buffer);
}

char **my_str_to_word_array(char *str, char c)
{
    int i = 0;
    int n = 0;
    int y = 0;
    int x = 0;
    char **buffer = NULL;

    buffer = malloc_line(c, buffer, str);
    while (str[i]) {
        n = count_char(i, str, c);
        buffer[y] = malloc(sizeof(char) * n + 1);
        x = 0;
        while (str[i] != c && str[i] != '\0') {
            buffer[y][x] = str[i];
            x++;
            i++;
        } i++;
        y++;
    }
    buffer[y] = NULL;
    return (buffer);
}