/*
** EPITECH PROJECT, 2023
** error.c
** File description:
** error
*/

#include "torus.h"

int check_arg(char **av)
{
    for (int i = 1; i < 8; i++) {
        if(my_str_isnum(av[i]) == 0)
            return 1;
    }
    return 0;
}

void manage_error(void)
{
    my_putstr("./105torus: bad arguments\n");
    my_putstr("retry with -h\n");
    exit(84);
}

void manage_usage(void)
{
    my_putstr("USAGE\n   ./105torus opt a0 a1 a2 a3 a4 n\n\nDESCRIPTION\n");
    my_putstr("   opt\t    method option:\n\t\t1 for the bisection method");
    my_putstr("\n\t\t2 for Newton's method\n\t\t3 for the secant method\n");
    my_putstr("   a[0-4]   coefficients of the equation\n   n\t    ");
    my_putstr("precision (the application of the polynomial to the solution");
    my_putstr(" should\n\t    be smaller than 10^-n\n");
    exit(0);
}
