/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** player_direction.c
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
