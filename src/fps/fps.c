/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** fps
*/

#include "../../include/prototype.h"

void destroy_fps(fps_t *fps)
{
    sfClock_destroy(fps->clock);
    sfText_destroy(fps->text);
    sfFont_destroy(fps->font);
    free(fps);
}

void show_fps(app_t *app)
{
    sfVector2f position = sfView_getCenter(app->view);
    sfVector2f size = sfView_getSize(app->view);
    position.x -= (size.x / 2) - 5;
    position.y -= (size.y / 2) - 5;
    sfText_setPosition(app->fps->text, position);
    sfText_setScale(app->fps->text, (sfVector2f){0.3, 0.3});
    sfText_setCharacterSize(app->fps->text, 10);
    sfText_setFillColor(app->fps->text, sfGreen);
    sfText_setString(app->fps->text, my_int_to_str(app->fps->fps));
    sfRenderWindow_drawText(app->window, app->fps->text, NULL);
    position.x += 5;
    sfText_setPosition(app->fps->text, position);
    sfText_setString(app->fps->text, "FPS");
    if (app->state == game)
        sfRenderWindow_drawText(app->window, app->fps->text, NULL);
}

void get_fps(app_t *app)
{
    static int first = 1;
    static int fps = 0;

    if (first == 1) {
        app->fps->clock = sfClock_create();
        first = 0;
    }
    if (sfClock_getElapsedTime(app->fps->clock).microseconds / 1000000.0 >= 1) {
        app->fps->fps = fps;
        fps = 0;
        sfClock_restart(app->fps->clock);
    } else
        fps++;
}
