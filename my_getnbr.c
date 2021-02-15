/*
** EPITECH PROJECT, 2020
** my get nbr
** File description:
** get nbr
*/

int my_getnbr(char const *str)
{

    int i = 0;
    int nb1 = 0;
    int minus = 1;

    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            nb1 = nb1 * 10 + (str[i] - 48);
        } else if (str[i] == 45) {
            minus = minus*-1;
            } else {
                nb1 = nb1 * minus;
            }
        i++;
    }
    return (nb1*minus);
}
