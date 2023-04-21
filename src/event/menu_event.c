/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** menu_event.c
*/

#include "../../include/prototype.h"

int menu_event(app_t *app, sfEvent event)
{
    if (app->menu->state == main_menu)
        button_event(app, app->menu->main->button, event);
    if (app->menu->state == settings)
        button_event(app, app->menu->settings->button, event);
    if (app->menu->state == paused)
        button_event(app, app->menu->escape->button, event);
    return 0;
}
