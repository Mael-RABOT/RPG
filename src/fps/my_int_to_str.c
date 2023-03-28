/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-yohann.mangenot
** File description:
** my_int_to_str
*/

#include "../../include/prototype.h"

int rev(int nb)
{
    int a = 0;
    int b = 0;

    while (nb > 0) {
        a = nb % 10;
        nb = nb / 10;
        b *= 10;
        b += a;
    }
    return (b);
}

int nbsize(int nb)
{
    int i = 0;

    for (; nb > 0; i++) {
        nb = nb / 10;
    }
    return (i);
}

char *my_int_to_str(int nb)
{
    char *result = malloc(nbsize(nb));
    int reverse_nb = rev(nb);
    int size = nbsize(nb);

    result[0] = '\0';
    if (nb == 0)
        return ("0");
    for (int i = 0; i < size; i++) {
        my_strappend(result, (reverse_nb % 10) + 48);
        reverse_nb = reverse_nb / 10;
    }
    return (result);
}
