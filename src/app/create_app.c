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
    sfRenderWindow_setFramerateLimit(app->window, 60);
    return app;
}
