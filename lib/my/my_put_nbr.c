/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** Insert an number display the number.
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb <= 9 && nb >= 0) {
        my_putchar(nb + '0');
    }
    else if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    }
    else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return (nb);
}
