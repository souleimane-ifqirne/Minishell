/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** Positive or Negative integer
*/

#include "my.h"

int my_isneg(int n)
{
    char N = 78;
    char P = 80;

    if (n < 0)
    {
        my_putchar(N);
    }
    else
    {
        my_putchar(P);
    }
    return (0);
}