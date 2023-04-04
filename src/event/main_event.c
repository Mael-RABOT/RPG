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
    if (code == sfKeyC) {
        if (app->fps->key_f == 0)
            change_map(app->maps, app->player, 0);
        else
            change_map(app->maps, app->player, 1);
    }
    return 0;
}

int main_event(app_t *app)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(app->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(app->window);
        if (app->state == splash && event.type == sfEvtKeyPressed)
            skip_splash_screen(app);
        if (app->state == game && event.type == sfEvtKeyPressed)
            manage_keys(app, event.key.code);
        move_player(app->view, app->maps, app->player, event);
    }
    return 0;
}
