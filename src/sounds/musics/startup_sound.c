/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** startup_sound
*/

#include "../../../include/prototype.h"

int launch_startup_sound(app_t *app)
{
    app->sound_buffer = sfSoundBuffer_createFromFile(INTRO_MUSIC);
    app->music = sfSound_create();
    sfSound_setBuffer(app->music, app->sound_buffer);
    sfSound_setVolume(app->music, 100);
    sfSound_play(app->music);
    sfSound_setLoop(app->music, sfTrue);
    return (EXIT_SUCCESS);
}
