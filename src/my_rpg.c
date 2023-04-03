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
    sfVector2f position = sfSprite_getPosition(app->player->sprite->sprite);
    app->view = create_view(position, app->tutorial->size);
    sfRenderWindow_setView(app->window, app->view);
    return 0;
}

static map_t **load_maps(void)
{
    map_t **map = malloc(sizeof(map_t *) * 4);
    map[tutorial] = load_manifest("./maps/Tutorial/manifest");
    map[hub] = load_manifest("./maps/Hub/manifest");
    map[maze] = load_manifest("./maps/maze/manifest");
    return map;
}

int my_rpg(const int ac, const char **av)
{
    sfBool is_dead = sfFalse;
    sfVideoMode videomode = {1920, 1080, 32};
    app_t *app = create_app(videomode);
    launch_startup_sound(app);
    create_player(app);
    app->tutorial = load_manifest("./maps/maze/manifest", app->player);
    create_player_view(app);
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
