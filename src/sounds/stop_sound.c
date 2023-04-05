/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** stop_sound
*/

#include "../../include/prototype.h"

void stop_sound(app_t *app)
{
    sfMusic_stop(app->music_handler->music);
}

void close_sound(app_t *app)
{
    sfMusic_destroy(app->music_handler->music);
}
