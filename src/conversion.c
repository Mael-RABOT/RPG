/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** conversion.c
*/

#include "../include/prototype.h"

int set_isometric_pos(entity_t *entity, sfVector2f position, sfVector2f size)
{
    entity->position = position;
    sfVector2f real_position = {((position.x - position.y) * 32 / 2) +
        size.x * 32, ((position.x + position.y) * 32 / 4)};
    sfSprite_setPosition(entity->sprite->sprite, real_position);
    return 0;
}

sfVector2f get_isometric_pos(sfVector2f position, sfVector2f size)
{
    sfVector2f real_position = {((position.x - position.y) * 32 / 2) +
        size.x * 32, ((position.x + position.y) * 32 / 4)};
    return real_position;
}
