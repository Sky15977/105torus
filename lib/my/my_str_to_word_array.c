/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** char* in char**
*/

#include "my.h"

int is_char(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

int len_of_word(char const *str, int i)
{
    int a = 0;

    for (; str[i] != 0; i++) {
        if (is_char(str[i]) == 0)
            return a;
        a++;
    }
    return a;
}

int count(char const *str)
{
    int a = 0;

    for (int i = 0; str[i] != 0; i++)
        if (is_char(str[i]) == 1 && is_char(str[i + 1]) == 0)
            a++;
    return a;
}

char **my_str_to_word_array(char const *str)
{
    int nb_word = count(str);
    int i = 0;
    int y = 0;
    int x = 0;
    char **tab = tab = malloc(sizeof(char *) * (nb_word + 1));

    while (y < nb_word) {
        x = 0;
        tab[y] = malloc(sizeof(char) * (len_of_word(str, i) +1));
        while (str[i] != 0 && is_char(str[i]) != 0) {
            tab[y][x] = str[i];
            x++;
            i++;
        }
        tab[y][x] = '\n';
        y++;
        i++;
    }
    tab[y] = NULL;
    return tab;
}
