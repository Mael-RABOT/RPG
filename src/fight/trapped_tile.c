/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** trapped_tile.c
*/

#include "../../include/prototype.h"

static int trapped_tile_color(app_t *app, tile_t *tile)
{
    int change = 0;
        sfColor color = sfSprite_getColor(tile->tile);
        color.r = 100;
        color.g = 0;
        color.b = 0;
        color.a = 100;
        sfSprite_setColor(tile->tile, color);
        printf("%d - %d - %d - %d\n", color.r, color.g, color.b, color.a);
    return 0;
}

int trapped_tile(app_t *app)
{
    int i = app->player->layer - 1;
    sfVector2i position = {0, 0};
    layer_t *layer = app->maps->selected_map->layer[i];
    while (layer->layer[position.y] != NULL) {
        while (layer->layer[position.y][position.x] != NULL) {
            trapped_tile_color(app, layer->layer[position.y][position.y]);
            position.x += 1;
        }
        position.y += 1;
    }
    return 0;
}
