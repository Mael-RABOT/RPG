/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** settings_menu
*/

#ifndef SETTINGS_MENU_H_
    #define SETTINGS_MNU_H_

    #include "../include.h"

    typedef struct settings_menu {
        sprite_t *background;
        sprite_t *text_sounds;
        sprite_t *text_resolution;
        sprite_t *sounds;
        sprite_t *music;
        button_t *button;

        button_t *sounds_more;
        button_t *sounds_less;
        button_t *music_more;
        button_t *music_less;
        button_t *full_screen;
        button_t *windowded;
        button_t *low_resolution;
        button_t *high_resolution;
    } settings_menu_t;

#endif //SETTINGS_MENU_H_
