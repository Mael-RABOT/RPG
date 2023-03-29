/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_app.c
*/

#include "../../include/prototype.h"

int destroy_app(app_t *app)
{
    sfMusic_destroy(app->music);
    sfRenderWindow_destroy(app->window);
    free(app);
    return 0;
}
