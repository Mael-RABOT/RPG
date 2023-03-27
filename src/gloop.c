/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** gloop.c
*/

#include "../include/prototype.h"

int gloop(app_t *app)
{
    app->state = splash;
    if (app->state == splash)
        splash_screen(app->window, app->splash_screen);
    main_event(app);
    return 0;
}
