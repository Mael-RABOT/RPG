/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** main_menu
*/

#include "../prototype.h"

#ifndef MAIN_MENU_H_
    #define MAIN_MENU_H_

    typedef struct main_menu {
        button_t *button;
        sprite_t *ruined_city;
        sprite_t *title;
        int fade_index;
    } main_menu_t;

#endif //MAIN_MENU_H_
