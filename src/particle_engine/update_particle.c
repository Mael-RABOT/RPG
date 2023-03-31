/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** update_particle
*/

#include "../../include/prototype.h"

void update_particle(app_t *app)
{
    double time = sfClock_getElapsedTime(
        app->particle_clock).microseconds / TIME_DIVIDER;
    if (time < 0.7) {
        for (int i = 0; i < app->particle_count; i++)
            sfRenderWindow_drawSprite(app->window,
                app->particle_list[i]->sprite, NULL);
        return;
    }
    for (int i = 0; i < app->particle_count; i++) {
        if (app->particle_list[i]->frame <= app->particle_list[i]->max_frame) {
            sfSprite_setTextureRect(app->particle_list[i]->sprite,
                (sfIntRect) {32 * app->particle_list[i]->frame++, 0, 32, 32});
            sfRenderWindow_drawSprite(app->window,
                app->particle_list[i]->sprite, NULL);
        }
    }
    sfClock_restart(app->particle_clock);
}
