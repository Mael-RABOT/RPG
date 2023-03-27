/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** app.h
*/

#ifndef APP_H_
    #define APP_H_

    #include "include.h"

    typedef struct app {
        sfVideoMode videomode;
        sfRenderWindow *window;
        struct splash_screen *splash_screen;
    } app_t;

#endif //APP_H_
