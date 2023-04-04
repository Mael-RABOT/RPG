/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** sprite.c
*/

#include "../../include/prototype.h"

int destroy_sprite(sprite_t *sprite)
{
    if (!sprite)
        return 1;
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->texture);
    free(sprite);
    return 0;
}

sprite_t *create_sprite(const char *pathfile)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(pathfile, NULL);
    if (!sprite->texture)
        return NULL;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    return sprite;
}
