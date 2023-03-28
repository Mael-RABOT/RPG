/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** main_menu
*/

#ifndef MAIN_MENU_H_
    #define MAIN_MENU_H_

    #include "include.h"

    typedef struct ruined_city {
        sfSprite *sprite;
        sfTexture *texture;
    } ruined_city_t;

    typedef struct main_menu {
        button_t *play;
        button_t *resume;
        button_t *settings;
        button_t *quit;
        ruined_city_t *ruined_city;
        title_t *title;
        int fade_index;
    } main_menu_t;

#endif //MAIN_MENU_H_
