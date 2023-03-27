/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** free.c
*/

#include "../../include/prototype.h"

int destroy_tile(tile_t *tile)
{
    sfSprite_destroy(tile->tile);
    free(tile);
    return 0;
}

int destroy_map(map_t *map)
{
    int i = 0;
    while (map->map[i] != NULL) {
        int j = 0;
        while (map->map[i][j] != NULL) {
            destroy_tile(map->map[i][j]);
            j += 1;
        }
        free(map->map[i]);
        i += 1;
    }
    free(map->map);
    free(map);
    return 0;
}
