/*
** EPITECH PROJECT, 2023
** torus.c
** File description:
** 105torus
*/

#include "torus.h"

double func(torus_t *torus, double x)
{
    x = (torus->e * pow(x, 4)) + (torus->d * pow(x, 3)) +
        (torus->c * pow(x, 2)) + (torus->b * x) + torus->a;
    return x;
}

double func_prime(torus_t *torus, double x)
{
    x = ((4 * (torus->e * pow(x, 3))) + (3 * (torus->d * pow(x, 2))) +
         (2 * (torus->c * x)) + torus->b);
    return x;
}

void bisection(torus_t *torus)
{
    double x1 = 0;
    double x2 = 1;
    double xm = (x1 + x2) / 2;
    double epsi = pow(10, (-1 * torus->n));
    double f_x1 = func(torus, x1);
    double f_x2 = func(torus, x2);
    double f_xm = func(torus, xm);

    if (f_x1 == 0) {
//        f_x1 < epsi
        exit(0);
    }
    if (f_x2 == 0) {
//        f_x2 < epsi
        exit(0);
    }
    if ((f_x1 * f_x2) > 0) {
        exit(84);
        }
/*    if (f_xm < epsi) {
        exit(0);
    }*/
    for (int i = 1; i <= 50; i++) {
        if (i <= torus->n)
            printf("x = %.*f\n", i, xm);
        else
            printf("x = %.*f\n", torus->n, xm);
        f_x1 = func(torus, x1);
        f_xm = func(torus, xm);
        if ((f_x1 * f_xm) < 0)
            x2 = xm;
        else
            x1 = xm;
        xm = (x1 + x2) / 2;
        if (f_xm < epsi && f_xm > -epsi) {
            exit(0);
        }
    }
    printf("error: max count\n");
    exit(84);
}

void newton(torus_t *torus)
{
    double x0 = 0.5;
    double xm = x0;
    double f_x0;
    double f_xm;
    double epsi = pow(10, (-1 * torus->n));

/*    if (func(torus, x0) < epsi) {
        exit(0);
    }*/
    for (int i = 1; i <= 50; i++) {
        if (i == 1)
            printf("x = %.*f\n", i, xm);
        else
            printf("x = %.*f\n", torus->n, xm);
        f_x0 = func(torus, x0);
        f_xm = func_prime(torus, x0);
        if (f_xm == 0) {
            printf("error: divisions by zero");
            exit(84);
        }
        xm = x0 - (f_x0 / f_xm);
        x0 = xm;
        if (f_x0 < epsi && f_x0 > -epsi) {
            exit(0);
        }
    }
    printf("error: max count\n");
    exit(84);
}

void secant(torus_t *torus)
{
    double x0 = 0;
    double x1 = 1;
    double xm = 0;
    double f_x0;
    double f_x1;
    double f_xm;
    double epsi = pow(10, (-1 * torus->n));

/*    if (func(torus, x0) < epsi) {
        exit(0);
        }*/
/*    if (func(torus, x1) < epsi) {
        exit(0);
        }*/
    for (int i = 1; i <= 50; i++) {
        f_x0 = func(torus, x0);
        f_x1 = func(torus, x1);
        f_xm = func(torus, xm);
        if (f_x1 - f_x0 == 0) {
            printf("error: divisions by zero");
            exit(84);
        }
        xm = x1 - (f_x1 * (x1 - x0) / (f_x1 - f_x0));
        if (f_xm < epsi && f_xm > -epsi) {
            exit(0);
        }
        if (xm == 0.5)
            printf("x = %.*f\n", i, xm);
        else
            printf("x = %.*f\n", torus->n, xm);
        x0 = x1;
        x1 = xm;
        }
    printf("error: max count\n");
    exit(84);
}

int torus_math(char **av)
{
    torus_t *torus = malloc(sizeof(torus_t));

    init_struct(torus, av);
    if (torus->opt < 1 || torus->opt > 3 || torus->n < 1)
        manage_error();
    if (torus->opt == 1)
        bisection(torus);
    if (torus->opt == 2)
        newton(torus);
    if (torus->opt == 3)
        secant(torus);
    return 0;
}
