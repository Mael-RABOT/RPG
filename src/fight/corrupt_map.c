/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** trapped_tile.c
*/

#include "../../include/prototype.h"

static int corrupt_map_tile(app_t *app, tile_t *tile)
{
    if (tile->state != SOLID)
        return 0;
    if (random_randint(0, 100000) != 0)
        return 0;
    sfTexture *texture = get_texture(app->maps->map_object, 58);
    sfSprite_setTexture(tile->tile, texture, sfFalse);
    return 0;
}

static int corrupt_map_layer(app_t *app, layer_t *layer)
{
    sfVector2i position = {0, 0};
    while (layer->layer[position.y] != NULL) {
        position.x = 0;
        while (layer->layer[position.y][position.x] != NULL) {
            corrupt_map_tile(app, layer->layer[position.y][position.x]);
            position.x += 1;
        }
        position.y += 1;
    }
    return 0;
}

int corrupt_map(app_t *app)
{
    map_t *map = app->maps->selected_map;
    int i = 0;
    while (map->layer[i] != NULL) {
        corrupt_map_layer(app, map->layer[i]);
        i += 1;
    }
    return 0;
}
