/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** displays, one-by-one, the character of a string
*/

#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
