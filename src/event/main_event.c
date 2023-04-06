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

int settings_menu_events(app_t *app, sfEvent event)
{
    button_event(app->settings_menu->button, event);
    update_button_texture(app, app->settings_menu->button);
    return 0;
}

int main_menu_events(app_t *app, sfEvent event)
{
    button_event(app->main_menu->button, event);
    update_button_texture(app, app->main_menu->button);
    return 0;
}

int main_event(app_t *app)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(app->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(app->window);
        if (app->state == splash &&
            (event.type == sfEvtKeyPressed
            || event.type == sfEvtMouseButtonReleased))
            skip_splash_screen(app);
        if (app->state == game && event.type == sfEvtKeyPressed)
            manage_keys(app, event.key.code);
        if (app->state == main_menu)
            main_menu_events(app, event);
        if (app->state == settings)
            settings_menu_events(app, event);
        move_player(app, event);
    }
    return 0;
}
