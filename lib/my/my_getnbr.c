/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** change a string to a int
*/

int my_getnbr(char *str)
{
    int nb = 0;
    int i = 0;
    int neg = 1;

    while (str[i] != '\0') {
        if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9') {
            neg = neg * (-1);
            i = i + 1;
        } else if (str[i] >= '0' && str[i] <= '9') {
            while (str[i] >= '0' && str[i] <= '9') {
                nb = nb * 10 + (str[i] -48);
                i = i + 1;
            }
            str[i] = '\0';
        } else
            i = i + 1;
    }
        nb = nb * neg;
        return (nb);
}
