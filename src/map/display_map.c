/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** display_map.c
*/

#include "../../include/prototype.h"

static int display_layer(sfRenderWindow *window, map_t *map, int x, entity_t *player)
{
    int y = 0;
    int z = 0;
    layer_t *layer = map->layer[0];
    while (layer->layer[x][y] != NULL) {
        z = 0;
        if (x == player->position.x && y == player->position.y)
            sfRenderWindow_drawSprite(window, player->sprite->sprite, NULL);
        while (map->layer[z] != NULL) {
            sfRenderWindow_drawSprite(window, map->layer[1]->layer[x][y]->tile, NULL);
            z += 1;
        }
        y += 1;
    }
    return 0;
}

int display_map(sfRenderWindow *window, map_t *map, entity_t *player)
{
    int i = 0;
    layer_t *layer = map->layer[0];
    int x = 0;
    while (layer->layer[x] != NULL) {
        display_layer(window, map, x, player);
        x += 1;
    }

    return 0;
}

