/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** add_particle
*/

#include "../../include/prototype.h"
//particle->position = (sfVector2f){((position.x - position.y) * 32 / 2) +
//    size.x * 32, ((position.x + position.y) * 32 / 4)};
// UPDATE THE particle->position WITH IT'S ISOMETRIC POSITION
static particle_t *create_particle(sfVector2f position, char* filepath,
    sfBool isometric)
{
    particle_t *particle = malloc(sizeof(particle_t));
    particle->frame = 1;
    if (isometric == sfFalse)
        particle->position = position;
    else
        particle->position = position;
    particle->texture = sfTexture_createFromFile(filepath, sfFalse);
    particle->sprite = sfSprite_create();
    particle->max_frame = sfTexture_getSize(particle->texture).x / 32;
    sfSprite_setTexture(particle->sprite, particle->texture, sfFalse);
    sfSprite_setTextureRect(particle->sprite,
        (sfIntRect){0, 0, 32 * particle->frame, 32});
    sfSprite_setPosition(particle->sprite, particle->position);
    return (particle);
}

void add_particle(app_t *app, sfVector2f position, char* filepath,
    sfBool isometric)
{
    app->particle_list[app->particle_count++] =
        create_particle(position, filepath, isometric);
    app->particle_list[app->particle_count] = NULL;
}
