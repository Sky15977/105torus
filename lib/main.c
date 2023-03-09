/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "torus.h"

int main(int ac, char **av)
{
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0))
        manage_usage();
    if (ac != 8)
        manage_error();
    if (check_arg(av) == 1)
        manage_error();    
    torus_math(av);
    return 0;
}
