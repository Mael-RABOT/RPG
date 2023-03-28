/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** gloop.c
*/

#include "../include/prototype.h"

int gloop(app_t *app)
{
    main_event(app);
    switch (app->state) {
        case splash:
            splash_screen(app, app->window, app->splash_screen);
            break;
        case main_menu:
            display_main_menu(app);
            break;
        case game:
            display_map(app->window, app->map);
            break;
    }
    return 0;
}
