/*
** EPITECH PROJECT, 2022
** list_v1.c
** File description:
** list_chainé
*/

#include "my.h"

list_t *list_create(void)
{
    list_t *list = malloc(sizeof(list_t));

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}
