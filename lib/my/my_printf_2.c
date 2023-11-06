/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** first 5 modulo
*/

#include <stdarg.h>
#include "my.h"
#include <stdlib.h>

void my_printf_s(va_list my)
{
    char *str = va_arg(my, char *);

    my_putstr(str);
}

void my_printf_c(va_list my)
{
    char c = va_arg(my, int);

    my_putchar(c);
}

void my_printf_d(va_list my)
{
    int nb = va_arg(my, int);

    my_put_nbr(nb);
}

void my_printf_o(va_list my)
{
    unsigned int nb = va_arg(my, unsigned int);
    int oct = 0;
    char *octal;
    octal = malloc(sizeof(char) * 12);
    int i = 0;

    if (nb == 0)
        my_putchar('0');
    while (nb > 0) {
        oct  = nb % 8;
        nb = nb / 8;
        octal[i] = oct + '0';
        i = i + 1;
    }
    octal[i] = '\0';
    my_putstr(my_revstr(octal));
}

void my_printf_b(va_list my)
{
    unsigned int nb = va_arg(my, unsigned int);
    int bin = 0;
    char *binary;
    binary = malloc(sizeof(char) * 32);
    int i = 0;

    if (nb == 0)
        my_putchar('0');
    while (nb > 0) {
        bin = nb % 2;
        nb = nb / 2;
        binary[i] = bin + '0';
        i = i + 1;
    }
    binary[i] = '\0';
    my_putstr(my_revstr(binary));
}
