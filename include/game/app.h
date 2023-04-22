/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** app.h
*/

#include "../include.h"

#ifndef APP_H_
    #define APP_H_

    typedef struct app_menu {
        main_menu_t *main;
        settings_menu_t *settings;
        escape_menu_t *escape;
        splash_screen_t *splash_screen;
        int state;
        int old_state;
    } app_menu_t;

    typedef struct fight {
        int is_fighting;
        int fight_tick;
        sfClock *clock;
        int no_round;
    } fight_t;

    typedef struct app {
        sfVideoMode videomode;
        sfRenderWindow *window;
        maps_t *maps;
        app_menu_t *menu;
        music_t *music_handler;
        sprite_t *background;
        sprite_t *cursor;
        fps_t *fps;
        sfView *default_view;
        sfView *view;
        particle_t **particle_list;
        int particle_count;
        sfClock *particle_clock;
        entity_t *player;
        weapon_t **weapons_list;
        int weapons_count;
        fight_t *fight;
    } app_t;

#endif //APP_H_
