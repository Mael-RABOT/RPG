/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** background
*/

#include "../../include/prototype.h"

void change_background(sprite_t *background, char *filepath)
{
    background->texture = sfTexture_createFromFile(filepath, sfFalse);
    sfSprite_setTexture(background->sprite, background->texture, sfFalse);
}

void display_background(app_t *app)
{
    sfRenderWindow_drawSprite(app->window, app->background->sprite, NULL);
}
