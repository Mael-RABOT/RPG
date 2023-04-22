/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** kill_player.c
*/

#include "../../include/prototype.h"

int kill_player(app_t *app)
{
    int x = app->player->position.x;
    int y = app->player->position.y;
    map_t *map = app->maps->selected_map;
    tile_t *ptile = map->layer[app->player->layer - 1]->layer[y + 1][x + 1];
    if (ptile->is_trapped == 1) {
        app->fight->no_round = 10;
        change_map(app, 3);
    }
    return 0;
}
