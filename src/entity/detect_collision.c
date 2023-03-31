/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** detect_collision.c
*/

#include "../../include/prototype.h"

static int detect_on_sprite(entity_t *player, tile_t **tile)
{
    int i = 0;
    while (tile[i] != NULL) {
        if (player->position.x == tile[i]->position.x &&
            player->position.y == tile[i]->position.y
            && tile[i]->id != -1) {
            return 1;
        }
        i += 1;
    }
    return 0;
}

static int detect_on_layer(entity_t *player, tile_t ***layer)
{
    int i = 0;
    while (layer[i] != NULL) {
        if (detect_on_sprite(player, layer[i]) == 1)
            return 1;
        i += 1;
    }
    return 0;
}

int detect_collision(entity_t *player, map_t *map)
{
    int i = player->layer + 1;
    return detect_on_layer(player, map->layer[i]->layer);
}
