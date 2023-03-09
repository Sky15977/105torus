/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** init
*/

#include "torus.h"

void init_struct(torus_t *torus, char **av)
{
    torus->opt = my_getnbr(av[1]);
    torus->a = my_getnbr(av[2]);
    torus->b = my_getnbr(av[3]);
    torus->c = my_getnbr(av[4]);
    torus->d = my_getnbr(av[5]);
    torus->e = my_getnbr(av[6]);
    torus->n = my_getnbr(av[7]);
}
