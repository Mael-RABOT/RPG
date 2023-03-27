/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-mathieu.borel
** File description:
** array_manipulation
*/

#include "../../include/prototype.h"

int print_array(char **array)
{
    int i = 0;
    while (array[i] != NULL) {
        my_printf("%s\n", array[i]);
        i += 1;
    }
    return 0;
}

int free_array(char **array)
{
    int i = 0;
    while (array[i] != NULL) {
        free(array[i]);
        i += 1;
    }
    free(array);
    return 0;
}

int len_array(char **array)
{
    int i = 0;
    while (array[i] != NULL) {
        i += 1;
    }
    return i;
}
