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
    player->position.y -= 1;
    int status = detect_collision(app, player);
    switch (status) {
        case 1:
            player->position.y += 1;
            return 1;
        case 2:
            player->position.y -= 2;
            player->position.x -= 1;
            break;
        case 3:
            player->position.x += 1;
            break;
    }
    set_isometric_pos(player, player->position, maps->selected_map->size);
    return 0;
}

int move_bot(app_t *app, maps_t *maps, entity_t *player, sfView *view)
{
    player->texture_rect.left = 32;
    sfSprite_setTextureRect(player->sprite->sprite, player->texture_rect);
    player->position.y += 1;
    int status = detect_collision(app, player);
    switch (status) {
        case 1:
            player->position.y -= 1;
            return 1;
        case 2:
            player->position.x -= 1;
            break;
        case 3:
            player->position.x += 1;
            player->position.y += 2;
            break;
    }
    set_isometric_pos(player, player->position, maps->selected_map->size);
    return 0;
}

int move_left(app_t *app, maps_t *maps, entity_t *player, sfView *view)
{
    player->texture_rect.left = 96;
    sfSprite_setTextureRect(player->sprite->sprite, player->texture_rect);
    player->position.x -= 1;
    int status = detect_collision(app, player);
    switch (status) {
        case 1:
            player->position.x += 1;
            return 1;
        case 2:
            player->position.x -= 2;
            player->position.y -= 1;
            break;
        case 3:
            player->position.y += 1;
            break;
    }
    set_isometric_pos(player, player->position, maps->selected_map->size);
    return 0;
}

int move_right(app_t *app, maps_t *maps, entity_t *player, sfView *view)
{
    player->texture_rect.left = 0;
    sfSprite_setTextureRect(player->sprite->sprite, player->texture_rect);
    player->position.x += 1;
    int status = detect_collision(app, player);
    switch (status) {
        case 1:
            player->position.x -= 1;
            return 1;
        case 2:
            player->position.y -= 1;
            break;
        case 3:
            player->position.y += 1;
            player->position.x += 2;
    }
    set_isometric_pos(player, player->position, maps->selected_map->size);
    return 0;
}

int move_player(app_t *app, sfEvent event)
{
    sfTime time = sfClock_getElapsedTime(app->player->move_clock);
    if (time.microseconds < 1000)
        return 0;
    sfClock_restart(app->player->move_clock);
    if (event.type == sfEvtKeyPressed) {
        int code = event.key.code;
        switch (code) {
            case 25:
                move_top(app, app->maps, app->player, app->view);
                break;
            case 18:
                move_bot(app, app->maps, app->player, app->view);
                break;
            case 16:
                move_left(app, app->maps, app->player, app->view);
                break;
            case 3:
                move_right(app, app->maps, app->player, app->view);
                break;
            default:
                break;
        }
    }
    return 0;
}
