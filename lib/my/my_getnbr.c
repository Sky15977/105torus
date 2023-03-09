/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** this will return a number and as input get string
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int	nb = 0;
    int	compt = 1;
    int	i = 0;

    while (str[i] == 43 || str[i] == 45) {
        if (str[i] == 45)
            compt *= -1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            nb = nb * 10;
            nb = nb + str[i] - 48;
            i++;
        } else {
            return (nb * compt);
        }
    }
    return (nb * compt);
}
