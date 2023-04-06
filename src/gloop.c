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
    main_event(app);
    switch (app->state) {
        case splash:
            splash_screen(app, app->window, app->splash_screen); break;
        case main_menu:
            display_main_menu(app);
            update_texture(app->main_menu->button, app);
            break;
        case game:
            gloop(app); break;
        case settings:
            display_settings_menu(app->window, app->settings_menu);
            update_texture(app->settings_menu->button, app);
            break;
    }
    if (app->fps->key_f == 1 && app->state == game)
        show_fps(app);
    return 0;
}

int gloop(app_t *app)
{
    display_background(app);
    display_map(app->window, app->maps->selected_map, app->player);
    center_view(app->view, app->player);
    return 0;
}
