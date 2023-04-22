/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** launch_fight.c
*/

#include "../../include/prototype.h"

int stop_fight(app_t *app)
{
    if (app->fight->no_round == 0) {
        change_map_by_map(app, app->maps->old_map);
        app->fight->is_fighting = 0;
    }
    return 0;
}

int launch_fight(app_t *app)
{
    app->fight->is_fighting = 1;
    change_map(app, 3);
    app->fight->no_round = 10;
    return 0;
}
