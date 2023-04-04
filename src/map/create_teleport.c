/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_teleport.c
*/

#include "../../include/prototype.h"

teleport_t *create_teleport(int id)
{
    teleport_t *teleport = malloc(sizeof(teleport_t));
    teleport->name = NULL;
    return teleport;
}

int destroy_teleport(teleport_t *teleport)
{
    free(teleport->name);
    free(teleport);
    return 0;
}
