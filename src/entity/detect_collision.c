/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** detect_collision.c
*/

#include "../../include/prototype.h"

static int detect_on_sprite(app_t *app, entity_t *entity, int i)
{
    int j = 0;
    while (app->maps->selected_map->layer[entity->layer]->layer[i][j] != NULL) {
tile_t *tile = app->maps->selected_map->layer[entity->layer]->layer[i][j++];
        if (entity->position.x == tile->position.x &&
            entity->position.y == tile->position.y
            && tile->state == STAIRS) {
            entity->layer += 1;
            return 1;
        }
        if (entity->position.x == tile->position.x &&
            entity->position.y == tile->position.y &&
            tile->state == TELEPORTER) {
            change_map_by_name(app, app->maps, entity, tile->teleport->name);
            return 0;
        }
        if (entity->position.x == tile->position.x &&
            entity->position.y == tile->position.y
            && tile->state == SOLID)
            return 1;
    } return 0;
}

int detect_collision(app_t *app, entity_t *entity)
{
    int i = 0;
    map_t *map = app->maps->selected_map;
    while (map->layer[entity->layer]->layer[i] != NULL) {
        if (detect_on_sprite(app, entity, i) == 1)
            return 1;
        i += 1;
    }
    return 0;
}
