/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** startup_sound
*/

#include "../../../include/prototype.h"

int launch_startup_sound(app_t *app)
{
    app->music = sfMusic_createFromFile(INTRO_MUSIC);
    if (!app->music)
        return 1;
    sfMusic_setVolume(app->music, 100.0f);
    sfMusic_play(app->music);
    if (sfMusic_getStatus(app->music) != sfPlaying) {
        return 1;
    }
    return (EXIT_SUCCESS);
}
