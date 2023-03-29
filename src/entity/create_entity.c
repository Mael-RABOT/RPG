/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_player.c
*/

#include "../../include/prototype.h"

int set_isometric_pos(entity_t *entity, sfVector2f position, sfVector2f size)
{
    sfVector2f real_position = {((position.x - position.y) * 32 / 2) +
        size.x * 32, ((position.x + position.y) * 32 / 4)};
    sfSprite_setPosition(entity->sprite->sprite, real_position);
    return 0;
}

int destroy_entity(entity_t *entity)
{
    destroy_sprite(entity->sprite);
    free(entity);
    return 0;
}

entity_t *create_entity(const char *pathfile)
{
    entity_t *player = malloc(sizeof(entity_t));
    player->sprite = create_sprite(pathfile);
    player->layer = 0;
    return player;
}
