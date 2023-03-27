/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** splash_screen
*/

#include "../../include/prototype.h"

int splash_screen(sfRenderWindow *window, splash_screen_t *splash_screen)
{
    splash_screen->seconds = splash_screen->time.microseconds / 1000000.0;
    splash_screen->time = sfClock_getElapsedTime(splash_screen->clock);
    if (splash_screen->seconds > 0.005) {
        sfClock_restart(splash_screen->clock);
        sfSprite_move(splash_screen->ruined_back->sprite, (sfVector2f){1, 0});
        sfSprite_move(splash_screen->ruined_fore->sprite, (sfVector2f){-1, 0});
        sfRenderWindow_drawSprite(window, splash_screen->ruined_back->sprite,
        NULL);
        sfRenderWindow_drawSprite(window, splash_screen->ruined_fore->sprite,
        NULL);
    }
    return 0;
}
