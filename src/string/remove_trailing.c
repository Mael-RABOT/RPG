/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** remove_trailing.c
*/

#include "../../include/prototype.h"

void remove_trailing_newline_or_space(char *line)
{
    line[my_strlen(line) - 1] = (line[my_strlen(line) - 1] == '\n'
    || line[my_strlen(line) - 1] == ' ')
        ? '\0' : line[my_strlen(line) - 1];
}
