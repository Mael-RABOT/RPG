/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_tile.c
*/

#include "../../include/prototype.h"

int destroy_tile(tile_t *tile)
{
    sfSprite_destroy(tile->tile);
    free(tile);
}

tile_t *create_tile(int id, manifest_t *manifest, sfVector2i position)
{
    tile_t *tile = malloc(sizeof(tile_t));
    tile->id = id;
    tile->position = position;
    tile->collision = get_collision(manifest, id);
    tile->texture = get_texture(manifest, id);
    tile->tile = sfSprite_create();
    sfVector2f real_position = {0, 0};
    if (position.y % 2 != 0) {
        real_position = (sfVector2f){position.x * 32 + 16, position.y * 32 - 24};
    } else {
        real_position = (sfVector2f){position.x * 32, position.y * 32};
    }
    sfSprite_setPosition(tile->tile, real_position);
    sfSprite_setTexture(tile->tile, tile->texture, sfFalse);
    return tile;
}
