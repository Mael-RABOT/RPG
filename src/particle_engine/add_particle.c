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
static particle_t *init_particle(sfVector2f position, sfBool isometric)
{
    particle_t *particle = malloc(sizeof(particle_t));
    particle->frame = 1;
    if (isometric == sfFalse)
        particle->position = position;
    else
        particle->position = position;
    return (particle);
}

static void add_particle_data(particle_t **particle, char *filepath)
{
    (*particle)->texture = sfTexture_createFromFile(filepath, sfFalse);
    (*particle)->max_frame = sfTexture_getSize((*particle)->texture).x / 32;
    (*particle)->sprite = sfSprite_create();
    sfSprite_setTexture((*particle)->sprite, (*particle)->texture, sfFalse);
    sfSprite_setTextureRect((*particle)->sprite,
        (sfIntRect){0, 0, 32 * (*particle)->frame, 32});
    sfSprite_setPosition((*particle)->sprite, (*particle)->position);
}

void add_particle(app_t *app, sfVector2f position, char* filepath,
    sfBool isometric)
{
    app->particle_list[app->particle_count] =
        init_particle(position, isometric);
    add_particle_data(&(app->particle_list[app->particle_count++]), filepath);
    app->particle_list[app->particle_count] = NULL;
}
