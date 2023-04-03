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
    app->videomode = (sfVideoMode){1920, 1080, 32};
    app->window = create_window(app->videomode, "my_rpg");
    app->state = DEFAULT_GAME_STATE;
    app->splash_screen = create_splash_screen(app->window);
    sfRenderWindow_setFramerateLimit(app->window, 60);
    app->fps = create_fps_counter();
    app->background = init_background();
    create_cursor(app);
    app->particle_count = 0;
    app->particle_list = init_particle_list();
    app->particle_clock = sfClock_create();
    return app;
}
