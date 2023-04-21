/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** npc.c
*/

#include "../../../include/prototype.h"

npc_t *create_npc(char *name, sfVector2i position)
{
    npc_t *npc = malloc(sizeof(npc_t));
    npc->file = my_strdup(name);
    npc->position = position;
    return npc;
}

int destroy_npc(npc_t *npc)
{
    if (npc->file != NULL)
        free(npc->file);
    free(npc);
    return 0;
}
