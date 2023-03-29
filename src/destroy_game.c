/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_game.c
*/

#include "../include/prototype.h"

int destroy_game(app_t *app)
{
    destroy_app(app);
    destroy_entity(app->player);
    destroy_map(app->tutorial);
    //sfMusic_destroy(app->music);
    free(app);
    return 0;
}
