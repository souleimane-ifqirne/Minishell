/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** the second 5 flag
*/

#include <stdarg.h>
#include "my.h"
#include <stdlib.h>

char hexaa_test(int h)
{
    char *tab_hexa = "ABCDEF";
    h = h - 10;
    return (tab_hexa[h]);
}

void my_printf_xx(va_list my)
{
    unsigned int nb = va_arg(my, unsigned int);
    int h = 0;
    char *hexa;
    hexa = malloc(sizeof(char) * 9);
    int i = 0;

    if (nb == 0)
        my_putchar('0');
    while (nb >0) {
        h = nb % 16;
        nb = nb / 16;
        if (h >= 10)
            hexa[i] = hexaa_test(h);
        else
            hexa[i] = h + '0';
        i = i + 1;
    }
    hexa[i] = '\0';
    my_putstr(my_revstr(hexa));
}

void my_printf_i(va_list my)
{
    int nb = va_arg(my, int);

    my_put_nbr(nb);
}

char hexa_test(int h)
{
    char *tab_hexa = "abcdef";
    h = h - 10;
    return (tab_hexa[h]);
}

void my_printf_x(va_list my)
{
    unsigned int nb = va_arg(my, unsigned int);
    int h = 0;
    char *hexa;
    hexa = malloc(sizeof(char) * 9);
    int i = 0;

    if (nb == 0)
        my_putchar('0');
    while (nb > 0) {
        h = nb % 16;
        nb = nb / 16;
        if (h >= 10)
            hexa[i] = hexa_test(h);
        else
            hexa[i] = h + '0';
        i = i + 1;
    }
    hexa[i] = '\0';
    my_putstr(my_revstr(hexa));
}
