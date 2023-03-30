/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** gloop.c
*/

#include "../include/prototype.h"

int choose_state(app_t *app)
{
    get_fps(app);
    if (app->fps->key_f == 1)
        show_fps(app);
    main_event(app);
    switch (app->state) {
        case splash:
            splash_screen(app, app->window, app->splash_screen); break;
        case game:
            gloop(app); break;
    }
    return 0;
}

int gloop(app_t *app)
{
    display_background(app);
    display_map(app->window, app->tutorial, app->player);
    update_particle(app);
    return 0;
}
