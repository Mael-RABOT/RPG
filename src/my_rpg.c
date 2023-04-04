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

void print_player_stat(app_t *app)
{
    my_printf("level: %d\n", app->player_stats->level);
    my_printf("hp: %d\n", app->player_stats->hp);
    my_printf("stamina: %d\n", app->player_stats->stamina);
    my_printf("strength: %d\n", app->player_stats->strength);
    my_printf("dexterity: %d\n", app->player_stats->dexterity);
    my_printf("defense: %d\n", app->player_stats->defense);
    my_printf("level_cost: %d\n", app->player_stats->level_cost);
}

int my_rpg(const int ac, const char **av)
{
    sfVideoMode videomode = {1920, 1080, 32};
    app_t *app = create_app(videomode);
    launch_startup_sound(app);
    app->view = create_view();
    app->player = create_entity("./assets/player_debug.png");
    app->maps = load_maps();
    change_map(app->maps, app->player, 0);
    app->state = game;
    while (sfRenderWindow_isOpen(app->window)) {
        sfRenderWindow_clear(app->window, sfBlack);
        choose_state(app);
        update_cursor(app);
        update_particle(app);
        sfRenderWindow_display(app->window);
        print_player_stat(app);
        sfRenderWindow_close(app->window);
    }
    destroy_game(app);
    return 0;
}
