/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** player_event.c
*/

#include "../../include/prototype.h"

int move_top(map_t *map, entity_t *player, sfView *view)
{
    sfVector2f position = sfSprite_getPosition(player->sprite->sprite);
    sfVector2f new_position = {position.x, position.y};
    new_position.y -= 8;
    new_position.x += 16;
    player->position.y -= 1;
    sfSprite_setPosition(player->sprite->sprite, new_position);
    if (detect_collision(player, map) == 1) {
        sfSprite_setPosition(player->sprite->sprite, position);
        player->position.y += 1;
        return 1;
    }
    //sfView_setCenter(view, new_position);
    return 0;
}

int move_bot(map_t *map, entity_t *player, sfView *view)
{
    sfVector2f position = sfSprite_getPosition(player->sprite->sprite);
    sfVector2f new_position = {position.x, position.y};
    new_position.y += 8;
    new_position.x -= 16;
    player->position.y += 1;
    sfSprite_setPosition(player->sprite->sprite, new_position);
    if (detect_collision(player, map) == 1) {
        sfSprite_setPosition(player->sprite->sprite, position);
        player->position.y -= 1;
        return 1;
    }
    //sfView_setCenter(view, new_position);
    return 0;
}

int move_left(map_t *map, entity_t *player, sfView *view)
{
    sfVector2f position = sfSprite_getPosition(player->sprite->sprite);
    sfVector2f new_position = {position.x, position.y};
    new_position.y -= 8;
    new_position.x -= 16;
    player->position.x -= 1;
    sfSprite_setPosition(player->sprite->sprite, new_position);
    if (detect_collision(player, map) == 1) {
        sfSprite_setPosition(player->sprite->sprite, position);
        player->position.x += 1;
        return 1;
    }
    //sfView_setCenter(view, new_position);
    return 0;
}

int move_right(map_t *map, entity_t *player, sfView *view)
{
    sfVector2f position = sfSprite_getPosition(player->sprite->sprite);
    sfVector2f new_position = {position.x, position.y};
    new_position.y += 8;
    new_position.x += 16;
    player->position.x += 1;
    sfSprite_setPosition(player->sprite->sprite, new_position);
    if (detect_collision(player, map) == 1) {
        sfSprite_setPosition(player->sprite->sprite, position);
        player->position.x -= 1;
        return 1;
    }
    //sfView_setCenter(view, new_position);
    return 0;
}

int move_player(sfView *view, map_t *map, entity_t *player, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        int code = event.key.code;
        switch (code) {
            case 25:
                move_top(map, player, view);
                break;
            case 18:
                move_bot(map, player, view);
                break;
            case 16:
                move_left(map, player, view);
                break;
            case 3:
                move_right(map, player, view);
                break;
            default:
                break;
        }
    }
    return 0;
}
