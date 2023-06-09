/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_app.c
*/

#include "../../include/prototype.h"

void destroy_particle(app_t *app)
{
    free(app->particle_list);
}

int destroy_app(app_t *app)
{
    destroy_menu(app->menu);
    destroy_background(app);
    sfRenderWindow_destroy(app->window);
    destroy_sprite(app->cursor);
    destroy_particle(app);
    sfView_destroy(app->view);
    sfView_destroy(app->default_view);
    free(app);
    return 0;
}
