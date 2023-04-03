/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** buttons.c
*/

#include "../../include/prototype.h"

void play(app_t *app)
{
    app->state = game;
    return;
}

void resume(app_t *app)
{
    app->state = game;
    return;
}

void settings_b(app_t *app)
{
    app->state = settings;
    return;
}

void quit(app_t *app)
{
    app->state = closed;
    sfRenderWindow_close(app->window);
    return;
}

int main_menu_buttons_actions(app_t *app)
{
    if (IS_PRESSED(app->main_menu->play->state))
        play(app);
    if (IS_PRESSED(app->main_menu->resume->state))
        resume(app);
    if (IS_PRESSED(app->main_menu->settings->state))
        settings_b(app);
    if (IS_PRESSED(app->main_menu->quit->state))
        quit(app);
    return 0;
}
