/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** musiccallback.c
*/

#include "../../include/prototype.h"

void increase_music_volume(app_t *app)
{
    float volume = sfMusic_getVolume(app->music_handler->music);

    volume += 5;
    if (volume < 0.0f)
        volume = 0.0f;
    if (volume > 100.0f)
        volume = 100.0f;
    sfMusic_setVolume(app->music_handler->music, volume);
    return;
}

void decrease_music_volume(app_t *app)
{
    float volume = sfMusic_getVolume(app->music_handler->music);

    volume -= 5;
    if (volume < 0.0f)
        volume = 0.0f;
    if (volume > 100.0f)
        volume = 100.0f;
    sfMusic_setVolume(app->music_handler->music, volume);
    return;
}

void increase_global_volume(app_t *app)
{
    float volume = sfListener_getGlobalVolume();

    volume += 5;
    if (volume < 0.0f)
        volume = 0.0f;
    if (volume > 100.0f)
        volume = 100.0f;
    sfListener_setGlobalVolume(volume);
    return;
}

void decrease_global_volume(app_t *app)
{
    float volume = sfListener_getGlobalVolume();

    volume -= 5;
    if (volume < 0.0f)
        volume = 0.0f;
    if (volume > 100.0f)
        volume = 100.0f;
    sfListener_setGlobalVolume(volume);
    return;
}
