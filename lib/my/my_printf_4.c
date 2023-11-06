/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** the third 5 flags
*/

#include "my.h"

void my_printf_o(va_list my);

void my_printf_ss(va_list my)
{
    char *str = va_arg(my, char *);

    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 32 || str[i] >= 127) {
            my_putchar('\\');
            my_printf_o(my);
        }
            my_putchar(str[i]);
        i = i + 1;
}
}
