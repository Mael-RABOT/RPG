/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** app.h
*/

#ifndef APP_H_
    #define APP_H_

    #include "prototype.h"

    typedef struct tile {
        int id;
        int collision;
        sfVector2i position;
        sfTexture *texture;
        sfSprite *tile;
    } tile_t;

    typedef struct layer {
        tile_t ***layer;
    } layer_t;

    typedef struct map_object {
        int id;
        char *path;
        int collision;
        sfTexture *texture;
    } map_object_t;

    typedef struct map {
        map_object_t **map_object;
        layer_t **layer;
    } map_t;

    typedef struct app {
        sfVideoMode videomode;
        sfRenderWindow *window;
        map_t *tutorial;
        state_t state;
        struct splash_screen *splash_screen;
    } app_t;

#endif //APP_H_
