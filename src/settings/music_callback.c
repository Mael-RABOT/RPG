/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** musiccallback.c
*/

#include "../../include/prototype.h"

void increase_music_volume(app_t *app)
{
    float volume = sfMusic_getVolume(app->music);

    volume += 5;
    if (volume < 0.0f)
        volume = 0.0f;
    if (volume > 100.0f)
        volume = 100.0f;
    sfMusic_setVolume(app->music, volume);
    app->settings_menu->music_more->state = NONE;
    app->settings_menu->music_less->state = NONE;
    return;
}

void decrease_music_volume(app_t *app)
{
    float volume = sfMusic_getVolume(app->music);

    volume -= 5;
    if (volume < 0.0f)
        volume = 0.0f;
    if (volume > 100.0f)
        volume = 100.0f;
    sfMusic_setVolume(app->music, volume);
    app->settings_menu->music_more->state = NONE;
    app->settings_menu->music_less->state = NONE;
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
    app->settings_menu->sounds_more->state = NONE;
    app->settings_menu->sounds_less->state = NONE;
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
    app->settings_menu->sounds_more->state = NONE;
    app->settings_menu->sounds_less->state = NONE;
    return;
}
