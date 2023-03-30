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
    launch_startup_sound(app);
    app->player = create_player("./assets/player_debug.png");
    app->tutorial = load_manifest("./maps/manifest", app->player);
    while (sfRenderWindow_isOpen(app->window)) {
        sfRenderWindow_clear(app->window, sfBlack);
        choose_state(app);
        launch_cinematic(app, Tutorial_door);
        launch_cinematic(app, Death);
        sfRenderWindow_display(app->window);
    }
    destroy_app(app);
    return 0;
}
