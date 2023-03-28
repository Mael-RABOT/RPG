/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_sounds
*/

#include "../../include/prototype.h"

void destroy_sounds(app_t *app)
{
    sfSoundBuffer_destroy(app->sound_buffer);
    sfSound_destroy(app->music);
}
