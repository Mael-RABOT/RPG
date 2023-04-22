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
    switch (app->menu->state) {
        case splash:
            splash_screen(app, app->window, app->menu->splash_screen); break;
        case main_menu:
            display_main_menu(app); break;
        case game:
            gloop(app); break;
        case settings:
            display_settings_menu(app->window, app->menu->settings); break;
        case paused:
            display_escape_menu(app, app->menu->escape); break;
        case character_stat_selection:
            character_selection(app);
            display_settings_menu(app->window, app->menu->settings); break;
    }
        return 0;
}

int gloop(app_t *app)
{
    display_background(app);
    display_map(app->window, app->maps->selected_map, app->player);
    if (app->fps->key_f == 1 && app->menu->state == game)
        show_fps(app);
    if (app->fight->is_fighting == 1)
        fight(app);
    center_view(app->view, app->player);
    return 0;
}
