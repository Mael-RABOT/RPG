/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_splash_screen
*/

#include "../../../include/prototype.h"

int free_splash_screen(app_t *app)
{
    free(app->splash_screen->ruined_back);
    free(app->splash_screen->ruined_fore);
    free(app->splash_screen->title);
    free(app->splash_screen->skip);
    free(app->splash_screen);
    return 0;
}

int destroy_splash_screen(splash_screen_t *splash_screen)
{
    sfSprite_destroy(splash_screen->ruined_back->sprite);
    sfSprite_destroy(splash_screen->ruined_fore->sprite);
    sfSprite_destroy(splash_screen->title->sprite);
    sfSprite_destroy(splash_screen->skip->sprite);
    sfTexture_destroy(splash_screen->ruined_back->texture);
    sfTexture_destroy(splash_screen->ruined_fore->texture);
    sfTexture_destroy(splash_screen->title->texture);
    sfTexture_destroy(splash_screen->skip->texture);
    sfClock_destroy(splash_screen->clock);
    return 0;
}

int clean_splash_screen(app_t *app)
{
    destroy_splash_screen(app->splash_screen);
    free_splash_screen(app);
    return 0;
}
