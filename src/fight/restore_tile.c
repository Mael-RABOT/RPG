/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** restore_tile.c
*/

#include "../../include/prototype.h"

static int restore_tile_layer(layer_t *layer)
{
    sfVector2i position = {0, 0};
    while (layer->layer[position.y] != NULL) {
        position.x = 0;
        while (layer->layer[position.y][position.x] != NULL) {
            tile_t *tile = layer->layer[position.y][position.x];
            tile->is_trapped = 0;
            sfColor color = {255, 255, 255, 255};
            sfSprite_setColor(tile->tile, color);
            position.x += 1;
        }
        position.y += 1;
    }
    return 0;
}

int restore_tile(app_t *app)
{
    map_t *map = app->maps->selected_map;
    int i = 0;
    while (map->layer[i] != NULL) {
        restore_tile_layer(map->layer[i]);
        i += 1;
    }
    return 0;
}
