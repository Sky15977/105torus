/*
** EPITECH PROJECT, 2022
** list_v3.c
** File description:
** v3
*/

#include "my.h"

void *list_get_node(list_t *list, unsigned int index)
{
    list_node_t *node;
    unsigned int current = 0;

    if (list == NULL) {
        printf("list_get_node: list == NULL");
        return NULL;
    }
    node = list->head;
    if (node == NULL)
        return NULL;
    while (node != NULL && current < index) {
        current++;
        node = node->next;
    }
    return node;
}

void *list_get(list_t *list, unsigned int index)
{
    list_node_t *node = list_get_node(list, index);

    if (node != NULL)
        return node->value;
    return NULL;
}
