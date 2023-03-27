/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** splash_screen
*/

#include "../../include/prototype.h"

int update_ruined_back(sfRenderWindow *window, splash_screen_t *splash_screen)
{
    sfSprite_move(splash_screen->ruined_back->sprite, (sfVector2f){0.5, 0});
    sfRenderWindow_drawSprite(window, splash_screen->ruined_back->sprite, NULL);
    return 0;
}

int update_ruined_fore(sfRenderWindow *window, splash_screen_t *splash_screen)
{
    sfSprite_move(splash_screen->ruined_fore->sprite, (sfVector2f){-0.5, 0});
    sfRenderWindow_drawSprite(window, splash_screen->ruined_fore->sprite, NULL);
    return 0;
}

int splash_screen(sfRenderWindow *window, splash_screen_t *splash_screen)
{
    splash_screen->seconds = splash_screen->time.microseconds / 1000000.0;
    splash_screen->time = sfClock_getElapsedTime(splash_screen->clock);
    splash_screen->index++;
    if (splash_screen->seconds > 0.005) {
        sfClock_restart(splash_screen->clock);
        if (splash_screen->fade_index <= 255 &&
        splash_screen->index > FADE_ITERATION) {
            sfSprite_setColor(splash_screen->title->sprite,
            (sfColor){255, 255, 255, splash_screen->fade_index++});
            splash_screen->index = 0;
        }
        sfRenderWindow_drawSprite(window, splash_screen->title->sprite, NULL);
    }
    return 0;
}

// TODO : stop the shift + delay the fade in + fix fade in
