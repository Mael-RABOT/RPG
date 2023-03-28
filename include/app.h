/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** app.h
*/

#ifndef APP_H_
    #define APP_H_

    #include "include.h"

    typedef enum state {
        splash = 0,
        main_menu,
        settings,
        pause_menu,
        game,
        cinematics
    } state_t;

    typedef struct app {
        state_t state;
        sfVideoMode videomode;
        sfRenderWindow *window;
        struct splash_screen *splash_screen;
        struct fps *fps;
    } app_t;

#endif //APP_H_
