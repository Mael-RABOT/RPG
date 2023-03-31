/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** app.h
*/

#ifndef APP_H_
    #define APP_H_

    #include "../include.h"

    typedef struct tile {
        int id;
        int collision;
        sfVector2f position;
        sfTexture *texture;
        sfSprite *tile;
    } tile_t;

    typedef struct layer {
        int id;
        char *filepath;
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
        sfVector2f size;
    } map_t;

    typedef struct entity {
        sprite_t *sprite;
        sfVector2f position;
        int layer;
    } entity_t;

    typedef struct app {
        int state;
        sfVideoMode videomode;
        sfRenderWindow *window;
        map_t *tutorial;
        entity_t *player;
        struct splash_screen *splash_screen;
        sfMusic *music;
        fps_t *fps;
        sfView *view;
    } app_t;

#endif //APP_H_
