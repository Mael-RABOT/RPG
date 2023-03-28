/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_app.c
*/

#include "../../include/prototype.h"

app_t *create_app(sfVideoMode videomode)
{
    app_t *app = malloc(sizeof(app_t));
    app->videomode = (sfVideoMode){1920, 1080, 32};
    app->window = create_window(app->videomode, "my_rpg");
    app->splash_screen = create_splash_screen(app->window);
    sfRenderWindow_setFramerateLimit(app->window, 60);
    app->fps = malloc(sizeof(app_t));
    app->fps->key_f = 0;
    return app;
}
