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

    typedef struct map {
        tile_t ***map;
    } map_t;

    typedef struct manifest {
        int id;
        char *path;
        sfTexture *texture;
        int collision;
        struct manifest *next_object;
    } manifest_t;

typedef enum state {
        splash = 0,
        main_menu,
        settings,
        pause_menu,
        game,
        cinematics
    } state_t;

    typedef struct app {
        sfVideoMode videomode;
        sfRenderWindow *window;
        manifest_t *manifest;
        map_t *map;
        state_t state;
        struct splash_screen *splash_screen;
        sfSoundBuffer *sound_buffer;
        sfSound *music;
    } app_t;

#endif //APP_H_
