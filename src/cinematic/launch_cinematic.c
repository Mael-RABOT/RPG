/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** launch_cinematics
*/

#include "../../include/prototype.h"

static my_sprite_t *init_cinematic_sprite(cinematic_t cinematic_type, sfVector2f scale)
{
    my_sprite_t *sprite = malloc(sizeof(sprite));
    sprite->texture = sfTexture_createFromFile(, sfFalse);
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, (sfIntRect){
            0, 0, sfTexture_getSize(sprite->texture).x,
            sfTexture_getSize(sprite->texture).y});
    sfSprite_setScale(sprite->sprite, scale);
    return (sprite);
}

static void update_sprite(my_sprite_t *sprite, const int frame, const int max_frame)
{
    sfSprite_setTextureRect(sprite->sprite, (sfIntRect){
        0,
        (sfTexture_getSize(sprite->texture).x / max_frame) * frame,
        sfTexture_getSize(sprite->texture).x,
        sfTexture_getSize(sprite->texture).y}
    );
}

int launch_cinematic(app_t *app, cinematic_t cinematic_type)
{
    my_printf("Launch animation %d\n", cinematic_type);
    sfClock *cinematic_clock = sfClock_create();
    my_sprite_t *sprite = init_cinematic_sprite(cinematic_type,
        (sfVector2f){sfRenderWindow_getSize(app->window).x,
        sfRenderWindow_getSize(app->window).y});
    int frame = 0;
    int max_frame = find_max_frame(cinematic_type);
    sfRenderWindow_clear(app->window, sfBlack);
    while (frame < max_frame)
        if (sfClock_getElapsedTime(cinematic_clock).microseconds
            / TIME_DIVIDER > 1.5) {
            update_sprite(sprite);
            sfRenderWindow_clear(app->window, sfBlack);
            sfRenderWindow_drawSprite(app->window, sprite->sprite, NULL);
            sfClock_restart(cinematic_clock);
            ++frame;
        }
    return EXIT_SUCCESS;
}
