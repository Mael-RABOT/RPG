/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** startup_sound
*/

#include "../../include/prototype.h"

int launch_startup_sound(app_t *app, int id)
{
    if (id >= app->music_handler->song_number)
        return EXIT_FAILURE;
    sfMusic_destroy(app->music_handler->music);
    app->music_handler->music = sfMusic_createFromFile(
        app->music_handler->songs[id]->path);
    if (app->music_handler->songs[id]->type == Music)
        sfMusic_setLoop(app->music_handler->music, sfTrue);
    else
        sfMusic_setLoop(app->music_handler->music, sfFalse);
    if (!app->music_handler->music)
        return EXIT_FAILURE;
    sfMusic_setVolume(app->music_handler->music, 100.0f);
    sfMusic_play(app->music_handler->music);
    if (sfMusic_getStatus(app->music_handler->music) != sfPlaying)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
