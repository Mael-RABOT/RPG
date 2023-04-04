/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_player.c
*/

#include "../../include/prototype.h"

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
    sfFloatRect rect = sfSprite_getLocalBounds(player->sprite->sprite);
    rect.width /= 4;
    sfIntRect new_rect = {rect.left, rect.top, rect.width, rect.height};
    player->texture_rect = new_rect;
    sfSprite_setTextureRect(player->sprite->sprite, new_rect);
    player->layer = 0;
    return player;
}
