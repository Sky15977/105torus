/*
** EPITECH PROJECT, 2022
** torus.h
** File description:
** dico func
*/

#include <stdio.h>

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#ifndef TORUS_H
    #define TORUS_H

    typedef struct torus_s {
        int opt;
        double a;
        double b;
        double c;
        double d;
        double e;
        int n;
    } torus_t;

//error.c
    int check_arg(char **av);
    void manage_error(void);
    void manage_usage(void);

//init.c
    void init_struct(torus_t *torus, char **av);

//torus.c
    double func(torus_t *torus, double x);
    double func_prime(torus_t *torus, double x);
    void bisection(torus_t *torus);
    void newton(torus_t *torus);
    void secant(torus_t *torus);
    int torus_math(char **av);

#endif
