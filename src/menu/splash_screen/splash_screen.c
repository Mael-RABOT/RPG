/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** splash_screen
*/

#include "../../../include/prototype.h"

int skip_splash_screen(app_t *app)
{
    if (app->menu->splash_screen->fade_index >= 255) {
        app->state = main_menu;
        clean_splash_screen(app);
    }
    return 0;
}

int splash_screen(app_t *app, sfRenderWindow *window,
splash_screen_t *splash_screen)
{
    sfVector2f pos = sfSprite_getPosition(splash_screen->ruined_back->sprite);

    splash_screen->time = sfClock_getElapsedTime(splash_screen->clock);
    splash_screen->seconds = splash_screen->time.microseconds / 1000000.0;
    if (splash_screen->seconds > 0.005) {
        sfClock_restart(splash_screen->clock);
        update_ruined_back(window, splash_screen);
        update_ruined_fore(window, splash_screen);
        update_title(window, splash_screen);
        update_skip(window, splash_screen);
    }
    if (pos.x == 0) {
        app->state = main_menu;
        clean_splash_screen(app);
    }
    return 0;
}
