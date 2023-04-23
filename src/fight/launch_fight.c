/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** launch_fight.c
*/

#include "../../include/prototype.h"

int stop_fight(app_t *app)
{
    if (app->fight->no_round == 0 && app->fight->is_fighting == 1) {
        change_map_by_map(app, app->maps->old_map, 1);
        app->fight->is_fighting = 0;
    }
    if (app->fight->no_round == 0 && app->fight->is_fighting == 2) {
        change_map_by_name(app, "Hub");
        app->fight->is_fighting = 0;
        credits(app);
    }
    return 0;
}

int launch_fight(app_t *app, int type)
{
    app->fight->is_fighting = type;
    change_map(app, 3);
    app->fight->no_round = 10;
    return 0;
}
