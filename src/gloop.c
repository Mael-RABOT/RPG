/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** gloop.c
*/

#include "../include/prototype.h"

int gloop(app_t *app)
{
    get_fps(app);
    if (app->fps->key_f == 1)
        show_fps(app);
    main_event(app);
    return 0;
}
