/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** player_event.c
*/

#include "../../include/prototype.h"

/*
 * 25 up
 * 18 down
 * 16 left
 * 3 right
*/

int move_player(map_t *map, entity_t *player, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        sfVector2f position = sfSprite_getPosition(player->sprite->sprite);
        int code = event.key.code;
        switch (code) {
            case 25:
                position.y -= 8;
                position.x += 16;
                break;
            case 18:
                position.y += 8;
                position.x -= 16;
                break;
            case 16:
                position.y -= 8;
                position.x -= 16;
                break;
            case 3:
                position.y += 8;
                position.x += 16;
                break;
            default:
                break;
        }
        sfSprite_setPosition(player->sprite->sprite, position);
    }
    return 0;
}
