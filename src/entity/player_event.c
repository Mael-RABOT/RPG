/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** player_event.c
*/

#include "../../include/prototype.h"

static int detect_on_sprite(sfSprite *player, tile_t **tile)
{
    int i = 0;
    while (tile[i] != NULL) {
        sfFloatRect bounds = sfSprite_getGlobalBounds(player);
        sfFloatRect bounds_2 = sfSprite_getGlobalBounds(tile[i]->tile);
        sfFloatRect bounds_3 = {0, 0, 0, 0};
        if (sfFloatRect_intersects(&bounds, &bounds_2, &bounds_3) == sfTrue) {
            printf("%.2f - %.2f - %.2f - %.2f\n", bounds_3.width, bounds_3.height,
                bounds_3.left, bounds_3.top);
            return 1;
        }
        i += 1;
    }
    return 0;
}

static int detect_on_layer(sfSprite *player, tile_t ***layer)
{
    int i = 0;
    while (layer[i] != NULL) {
        if (detect_on_sprite(player, layer[i]) == 1)
            return 1;
        i += 1;
    }
    return 0;
}

static int detect_collision(entity_t *player, map_t *map)
{
    int i = player->layer + 1;
    return detect_on_layer(player->sprite->sprite, map->layer[i]->layer);
        return 1;
    return 0;
}

int move_player(sfView *view, map_t *map, entity_t *player, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        sfVector2f position = sfSprite_getPosition(player->sprite->sprite);
        sfVector2f new_position = {position.x, position.y};
        int code = event.key.code;
        switch (code) {
            case 25:
                new_position.y -= 8;
                new_position.x += 16;
                break;
            case 18:
                new_position.y += 8;
                new_position.x -= 16;
                break;
            case 16:
                new_position.y -= 8;
                new_position.x -= 16;
                break;
            case 3:
                new_position.y += 8;
                new_position.x += 16;
                break;
            default:
                break;
        }
        sfSprite_setPosition(player->sprite->sprite, new_position);
        if (detect_collision(player, map) == 1) {
            sfSprite_setPosition(player->sprite->sprite, position);
            return 1;
        }
        sfView_setCenter(view, new_position);
    }
    return 0;
}
