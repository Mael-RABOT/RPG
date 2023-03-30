/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_app.c
*/

#include "../../include/prototype.h"

/*
 *     typedef struct particle {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f position;
        int frame;
        int max_frame;
    } particle_t;
 *
 * */

void destroy_particle(app_t *app)
{
    for (int i = 0; app->particle_list[i] != NULL; i++) {
        sfTexture_destroy(app->particle_list[i]->texture);
        sfSprite_destroy(app->particle_list[i]->sprite);
        free(app->particle_list[i]);
    }
    free(app->particle_list);
}

int destroy_app(app_t *app)
{
    destroy_background(app);
    sfMusic_destroy(app->music);
    sfRenderWindow_destroy(app->window);
    destroy_particle(app);
    free(app);
    return 0;
}
