/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_app.c
*/

#include "../../include/prototype.h"

void destroy_sprite_t(my_sprite_t *sprite)
{
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
    free(sprite);
}

int destroy_app(app_t *app)
{
    destroy_background(app);
    sfMusic_destroy(app->music);
    sfRenderWindow_destroy(app->window);
    destroy_sprite_t(app->cursor);
    free(app);
    return 0;
}
