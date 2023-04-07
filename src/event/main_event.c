/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** main_event.c
*/

#include "../../include/prototype.h"

int manage_keys(app_t *app, sfKeyCode code)
{
    if (code == sfKeyF)
        app->fps->key_f = 1 - app->fps->key_f;
    return 0;
}

static int detect_event(app_t *app, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(app->window);
    if (app->state == splash && (event.type == sfEvtKeyPressed
        || event.type == sfEvtMouseButtonReleased))
        skip_splash_screen(app);
    if (app->state == game && event.type == sfEvtKeyPressed)
        manage_keys(app, event.key.code);
    if (app->state == main_menu)
        button_event(app, app->menu->main->button, event);
    if (app->state == settings)
        button_event(app, app->menu->settings->button, event);
    if (event.type == sfEvtKeyPressed && event.key.code == 36)
        app->state = paused;
    if (app->state == paused)
        button_event(app, app->menu->escape->button, event);
    return 0;
}

int main_event(app_t *app)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(app->window, &event)) {
        detect_event(app, event);
        move_player(app, event);
    }
    return 0;
}
