/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** detect_collision.c
*/

#include "../../include/prototype.h"

static int detect_on_sprite(app_t *app, entity_t *player, maps_t *maps,
    tile_t **tile)
{
    int i = 0;
    while (tile[i] != NULL) {
        if (player->position.x == tile[i]->position.x &&
            player->position.y == tile[i]->position.y &&
            tile[i]->state == TELEPORTER) {
            change_map_by_name(maps, player, tile[i]->teleport->name);
            return 0;
        }
        if (player->position.x == tile[i]->position.x &&
            player->position.y == tile[i]->position.y
            && tile[i]->state == SOLID) {
            return 1;
        }
        i += 1;
    }
    return 0;
}

static int detect_on_layer(app_t *app, entity_t *player, maps_t *maps,
    tile_t ***layer)
{
    int i = 0;
    while (layer[i] != NULL) {
        if (detect_on_sprite(app, player, maps, layer[i]) == 1)
            return 1;
        i += 1;
    }
    return 0;
}

int detect_collision(app_t *app, entity_t *player, maps_t *maps)
{
    int i = player->layer + 1;
    return detect_on_layer(app, player, maps,
        maps->selected_map->layer[i]->layer);
}
