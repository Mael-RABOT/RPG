/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** menu.h
*/

#include "../prototype.h"

#ifndef MENU_H_
    #define MENU_H_

    typedef struct splash_screen {
        sprite_t *ruined_back;
        sprite_t *ruined_fore;
        sprite_t *title;
        sprite_t *skip;
        int fade_index;
        int fade_index_skip;
        int increment;
        sfClock *clock;
        sfTime time;
        float seconds;
    } splash_screen_t;

    typedef struct settings_menu {
        sprite_t *background;
        sprite_t *text_sounds;
        sprite_t *text_resolution;
        sprite_t *sounds;
        sprite_t *music;
        button_t **button;
    } settings_menu_t;

    typedef struct main_menu {
        button_t **button;
        sprite_t *ruined_city;
        sprite_t *title;
        int fade_index;
    } main_menu_t;

    typedef struct escape_menu {
        button_t **button;
    } escape_menu_t;

#endif //MENU_H_
