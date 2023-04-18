/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** map.h
*/

#include "../prototype.h"

#ifndef MAP_H_
    #define MAP_H_

    typedef struct teleport {
        char *name;
    } teleport_t;

    typedef struct tile {
        int id;
        block_t state;
        teleport_t *teleport;
        sfVector2f position;
        sfTexture *texture;
        sfSprite *tile;
    } tile_t;

    typedef struct layer {
        int id;
        char *pathfile;
        sfVector2f size;
        tile_t ***layer;
    } layer_t;

    typedef struct map_object {
        int id;
        char *path;
        block_t state;
        sfTexture *texture;
    } map_object_t;

    typedef struct map {
        layer_t **layer;
        char *name;
        char *path;
        sfVector2f size;
        sfVector2f spawn;
    } map_t;

    typedef struct maps {
        map_t **map;
        map_object_t **map_object;
        map_t *selected_map;
    } maps_t;

#endif //MAP_H_
