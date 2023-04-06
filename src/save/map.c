/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** map
*/

#include "../../include/prototype.h"

void write_map_name(FILE *file, char *map_name)
{
    fwrite(map_name, sizeof(char), my_strlen(map_name), file);
    fwrite("\n", sizeof(char), 1, file);
    return;
}
