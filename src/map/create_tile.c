/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_tile.c
*/

#include "../../include/prototype.h"
#include <stdio.h>

tile_t *create_tile(int id, map_object_t **map_object, sfVector2i position)
{
    tile_t *tile = malloc(sizeof(tile_t));
    tile->id = id;
    tile->position.x = position.x;
    tile->position.y = position.y;
    tile->state = get_collision(map_object, id);
    tile->texture = get_texture(map_object, id);
    tile->is_trapped = 0;
    tile->tile = sfSprite_create();
    sfSprite_setTexture(tile->tile, tile->texture, sfFalse);
    sfVector2f real_position = {((position.x - position.y) * 32 / 2),
        ((position.x + position.y) * 32 / 4)};
    sfSprite_setPosition(tile->tile, real_position);
    return tile;
}
