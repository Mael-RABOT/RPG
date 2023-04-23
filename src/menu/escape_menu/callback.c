/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** callback.c
*/

#include "../../../include/prototype.h"

void launch_main_menu(app_t *app)
{
    app->menu->old_state = app->menu->state;
    create_save(app);
    app->menu->state = main_menu;
}

void launch_setting(app_t *app)
{
    app->menu->old_state = app->menu->state;
    app->menu->state = settings;
}

void pause_game(app_t *app)
{
    app->menu->old_state = app->menu->state;
    app->menu->state = game;
}

void resume_game(app_t *app)
{
    app->menu->old_state = app->menu->state;
    app->menu->state = game;
}
