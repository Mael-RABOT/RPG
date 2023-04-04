/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** ressources
*/

#include "../../include/prototype.h"

static float calculate_scale_factor(app_t  *app, sprite_t *sprite)
{
    sfVector2f scale = (sfVector2f){sfRenderWindow_getSize(app->window).x,
        sfRenderWindow_getSize(app->window).y};
    float scale_factor = MAX(scale.x / sfTexture_getSize(sprite->texture).x,
            scale.y / sfTexture_getSize(sprite->texture).y);
    return scale_factor;
}

void scale_sprite(app_t *app, sprite_t *background)
{
    float scale_factor = calculate_scale_factor(app, background);
    sfSprite_setScale(background->sprite,
            (sfVector2f){scale_factor,scale_factor});
}
