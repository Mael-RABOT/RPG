/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** display_map.c
*/

#include "../../include/prototype.h"

static int display_layer_line(sfRenderWindow *window, entity_t *player,
    tile_t *tile, sfVector3i position)
{
    if (position.y == player->position.y && position.x == player->position.x
        && player->layer == position.z)
        sfRenderWindow_drawSprite(window, player->sprite->sprite, NULL);
    else
        sfRenderWindow_drawSprite(window, tile->tile, NULL);
    return 0;
}

static int display_layer(sfRenderWindow *window, map_t *map, entity_t *player,
    sfVector3i position)
{
    position.y = 0;
    while (map->layer[position.z]->layer[position.y] != NULL) {
        position.x = 0;
        while (map->layer[position.z]->layer[position.y][position.x] != NULL) {
            display_layer_line(window, player, map->layer[position.z]->
                layer[position.y][position.x], position);
            position.x += 1;
        }
        position.y += 1;
    }
    return 0;
}

int display_map(sfRenderWindow *window, map_t *map, entity_t *player)
{
    sfVector3i position = {0, 0, 0};
    while (map->layer[position.z] != NULL) {
        display_layer(window, map, player, position);
        position.z += 1;
    }
    return 0;
}
