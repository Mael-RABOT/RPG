/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** player_event.c
*/

#include "../../include/prototype.h"

int move_top(app_t *app, maps_t *maps, entity_t *player, sfView *view)
{
    player->texture_rect.left = 64;
    sfSprite_setTextureRect(player->sprite->sprite, player->texture_rect);
    sfVector2f position = sfSprite_getPosition(player->sprite->sprite);
    sfVector2f new_position = {position.x, position.y};
    new_position.y -= 8;
    new_position.x += 16;
    player->position.y -= 1;
    sfSprite_setPosition(player->sprite->sprite, new_position);
    if (detect_collision(app, player, maps) == 1) {
        sfSprite_setPosition(player->sprite->sprite, position);
        player->position.y += 1;
        return 1;
    }
    return 0;
}

int move_bot(app_t *app, maps_t *maps, entity_t *player, sfView *view)
{
    player->texture_rect.left = 32;
    sfSprite_setTextureRect(player->sprite->sprite, player->texture_rect);
    sfVector2f position = sfSprite_getPosition(player->sprite->sprite);
    sfVector2f new_position = {position.x, position.y};
    new_position.y += 8;
    new_position.x -= 16;
    player->position.y += 1;
    sfSprite_setPosition(player->sprite->sprite, new_position);
    if (detect_collision(app, player, maps) == 1) {
        sfSprite_setPosition(player->sprite->sprite, position);
        player->position.y -= 1;
        return 1;
    }
    return 0;
}

int move_left(app_t *app, maps_t *maps, entity_t *player, sfView *view)
{
    player->texture_rect.left = 96;
    sfSprite_setTextureRect(player->sprite->sprite, player->texture_rect);
    sfVector2f position = sfSprite_getPosition(player->sprite->sprite);
    sfVector2f new_position = {position.x, position.y};
    new_position.y -= 8;
    new_position.x -= 16;
    player->position.x -= 1;
    sfSprite_setPosition(player->sprite->sprite, new_position);
    if (detect_collision(app, player, maps) == 1) {
        sfSprite_setPosition(player->sprite->sprite, position);
        player->position.x += 1;
        return 1;
    }
    return 0;
}

int move_right(app_t *app, maps_t *maps, entity_t *player, sfView *view)
{
    player->texture_rect.left = 0;
    sfSprite_setTextureRect(player->sprite->sprite, player->texture_rect);
    sfVector2f position = sfSprite_getPosition(player->sprite->sprite);
    sfVector2f new_position = {position.x, position.y};
    new_position.y += 8;
    new_position.x += 16;
    player->position.x += 1;
    sfSprite_setPosition(player->sprite->sprite, new_position);
    if (detect_collision(app, player, maps) == 1) {
        sfSprite_setPosition(player->sprite->sprite, position);
        player->position.x -= 1;
        return 1;
    }
    return 0;
}

int move_player(app_t *app, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        int code = event.key.code;
        switch (code) {
            case 25:
                move_top(app, maps, player, view);
                break;
            case 18:
                move_bot(app, maps, player, view);
                break;
            case 16:
                move_left(app, maps, player, view);
                break;
            case 3:
                move_right(app, maps, player, view);
                break;
            default:
                break;
        }
    }
    return 0;
}
