/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-mathieu.borel
** File description:
** my_stricat
*/

#include "my_string.h"
#include <stdarg.h>
#include <stdio.h>

char *my_stricat(int len, char *dest, ...)
{
    va_list list;
    va_start(list, dest);
    dest[0] = '\0';
    int i = 0;
    while (i < len) {
        my_strcat(dest, va_arg(list, char *));
        i += 1;
    }
    va_end(list);
    return dest;
}
