/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** center_view.c
*/

#include "../../include/prototype.h"

int center_view(sfView *view, entity_t *player)
{
    sfVector2f position = sfSprite_getPosition(player->sprite->sprite);
    sfView_setCenter(view, position);
    return 0;
}
