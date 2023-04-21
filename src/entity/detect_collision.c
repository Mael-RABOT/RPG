/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** detect_collision.c
*/

#include "../../include/prototype.h"

static int detect_block(app_t *app, entity_t *entity, tile_t *tile)
{
    switch (tile->state) {
        case SOLID:
            return 1;
        case TELEPORTER:
            change_map_by_name(app, app->maps, entity, tile->sb.teleport->name);
            break;
        case STAIRS_UP:
            entity->layer += 1; return 2;
        case STAIRS_DOWN:
            entity->layer -= 1; return 3;
        default:
            return 0;
    }
    return 0;
}

int detect_collision(app_t *app, entity_t *entity)
{
    int x = entity->position.x;
    int y = entity->position.y;
    map_t *map = app->maps->selected_map;
    layer_t *layer = map->layer[entity->layer];
    if (x < 0 || y < 0 || x > layer->size.x - 1 || y > layer->size.y - 1)
        return 1;
    tile_t *tile = map->layer[entity->layer]->layer[y][x];
    int status = detect_block(app, entity, tile);
    if (status != 0)
        return status;
    tile_t *ptile = map->layer[entity->layer - 1]->layer[y + 1][x + 1];
    if (ptile->state != SOLID)
        return 1;
    return 0;
}
