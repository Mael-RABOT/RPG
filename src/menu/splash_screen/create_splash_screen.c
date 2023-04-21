/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_splash_screen
*/

#include "../../../include/prototype.h"

static sprite_t *create_title(sfRenderWindow *window)
{
    sprite_t *title = create_sprite(TITLE);
    sfVector2u window_size = sfRenderWindow_getSize(window);

    sfSprite_setPosition(title->sprite,
    (sfVector2f){((float)window_size.x - (float)window_size.x / 2) / 2,
    ((float)window_size.y - (float)window_size.y / 2) / 2});
    return title;
}

static sprite_t *create_ruined_fore(void)
{
    sprite_t *ruined_fore = create_sprite(RUINED_FORE);
    sfSprite_setPosition(ruined_fore->sprite, (sfVector2f){0, 0});
    return ruined_fore;
}

static sprite_t *create_ruined_back(sfRenderWindow *window)
{
    sprite_t *ruined_back = create_sprite(RUINED_BACK);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfSprite_setPosition(ruined_back->sprite,
    (sfVector2f){(float)window_size.x - RUINED_BACK_WIDTH, 0});
    return ruined_back;
}

static sprite_t *create_skip(sfRenderWindow *window)
{
    sprite_t *skip = create_sprite(SKIP);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfSprite_setPosition(skip->sprite,
    (sfVector2f){window_size.x / 2 - SKIP_WIDTH / 2, window_size.y - 200});
    return skip;
}

splash_screen_t *create_splash_screen(sfRenderWindow *window)
{
    splash_screen_t *splash_screen = malloc(sizeof(splash_screen_t));

    splash_screen->ruined_back = create_ruined_back(window);
    splash_screen->ruined_fore = create_ruined_fore();
    splash_screen->title = create_title(window);
    splash_screen->skip = create_skip(window);
    splash_screen->clock = sfClock_create();
    splash_screen->seconds = 1.0;
    splash_screen->fade_index = 0;
    splash_screen->fade_index_skip = 0;
    splash_screen->increment = 1;
    return splash_screen;
}
