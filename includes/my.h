/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** lib
*/

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef MY_SOKOBAN_H
    #define MY_SOKOBAN_H

typedef struct list_node_s {
    void *value;
    struct list_node_s *next;
    struct list_node_s *prev;
} list_node_t;

typedef struct list_s {
    list_node_t *head;
    list_node_t *tail;
    unsigned int size;
} list_t;

//my_put.c
    void my_putchar(char c);
    int my_putstr(char const *str);
    long long int my_put_nbr(long long int nb);
    long long int my_putnbr_base(long long int nbr, char const *base);

//my_getnbr.c
    int my_getnbr(char const *str);

//my_str.c
    int my_strlen(char const *str);
    char *my_strcat(char *dest, char const *src);

//my_str_is.c
    int my_str_isalpha(char const *str);
    int my_str_islower(char const *str);
    int my_str_isnum(char const *str);
    int my_str_isprintable(char const *str);
    int my_str_isupper(char const *str);

//my_str_to_word_array.c
    int is_char(char c);
    int len_of_word(char const *str, int i);
    int count(char const *str);
    char **my_str_to_word_array(char const *str);

//list_create.c
    list_t *list_create(void);
    void *list_pop(list_t *list);

//list_add.c
    unsigned int list_add(list_t *list, void *value);

//list_get.c
    void *list_get_node(list_t *list, unsigned int index);
    void *list_get(list_t *list, unsigned int index);

//list_remove.c
    void list_remove(list_t *list, unsigned int index);

#endif
