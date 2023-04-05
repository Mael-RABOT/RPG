/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** app.h
*/

#ifndef APP_H_
    #define APP_H_

    #include "../include.h"

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

    typedef struct entity {
        sprite_t *sprite;
        sfVector2f position;
        sfIntRect texture_rect;
        int layer;
    } entity_t;

    typedef struct app {
        int state;
        sfVideoMode videomode;
        sfRenderWindow *window;
        maps_t *maps;
        entity_t *player;
        struct splash_screen *splash_screen;
        music_t *music_handler;
        sprite_t *background;
        sprite_t *cursor;
        fps_t *fps;
        sfView *default_view;
        sfView *view;
        particle_t **particle_list;
        int particle_count;
        sfClock *particle_clock;
        struct main_menu *main_menu;
        player_t *player_stats;
    } app_t;

#endif //APP_H_
