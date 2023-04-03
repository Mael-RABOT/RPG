/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** clean_particle_list
*/

#include "../../include/prototype.h"

static void add_copy(particle_t **new_list, particle_t *old_particle,
    int *new_count)
{
    new_list[(*new_count)] = malloc(sizeof(particle_t));
    new_list[(*new_count)]->sprite = sfSprite_copy(old_particle->sprite);
    new_list[(*new_count)]->texture = sfTexture_copy(old_particle->texture);
    new_list[(*new_count)]->frame = old_particle->frame;
    new_list[(*new_count)]->max_frame = old_particle->max_frame;
    new_list[(*new_count)]->position = old_particle->position;
    new_list[(++(*new_count))] = NULL;
}

void clean_particle_list(app_t *app)
{
    particle_t **new_list = malloc(sizeof(particle_t*) * 100);
    int new_count = 0;
    for (int i = 0; i < app->particle_count; i++)
        if (app->particle_list[i]->frame <= app->particle_list[i]->max_frame)
            add_copy(new_list, app->particle_list[i], &new_count);
    for (int i = 0; i < app->particle_count; i++)
        free(app->particle_list[i]);
    app->particle_list = new_list;
    app->particle_count = new_count;
}
