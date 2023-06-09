/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_teleport.c
*/

#include "../../../include/prototype.h"

teleport_t *create_teleport(char *map_name)
{
    teleport_t *teleport = malloc(sizeof(teleport_t));
    teleport->name = my_strdup(map_name);
    return teleport;
}

int destroy_teleport(teleport_t *teleport)
{
    free(teleport->name);
    free(teleport);
    return 0;
}
