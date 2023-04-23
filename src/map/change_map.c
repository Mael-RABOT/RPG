/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** change_map.c
*/

#include "../../include/prototype.h"

int change_map_by_map(app_t *app, map_t *map, int old_map)
{
    if (old_map == 1)
        app->maps->old_map = app->maps->selected_map;
    app->maps->selected_map = map;
    app->player->layer = 1;
    app->player->position = app->maps->selected_map->spawn;
    set_isometric_pos(app->player, app->maps->selected_map->spawn);
    if (app->menu->state == game) {
        sfRenderWindow_setView(app->window, app->default_view);
        launch_cinematic(app, Portal);
        sfRenderWindow_setView(app->window, app->view);
    }
    return 0;
}

int change_map(app_t *app, int id)
{
    app->maps->old_map = app->maps->selected_map;
    app->maps->selected_map = app->maps->map[id];
    app->player->layer = 1;
    app->player->position = app->maps->selected_map->spawn;
    set_isometric_pos(app->player, app->maps->selected_map->spawn);
    if (app->menu->state == game) {
        sfRenderWindow_setView(app->window, app->default_view);
        launch_cinematic(app, Portal);
        sfRenderWindow_setView(app->window, app->view);
    }
    return 0;
}

int change_map_by_name(app_t *app, char *name)
{
    int i = 0;
    while (app->maps->map[i] != NULL) {
        if (my_strcmp(app->maps->map[i]->name, name) == 0) {
            change_map(app, i);
        }
        i += 1;
    }
    return 0;
}
