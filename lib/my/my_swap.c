/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swap the content of two integer
*/

int my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
    return (0);
}
