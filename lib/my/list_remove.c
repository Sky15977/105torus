/*
** EPITECH PROJECT, 2022
** list_v4.c
** File description:
** list_v4.c
*/

#include "my.h"

static void list_remove_node(list_t *list, list_node_t *node)
{
    list->size--;
    if (list->head == node)
        list->head = node->next;
    if (list->tail == node)
        list->tail = node->prev;
    if (node->prev != NULL)
        node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    node->next = NULL;
    node->prev = NULL;
    free(node);
}

void list_remove(list_t *list, unsigned int index)
{
    list_node_t *node;

    if (list == NULL) {
        printf("list_remove: list == NULL");
        return;
    }
    node = list_get_node(list, index);
    if (node != NULL)
        list_remove_node(list, node);
}
