/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_game.c
*/

#include "../include/prototype.h"

int destroy_game(app_t *app)
{
    destroy_entity(app->player);
    destroy_fps(app->fps);
    destroy_maps(app->maps);
    destroy_app(app);
    return 0;
}
