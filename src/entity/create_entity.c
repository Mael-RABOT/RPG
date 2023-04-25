/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_player.c
*/

#include "../../include/prototype.h"

int destroy_entity(entity_t *entity)
{
    if (entity->stat != NULL)
        free(entity->stat);
    destroy_sprite(entity->sprite);
    sfClock_destroy(entity->move_clock);
    free(entity);
    return 0;
}

entity_t *create_entity(app_t *app, const char *pathfile,
    player_preset_t preset, weapon_type_t type)
{
    (void)type;
    (void)preset;
    entity_t *entity = malloc(sizeof(entity_t));
    entity->move_clock = sfClock_create();
    entity->sprite = create_sprite(pathfile);
    entity->stat = create_player(app, Default);
    sfFloatRect rect = sfSprite_getLocalBounds(entity->sprite->sprite);
    rect.width /= 4;
    sfIntRect new_rect = {rect.left, rect.top, rect.width, rect.height};
    entity->texture_rect = new_rect;
    sfSprite_setTextureRect(entity->sprite->sprite, new_rect);
    entity->layer = 1;
    return entity;
}
