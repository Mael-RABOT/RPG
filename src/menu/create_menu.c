/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_menu.c
*/

#include "../../include/prototype.h"

int destroy_menu(app_menu_t *am)
{
    destroy_settings_menu(am->settings);
    destroy_main_menu(am->main);
    destroy_escape_menu(am->escape);
    destroy_splash_screen(am->splash_screen);
    free(am);
    return 0;
}

app_menu_t *create_menu(app_t *app)
{
    app_menu_t *menu = malloc(sizeof(app_menu_t));
    menu->splash_screen = create_splash_screen(app->window);
    menu->main = create_main_menu(app->window);
    menu->settings = create_settings_menu(app->window);
    menu->escape = create_escape_menu(app->window);
    return menu;
}
