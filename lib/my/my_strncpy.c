/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copies n characters or the whole string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' || i != n) {
        dest[i] = src[i];
        i = i + 1;
    }
    if (n > i)
        dest[i] = '\0';
    return (dest);
}
