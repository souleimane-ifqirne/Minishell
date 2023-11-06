/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** do same fonction as my_printf
*/

#include "my.h"

void my_printf_s(va_list my);

void my_printf_c(va_list my);

void my_printf_d(va_list my);

void my_printf_o(va_list my);

void my_printf_b(va_list my);

void my_printf_i(va_list my);

void my_printf_x(va_list my);

void my_printf_xx(va_list my);

void my_printf_u(va_list my);

void my_printf_ss(va_list my);

int my_printf_mod(char *str, int i)
{
    int count_mod = 0;
    int mod_1 = 0;
    int x = 0;

    while (str[i] == '%') {
        count_mod = count_mod + 1;
        i = i + 1;
    }
    mod_1 = count_mod % 2;
    count_mod = count_mod / 2;
    while (x < count_mod) {
        my_putchar('%');
        x = x + 1;
    }
    if (mod_1 == 1)
        my_putchar('%');
    return (i - 1);
}

int find_modulo(char *tabindex, char mod)
{
    int i = 0;

    while (tabindex[i] != '\0') {
        if (mod == tabindex[i])
            return (i);
        i = i + 1;
    }
    if (mod == '%')
        return (-22);
    return (-1);
}

int my_modulo(int i, char *st, void (*modulofunction[9]) (va_list), va_list my)
{
    int test = 0;
    char *tabindex = "scdobixXS";

    if (st[i] == '%' && st[i + 1] != '\0') {
        test = find_modulo(tabindex, st[i + 1]);
        if (test == -1)
            my_putchar(st[i]);
        else if (test == -22)
            i = my_printf_mod(st, i);
        else {
            (*modulofunction[test]) (my);
            i = i + 1;
        }
    }
    else
        my_putchar(st[i]);
    return (i);
}

void my_printf2(char *str, void (*modulofunction[9]) (va_list), va_list my)
{
    int i = 0;

    while (str[i] != '\0') {
        i = my_modulo(i, str, modulofunction, my);
        i = i + 1;
    }
}

void my_printf(char *str, ...)
{
    va_list my;
    void (*modulofunction[9]) (va_list);
    modulofunction[0] = &my_printf_s;
    modulofunction[1] = &my_printf_c;
    modulofunction[2] = &my_printf_d;
    modulofunction[3] = &my_printf_o;
    modulofunction[4] = &my_printf_b;
    modulofunction[5] = &my_printf_i;
    modulofunction[6] = &my_printf_x;
    modulofunction[7] = &my_printf_xx;
    modulofunction[8] = &my_printf_ss;
    va_start(my, str);
    my_printf2(str, modulofunction, my);
    va_end(my);
}
