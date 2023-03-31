/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** display_map.c
*/

#include "../../include/prototype.h"

static int display_layer(sfRenderWindow *window, layer_t *layer)
{
    int i = 0;
    while (layer->layer[i] != NULL) {
        int j = 0;
        while (layer->layer[i][j] != NULL) {
            sfRenderWindow_drawSprite(window, layer->layer[i][j]->tile, NULL);
            j += 1;
        }
        i += 1;
    }
    return 0;
}

int display_map(sfRenderWindow *window, map_t *map, entity_t *player)
{
    int i = 0;
    while (map->layer[i] != NULL) {
        display_layer(window, map->layer[i]);
        i += 1;
    }
    sfRenderWindow_drawSprite(window, player->sprite->sprite, NULL);
    return 0;
}
