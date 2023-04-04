/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** player_event.c
*/

#include "../../include/prototype.h"

int move_top(maps_t *maps, entity_t *player, sfView *view)
{
    sfVector2f position = sfSprite_getPosition(player->sprite->sprite);
    sfVector2f new_position = {position.x, position.y};
    new_position.y -= 8;
    new_position.x += 16;
    player->position.y -= 1;
    sfSprite_setPosition(player->sprite->sprite, new_position);
    if (detect_collision(player, maps) == 1) {
        sfSprite_setPosition(player->sprite->sprite, position);
        player->position.y += 1;
        return 1;
    }
    return 0;
}

int move_bot(maps_t *maps, entity_t *player, sfView *view)
{
    sfVector2f position = sfSprite_getPosition(player->sprite->sprite);
    sfVector2f new_position = {position.x, position.y};
    new_position.y += 8;
    new_position.x -= 16;
    player->position.y += 1;
    sfSprite_setPosition(player->sprite->sprite, new_position);
    if (detect_collision(player, maps) == 1) {
        sfSprite_setPosition(player->sprite->sprite, position);
        player->position.y -= 1;
        return 1;
    }
    return 0;
}

int move_left(maps_t *maps, entity_t *player, sfView *view)
{
    sfVector2f position = sfSprite_getPosition(player->sprite->sprite);
    sfVector2f new_position = {position.x, position.y};
    new_position.y -= 8;
    new_position.x -= 16;
    player->position.x -= 1;
    sfSprite_setPosition(player->sprite->sprite, new_position);
    if (detect_collision(player, maps) == 1) {
        sfSprite_setPosition(player->sprite->sprite, position);
        player->position.x += 1;
        return 1;
    }
    return 0;
}

int move_right(maps_t *maps, entity_t *player, sfView *view)
{
    sfVector2f position = sfSprite_getPosition(player->sprite->sprite);
    sfVector2f new_position = {position.x, position.y};
    new_position.y += 8;
    new_position.x += 16;
    player->position.x += 1;
    sfSprite_setPosition(player->sprite->sprite, new_position);
    if (detect_collision(player, maps) == 1) {
        sfSprite_setPosition(player->sprite->sprite, position);
        player->position.x -= 1;
        return 1;
    }
    return 0;
}

int move_player(sfView *view, maps_t *maps, entity_t *player, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        int code = event.key.code;
        switch (code) {
            case 25:
                move_top(maps, player, view);
                break;
            case 18:
                move_bot(maps, player, view);
                break;
            case 16:
                move_left(maps, player, view);
                break;
            case 3:
                move_right(maps, player, view);
                break;
            default:
                break;
        }
    }
    return 0;
}
