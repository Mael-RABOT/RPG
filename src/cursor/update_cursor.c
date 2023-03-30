/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** update_cursor
*/

#include "../../include/prototype.h"

void update_cursor(app_t *app)
{
    sfSprite_setPosition(app->cursor->sprite,
    (sfVector2f){
    sfMouse_getPositionRenderWindow(app->window).x - CURSOR_OFFSET_X,
    sfMouse_getPositionRenderWindow(app->window).y - CURSOR_OFFSET_Y});
    sfRenderWindow_drawSprite(app->window, app->cursor->sprite, NULL);
}
