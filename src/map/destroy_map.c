/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_map.c
*/

#include "../../include/prototype.h"

int destroy_object(map_object_t *object)
{
    free(object->path);
    sfTexture_destroy(object->texture);
    free(object);
    return 0;
}

int destroy_tile(tile_t *tile)
{
    sfSprite_destroy(tile->tile);
    if (tile->teleport != NULL) {
        free(tile->teleport->name);
        free(tile->teleport);
    }
    free(tile);
    return 0;
}

int destroy_layer(layer_t *layer)
{
    free(layer->pathfile);
    int i = 0;
    while (layer->layer[i] != NULL) {
        int j = 0;
        while (layer->layer[i][j] != NULL) {
            destroy_tile(layer->layer[i][j]);
            j += 1;
        }
        free(layer->layer[i]);
        i += 1;
    }
    free(layer->layer);
    free(layer);
    return 0;
}

int destroy_map(map_t *map)
{
    int i = 0;
    free(map->name);
    free(map->path);
    while (map->layer[i] != NULL) {
        destroy_layer(map->layer[i]);
        i += 1;
    }
    free(map->layer);
    free(map);
    return 0;
}

int destroy_maps(maps_t *maps)
{
    int i = 0;
    while (maps->map_object[i] != NULL) {
        destroy_object(maps->map_object[i]);
        i += 1;
    }
    i = 0;
    while (maps->map[i] != NULL) {
        destroy_map(maps->map[i]);
        i += 1;
    }
    free(maps->map);
    free(maps->map_object);
    free(maps);
    return 0;
}
