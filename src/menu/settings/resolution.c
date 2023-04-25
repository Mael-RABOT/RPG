/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** resolution.c
*/

#include "../../../include/prototype.h"

void set_1920_1080(app_t *app)
{
    sfVector2u size = {1920, 1080};
    sfVector2i position = {0, 0};
    sfRenderWindow_setSize(app->window, size);
    sfRenderWindow_setPosition(app->window, position);
}

void set_800_400(app_t *app)
{
    sfVector2u size = {854, 480};
    sfVector2i position = {0, 0};
    sfRenderWindow_setSize(app->window, size);
    sfRenderWindow_setPosition(app->window, position);
}

void toggle_windowed(app_t *app)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow_close(app->window);
    sfRenderWindow_destroy(app->window);
    app->window = sfRenderWindow_create(mode, "my_rpg", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(app->window, 60);
    sfRenderWindow_setMouseCursorVisible(app->window, sfFalse);
    sfRenderWindow_setPosition(app->window, (sfVector2i){0, 0});
}

void toggle_borderless(app_t *app)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow_close(app->window);
    sfRenderWindow_destroy(app->window);
    app->window = sfRenderWindow_create(mode, "my_rpg", sfNone, NULL);
    sfRenderWindow_setFramerateLimit(app->window, 60);
    sfRenderWindow_setMouseCursorVisible(app->window, sfFalse);
    sfRenderWindow_setPosition(app->window, (sfVector2i){0, 0});
}

void toggle_fullscreen(app_t *app)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow_close(app->window);
    sfRenderWindow_destroy(app->window);
    app->window = sfRenderWindow_create(mode, "my_rpg", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(app->window, 60);
    sfRenderWindow_setMouseCursorVisible(app->window, sfFalse);
    return;
}
