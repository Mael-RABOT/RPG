/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** startup_sound
*/

#include "../../../include/prototype.h"

int launch_startup_sound(app_t *app)
{
    /*app->sound_buffer = sfSoundBuffer_createFromFile(INTRO_MUSIC);
    app->music = sfSound_create();
    sfSound_setBuffer(app->music, app->sound_buffer);
    sfSound_setVolume(app->music, 100);
    sfSound_play(app->music);
    sfSound_setLoop(app->music, sfTrue);*/
    sfMusic *music = sfMusic_createFromFile(INTRO_MUSIC);
    if (!music) {
        printf("ERROR\n");
        return 1;
    }
    sfMusic_setVolume(music, 100.0f);
    sfMusic_play(music);
    if (sfMusic_getStatus(music) != sfPlaying)
    {
        printf("Failed to play music\n");
        sfMusic_destroy(music);
        return 1;
    }
    return (EXIT_SUCCESS);
}
