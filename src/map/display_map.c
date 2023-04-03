/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** display_map.c
*/

#include "../../include/prototype.h"

static sfVector2i get_layer_dimension(layer_t *layer)
{
    sfVector2i position = {0, 0};
    while (layer->layer[position.y] != NULL)
        position.y += 1;
    while (layer->layer[0][position.x] != NULL)
        position.x += 1;
    return position;
}

static int display_layer(sfRenderWindow *window, layer_t *layer, entity_t *player)
{
    int i = 0;
    while (layer->layer[i] != NULL) {
        int j = 0;
        while (layer->layer[i][j] != NULL) {
            if (i == player->position.y && j == player->position.x)
                sfRenderWindow_drawSprite(window, player->sprite->sprite, NULL);
            else
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
        display_layer(window, map->layer[i], player);
        i += 1;
    }
    return 0;
}
