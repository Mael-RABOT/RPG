/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_ressources
*/

#include "../../include/prototype.h"

void destroy_cinematic(my_sprite_t *sprite, sfClock *clock)
{
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
    sfClock_destroy(clock);
}
