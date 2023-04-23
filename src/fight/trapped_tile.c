/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** trapped_tile.c
*/

#include "../../include/prototype.h"

static int trapped_layer(app_t *app, tile_t *tile)
{
    if (tile->state != SOLID)
        return 0;
    if (random_randint(0, 3) != 0)
        return 0;
    sfColor color = sfSprite_getColor(tile->tile);
    color.r = 255;
    color.b = 0;
    color.g = 0;
    tile->is_trapped = 1;
    sfSprite_setColor(tile->tile, color);
    return 0;
}

int trapped_tile(app_t *app)
{
    int i = app->player->layer - 1;
    sfVector2i position = {0, 0};
    layer_t *layer = app->maps->selected_map->layer[i];
    while (layer->layer[position.y] != NULL) {
        position.x = 0;
        while (layer->layer[position.y][position.x] != NULL) {
            trapped_layer(app, layer->layer[position.y][position.x]);
            position.x += 1;
        }
        position.y += 1;
    }
    return 0;
}
