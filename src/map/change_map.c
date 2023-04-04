/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** change_map.c
*/

#include "../../include/prototype.h"

int change_map_by_name(maps_t *maps, entity_t *player, char *name)
{
    int i = 0;
    while (maps->map[i] != NULL) {
        if (my_strcmp(maps->map[i]->name, name) == 0) {
            maps->selected_map = maps->map[i];
            player->position = maps->selected_map->spawn;
            sfVector2f size = maps->selected_map->layer[1]->size;
            set_isometric_pos(player, maps->selected_map->spawn, size);
        }
        i += 1;
    }
        return 0;
}

int change_map(maps_t *maps, entity_t *player, int id)
{
    maps->selected_map = maps->map[id];
    player->position = maps->selected_map->spawn;
    sfVector2f size = maps->selected_map->layer[1]->size;
    set_isometric_pos(player, maps->selected_map->spawn, size);
    return 0;
}
