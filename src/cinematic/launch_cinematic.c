/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** launch_cinematics
*/

#include "../../include/prototype.h"

static void cinematic_event(sfRenderWindow *window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

static my_sprite_t *init_cinematic_sprite(cinematic_t cinematic_type,
    sfVector2f scale)
{
    my_sprite_t *sprite = malloc(sizeof(sprite));
    sprite->texture = sfTexture_createFromFile(
        get_cinematic_path(cinematic_type),
        sfFalse);
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    int width = sfTexture_getSize(sprite->texture).x /
        find_max_frame(cinematic_type);
    int height = sfTexture_getSize(sprite->texture).y;
    sfSprite_setTextureRect(sprite->sprite, (sfIntRect){0, 0, width, height});
    sfSprite_setPosition(sprite->sprite,
        (sfVector2f){0, 0});
    float scale_factor = MAX(scale.x / sfTexture_getSize(sprite->texture).x,
        scale.y / sfTexture_getSize(sprite->texture).y);
    sfSprite_setScale(sprite->sprite, (sfVector2f){
        scale_factor,
        scale_factor});
    return (sprite);
}

static void update_sprite(my_sprite_t *sprite, const int frame,
    const int max_frame)
{
    sfSprite_setTextureRect(sprite->sprite, (sfIntRect){
        (sfTexture_getSize(sprite->texture).x / max_frame) * (frame),
        0,
        sfTexture_getSize(sprite->texture).x / max_frame,
        sfTexture_getSize(sprite->texture).y}
    );
}

static void tick(app_t *app, my_sprite_t *sprite, int frame, int max_frame)
{
    update_sprite(sprite, frame, max_frame);
    sfRenderWindow_clear(app->window, sfBlack);
    sfRenderWindow_drawSprite(app->window, sprite->sprite, NULL);
    sfRenderWindow_display(app->window);
}

int launch_cinematic(app_t *app, cinematic_t cinematic_type)
{
    sfClock *cinematic_clock = sfClock_create();
    my_sprite_t *sprite = init_cinematic_sprite(cinematic_type,
        (sfVector2f){sfRenderWindow_getSize(app->window).x,
        sfRenderWindow_getSize(app->window).y});
    int frame = 0;
    int max_frame = find_max_frame(cinematic_type);
    sfRenderWindow_clear(app->window, sfBlack);
    while (frame < max_frame && sfRenderWindow_isOpen(app->window)) {
        cinematic_event(app->window);
        if (sfClock_getElapsedTime(cinematic_clock).microseconds
            / TIME_DIVIDER > 0.15) {
            tick(app, sprite, frame, max_frame);
            sfClock_restart(cinematic_clock);
            ++frame;
        }
    }
    destroy_cinematic(sprite, cinematic_clock);
    return EXIT_SUCCESS;
}
