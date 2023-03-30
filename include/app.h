/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** app.h
*/

#ifndef APP_H_
    #define APP_H_

    #include "include.h"

    typedef struct tile {
        int id;
        int collision;
        sfVector2i position;
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
    } map_t;

    typedef struct entity {
        sprite_t *sprite;
        int layer;
    } entity_t;

    typedef struct background {
        sfTexture *texture;
        sfSprite *sprite;
    } background_t;

    typedef struct app {
        int state;
        sfVideoMode videomode;
        sfRenderWindow *window;
        map_t *tutorial;
        entity_t *player;
        struct splash_screen *splash_screen;
        sfMusic *music;
        struct fps *fps;
        background_t *background;
        particle_t **particle_list;
        int particle_count;
        sfClock *particle_clock;
    } app_t;

#endif //APP_H_
