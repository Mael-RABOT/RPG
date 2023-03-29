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
    free(tile);
    return 0;
}

int destroy_layer(layer_t *layer)
{
    free(layer->filepath);
    int i = 0;
    while (layer->layer[i] != NULL) {
        int j = 0;
        while (layer->layer[i][j] != NULL) {
            destroy_tile(layer->layer[i][j]);
            j += 1;
        }
        i += 1;
    }
    free(layer);
    return 0;
}

int destroy_map(map_t *map)
{
    int i = 0;
    while (map->map_object[i] != NULL) {
        destroy_object(map->map_object[i]);
        i += 1;
    }
    i = 0;
    while (map->layer[i] != NULL) {
        destroy_layer(map->layer[i]);
        i += 1;
    }
    free(map->layer);
    free(map->map_object);
    free(map);
    return 0;
}
