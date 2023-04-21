/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** main_event.c
*/

#include "../../include/prototype.h"

static int detect_escape(app_t *app, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == 36) {
        switch (app->menu->state) {
            case game:
                app->menu->state = paused; break;
            case paused:
                app->menu->state = game; break;
            case settings:
                app->menu->state = app->menu->old_state; break;
        }
    }
    return 0;
}

static int manage_keys(app_t *app, sfKeyCode code)
{
    if (code == sfKeyF)
        app->fps->key_f = 1 - app->fps->key_f;
    return 0;
}

static int detect_event(app_t *app, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(app->window);
    if (app->menu->state == splash && (event.type == sfEvtKeyPressed
        || event.type == sfEvtMouseButtonReleased))
        skip_splash_screen(app);
    if (app->menu->state == game && event.type == sfEvtKeyPressed)
        manage_keys(app, event.key.code);
    menu_event(app, event);
    detect_escape(app, event);
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
