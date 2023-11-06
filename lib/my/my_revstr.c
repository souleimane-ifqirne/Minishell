/*
** EPITECH PROJECT, 2019
** EPITECH PROJECT, 2019
** File description:
** reverse the characters of a string
*/

char *my_revstr(char *str)
{
    int a = 0;
    char b = 0;
    int c = 0;

    while (str[c] != '\0'){
        c = c + 1;
    }
    c = c - 1;

    while (a <= c){
        b = str[a];
        str[a] = str[c];
        str[c] = b;
        a = a + 1;
        c = c - 1;
    }
    return (str);
}
