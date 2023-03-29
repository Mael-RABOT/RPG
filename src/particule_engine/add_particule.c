/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** add_particule
*/

#include "../../include/prototype.h"

particle_t *add_particle(app_t *app, sfVector2f position)
{
    sfVector2f real_position = {((position.x - position.y) * 32 / 2) +
    size.x * 32, ((position.x + position.y) * 32 / 4)};
}
