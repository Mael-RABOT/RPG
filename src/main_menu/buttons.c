/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** buttons.c
*/

#include "../../include/prototype.h"

void play(app_t *app)
{
    app->state = character_stat_selection;
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
