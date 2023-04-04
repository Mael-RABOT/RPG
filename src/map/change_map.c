/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** change_map.c
*/

#include "../../include/prototype.h"

int change_map(app_t *app, maps_t *maps, entity_t *player, int id)
{
    maps->selected_map = maps->map[id];
    player->position = maps->selected_map->spawn;
    sfVector2f size = maps->selected_map->layer[1]->size;
    set_isometric_pos(player, maps->selected_map->spawn, size);
    sfRenderWindow_setView(app->window, app->default_view);
    launch_cinematic(app, Portal);
    sfRenderWindow_setView(app->window, app->view);
    return 0;
}

int change_map_by_name(app_t *app, maps_t *maps, entity_t *player, char *name)
{
    int i = 0;
    while (maps->map[i] != NULL) {
        if (my_strcmp(maps->map[i]->name, name) == 0) {
            change_map(app, maps, player, i);
        }
        i += 1;
    }
        return 0;
}
