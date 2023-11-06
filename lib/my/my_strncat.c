/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** concatenates two strings
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int cont = 0;

    while (dest[cont] != '\0')
        cont = cont + 1;
    while (src[i] != '\0' && i < nb) {
        dest[cont + i] = src[i];
        i++;
    }
    dest[cont + i] = '\0';
    return (dest);
}
