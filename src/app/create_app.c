/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_app.c
*/

#include "../../include/prototype.h"

fps_t *create_fps_counter(void)
{
    fps_t *fps = malloc(sizeof(fps_t));
    fps->key_f = SHOW_FPS_DEFAULT;
    fps->fps = 0;
    fps->font = sfFont_createFromFile(FFFFORWA);
    fps->text = sfText_create();
    sfText_setFont(fps->text, fps->font);
    return fps;
}

particle_t **init_particle_list(void)
{
    particle_t **list = malloc(sizeof(particle_t *) * 100);
    list[0] = NULL;
    return (list);
}

app_t *create_app(sfVideoMode videomode)
{
    app_t *app = malloc(sizeof(app_t));
    create_weapons_list(app);
    app->videomode = videomode;
    app->window = create_window(app->videomode, "my_rpg");
    sfRenderWindow_setFramerateLimit(app->window, 60);
    app->fps = create_fps_counter();
    app->background = create_sprite(NIGHT_SKY);
    create_cursor(app);
    app->particle_count = 0;
    app->particle_list = init_particle_list();
    app->particle_clock = sfClock_create();
    create_music_handler(app);
    app->menu = create_menu(app);
    app->menu->state = DEFAULT_GAME_STATE;
    app->fight = create_fight();
    create_ui(app);
    return app;
}
