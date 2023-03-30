/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** clean_particle_list
*/

#include "../../include/prototype.h"

static void copy_list(app_t *app, particle_t **tmp_list, int *count)
{
    for (int i = 0; i < app->particle_count; i++) {
        if (app->particle_list[i]->frame >= app->particle_list[i]->max_frame) {
            tmp_list[*count] = malloc(sizeof(particle_t));
            *tmp_list[*count] = *app->particle_list[i];
            tmp_list[*count]->sprite =
                sfSprite_copy(app->particle_list[i]->sprite);
            tmp_list[*count]->texture =
                sfTexture_copy(app->particle_list[i]->texture);
            (*count)++;
        } else {
            sfSprite_destroy(app->particle_list[i]->sprite);
            sfTexture_destroy(app->particle_list[i]->texture);
            free(app->particle_list[i]);
        }
    }
}

void clean_particle_list(app_t *app)
{
    particle_t **tmp_list = malloc(sizeof(particle_t*) * app->particle_count);
    int count = 0;
    copy_list(app, tmp_list, &count);
    free(app->particle_list);
    app->particle_list = tmp_list;
    app->particle_count = count;
    for (int i = 0; i < count; i++) {
        sfSprite_destroy(tmp_list[i]->sprite);
        sfTexture_destroy(tmp_list[i]->texture);
        free(tmp_list[i]);
    }
    free(tmp_list);
}
