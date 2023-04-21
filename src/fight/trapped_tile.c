/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** trapped_tile.c
*/

#include "../../include/prototype.h"

static int corrupt_layer(app_t *app, tile_t *tile)
{
    int change = 0;
    if (tile->state != SOLID)
        return 0;
    if (random_randint(0, 100000) != 50000)
        return 0;
    sfTexture *texture = get_texture(app->maps->map_object, 58);
    sfSprite_setTexture(tile->tile, texture, sfFalse);
    return 0;
}

int corrupt_map(app_t *app)
{
    int i = app->player->layer - 1;
    sfVector2i position = {0, 0};
    layer_t *layer = app->maps->selected_map->layer[i];
    while (layer->layer[position.y] != NULL) {
        position.x = 0;
        while (layer->layer[position.y][position.x] != NULL) {
            trapped_tile_color(app, layer->layer[position.y][position.x]);
            position.x += 1;
        }
        position.y += 1;
    }
    return 0;
}
