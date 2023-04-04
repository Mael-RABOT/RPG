/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** position
*/

#include "../../include/prototype.h"

sfVector2f find_head_position(app_t *app, sfBool player)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    if (player == sfTrue)
        return (sfVector2f) {0, size.y / 2};
    return ((sfVector2f){size.x - (64 * 3), size.y / 2});
}

sfVector2f find_text_position(app_t *app)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    return (sfVector2f) {(size.x / 10) * 1, (size.y / 4) * 3};
}
