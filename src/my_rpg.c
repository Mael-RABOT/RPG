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

static int chose_view(app_t *app)
{
    if (app->menu->state == game)
        sfRenderWindow_setView(app->window, app->view);
    else
        sfRenderWindow_setView(app->window, app->default_view);
    return 0;
}

static int main_display(app_t *app)
{
    chose_view(app);
    sfRenderWindow_clear(app->window, sfBlack);
    choose_state(app);
    update_cursor(app);
    update_particle(app);
    sfRenderWindow_display(app->window);
    return 0;
}

int my_rpg(const int ac, const char **av)
{
    sfVideoMode videomode = {1920, 1080, 32};
    app_t *app = create_app(videomode);
    app->default_view = create_view((sfVector2f){1920, 1080});
    app->view = create_view((sfVector2f){426, 240});
    app->player = create_entity(app, "./assets/characters/player_debug.png",
        Default, Fist);
    app->maps = load_maps();
    change_map(app, app->maps, app->player, 0);
    while (sfRenderWindow_isOpen(app->window)) {
        main_display(app);
    }
    destroy_game(app);
    return 0;
}
