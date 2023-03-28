/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_tile.c
*/

#include "../../include/prototype.h"

tile_t *create_tile(int id, map_object_t **map_object, sfVector2i position,
    sfVector2i size)
{
    tile_t *tile = malloc(sizeof(tile_t));
    tile->id = id;
    tile->position = position;
    tile->collision = get_collision(map_object, id);
    tile->texture = get_texture(map_object, id);
    tile->tile = sfSprite_create();
    sfSprite_setTexture(tile->tile, tile->texture, sfFalse);
    sfVector2f real_position = {((position.x - position.y) * 32 / 2) +
        size.x * 32, ((position.x + position.y) * 32 / 4)};
    sfSprite_setPosition(tile->tile, real_position);
    return tile;
}
