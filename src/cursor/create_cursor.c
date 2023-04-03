/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_cursor
*/

#include "../../include/prototype.h"

void create_cursor(app_t *app)
{
    sfRenderWindow_setMouseCursorVisible(app->window, sfFalse);
    app->cursor = malloc(sizeof(sprite_t));
    app->cursor->texture = sfTexture_createFromFile(CURSOR, sfFalse);
    app->cursor->sprite = sfSprite_create();
    sfSprite_setTexture(app->cursor->sprite, app->cursor->texture, sfFalse);
}
