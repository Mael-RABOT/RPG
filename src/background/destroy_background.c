/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_background
*/

#include "../../include/prototype.h"

void destroy_background(app_t *app)
{
    sfTexture_destroy(app->background->texture);
    sfSprite_destroy(app->background->sprite);
    free(app->background);
}
