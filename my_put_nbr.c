/*
** EPITECH PROJECT, 2020
** myputnbe
** File description:
** myputnbr
*/

#include "runner.h"

int my_put_nbr(int nb)
{
    long long y;

    y = nb;
    if (y < 0) {
        y = -y;
        my_putchar('-');
    }
    if (y <= 9) {
        y = y + '0';
        my_putchar(y);
    } else {
        my_put_nbr(y / 10);
        y = y % 10 + '0';
        my_putchar(y);
    }
    return (0);
}
