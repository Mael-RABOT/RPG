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
    free(fps);
}

void show_fps(app_t *app)
{
    sfFont *font = sfFont_createFromFile(QUICKSAND_REGULAR);
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setFillColor(text, sfGreen);
    sfText_setString(text, my_int_to_str(app->fps->fps));
    sfText_setPosition(text, (sfVector2f) {10, 10});
    sfRenderWindow_drawText(app->window, text, NULL);
    sfText_setString(text, "FPS");
    sfText_setPosition(text, (sfVector2f) {60, 10});
    sfRenderWindow_drawText(app->window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
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
