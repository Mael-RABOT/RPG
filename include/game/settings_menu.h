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
    } settings_menu_t;

#endif //SETTINGS_MENU_H_
