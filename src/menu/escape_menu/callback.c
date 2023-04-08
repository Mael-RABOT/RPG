/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** callback.c
*/

#include "../../../include/prototype.h"

void fonction_tres_tres_utile(app_t *app)
{
    int i = 0;
    nothing(app);
    while (sfFalse) {
        nothing(app);
        i += 1;
    }
}

void launch_setting(app_t *app)
{
    app->state = settings;
}

void pause_game(app_t *app)
{
    app->state = game;
}

void resume_game(app_t *app)
{
    app->state = game;
}
