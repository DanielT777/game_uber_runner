/*
** EPITECH PROJECT, 2020
** my_printstr
** File description:
** print onebyone character
*/

#include "runner.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
