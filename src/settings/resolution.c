/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** resolution.c
*/

#include "../../include/prototype.h"

void toggle_windowed(app_t *app)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow_close(app->window);
    sfRenderWindow_destroy(app->window);
    app->window = sfRenderWindow_create(mode, "my_rpg", sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(app->window, sfFalse);
}

void toggle_borderless(app_t *app)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow_close(app->window);
    sfRenderWindow_destroy(app->window);
    app->window = sfRenderWindow_create(mode, "my_rpg", sfNone, NULL);
    sfRenderWindow_setMouseCursorVisible(app->window, sfFalse);
}

void toggle_fullscreen(app_t *app)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow_close(app->window);
    sfRenderWindow_destroy(app->window);
    app->window = sfRenderWindow_create(mode, "my_rpg", sfFullscreen, NULL);
    sfRenderWindow_setMouseCursorVisible(app->window, sfFalse);
    return;
}