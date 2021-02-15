/*
** EPITECH PROJECT, 2020
** myputchar
** File description:
** print char
*/

#include <unistd.h>
#include "runner.h"

void my_putchar(char c)
{
    write (1 , &c, 1);
}