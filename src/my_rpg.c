/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** my_rpg.c
*/

#include "../include/prototype.h"

static int create_player(app_t *app)
{
    app->player = create_entity("./assets/player_debug.png");
        return 0;
}

static int create_player_view(app_t *app)
{
    return 0;
}

static maps_t *load_maps(void)
{
    maps_t *maps = load_manifest("./maps/manifest");
    maps->selected_map = maps->map[0];
    return maps;
}

int my_rpg(const int ac, const char **av)
{
    sfBool is_dead = sfFalse;
    sfVideoMode videomode = {1920, 1080, 32};
    app_t *app = create_app(videomode);
    launch_startup_sound(app);
    create_player(app);
    app->maps = load_maps();
    app->state = game;
    while (sfRenderWindow_isOpen(app->window)) {
        sfRenderWindow_clear(app->window, sfBlack);
        if (is_dead)
            launch_cinematic(app, Death);
        choose_state(app);
        update_cursor(app);
        sfRenderWindow_display(app->window);
    }
    destroy_game(app);
    return 0;
}
