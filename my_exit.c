/*
** EPITECH PROJECT, 2020
** shell2
** File description:
** my_exit
*/

#include "list.h"

int exit_error(char **str)
{
    int i = 0;
    int c = 0;

    if (str[1] == NULL)
        return (0);
    while (str[1][i]) {
        if (str[1][i] < '0' || str[1][i] > '9')
            c = 1;
        i = i + 1;
    } if (c == 1 && str[1][0] >= '0' && str[1][0] <= '9') {
        write(2, "exit: Badly formed number.\n", 27);
        return (1);
    } if (c == 1 && str[1][0] < '0' || str[1][0] > '9') {
        write(2, "exit: Expression Syntax.\n", 26);
        return (1);
    } if (str[2] != NULL) {
        write(2, "exit: Expression Syntax.\n", 26);
        return (1);
    } return (0);
}

int exit_check(char **str)
{
    if (str[1] == NULL) {
        my_printf("exit\n");
        exit(0);
    } else {
        my_printf("exit\n");
        exit(my_getnbr(str[1]));
    } return (0);
}

void my_exit(shell_t *sh, char *buffer)
{
    char **str = NULL;

    buffer = del_backslash(buffer);
    str = my_str_to_word_array(buffer, ' ');
    if (exit_error(str) == 1)
        return;
    else
        exit_check(str);
    return;
}