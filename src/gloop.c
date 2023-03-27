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
    display_map(app->window, app->map);
    return 0;
}
