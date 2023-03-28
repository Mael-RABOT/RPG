/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** my_rpg.c
*/

#include "../include/prototype.h"

int my_rpg(const int ac, const char **av)
{
    sfVideoMode videomode = {1920, 1080, 32};
    app_t *app = create_app(videomode);
    app->manifest = load_manifest("./maps/manifest");
    app->map = load_map_from_file("./maps/Tutorial_Ground.csv", app->manifest);
    while (sfRenderWindow_isOpen(app->window)) {
        sfRenderWindow_clear(app->window, sfBlack);
        if (app->state == splash)
            splash_screen(app, app->window, app->splash_screen);
        else
            gloop(app);
        sfRenderWindow_display(app->window);
    }
    destroy_app(app);
    return 0;
}
