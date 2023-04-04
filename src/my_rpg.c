/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** my_rpg.c
*/

#include "../include/prototype.h"

static maps_t *load_maps(void)
{
    maps_t *maps = load_manifest("./maps/manifest");
    return maps;
}

int my_rpg(const int ac, const char **av)
{
    sfVideoMode videomode = {1920, 1080, 32};
    app_t *app = create_app(videomode);
    launch_startup_sound(app);
    app->default_view = create_view((sfVector2f){1920, 1080});
    app->view = create_view((sfVector2f){426, 240});
    app->player = create_entity("./assets/player_debug.png");
    app->maps = load_maps();
    change_map(app, app->maps, app->player, 0);
    while (sfRenderWindow_isOpen(app->window)) {
        sfRenderWindow_clear(app->window, sfBlack);
        choose_state(app);
        update_cursor(app);
        update_particle(app);
        if (app->state == game)
            sfRenderWindow_setView(app->window, app->view);
        else
            sfRenderWindow_setView(app->window, app->default_view);
        sfRenderWindow_display(app->window);
    }
    destroy_game(app);
    return 0;
}
