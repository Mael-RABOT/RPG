/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_tile.c
*/

#include "../../include/prototype.h"

tile_t *create_tile(int id, manifest_t *manifest, sfVector2i position, int size)
{
    tile_t *tile = malloc(sizeof(tile_t));
    tile->id = id;
    tile->position = position;
    tile->collision = get_collision(manifest, id);
    tile->texture = get_texture(manifest, id);
    tile->tile = sfSprite_create();
    sfSprite_setTexture(tile->tile, tile->texture, sfFalse);
    sfVector2f real_position;
    if (position.y % 2 == 0) {
        real_position = (sfVector2f){position.x * 32, (position.y * 32 -
            position.y * 24)};
    } else {
        real_position = (sfVector2f){position.x * 32 + 16, (position.y * 32 -
            position.y * 24)};
    }
    sfSprite_setPosition(tile->tile, real_position);
    return tile;
}
