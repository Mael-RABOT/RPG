/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** buttons.c
*/

#include "../../include/prototype.h"

void play(app_t *app, int i)
{
    app->state = game;
    printf("%s\n", "play!");
    return;
}

void resume(app_t *app, int i)
{
    printf("%s\n", "resume!");
    return;
}

void settings_b(app_t *app, int i)
{
    printf("%s\n", "settings!");
    return;
}

void quit(app_t *app, int i)
{
    printf("%s\n", "quit!");
    return;
}
