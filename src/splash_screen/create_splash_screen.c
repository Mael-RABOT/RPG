/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_splash_screen
*/

#include "../../include/prototype.h"

static sprite_t *create_title(sfRenderWindow *window)
{
    sprite_t *title = create_sprite(TITLE);
    sfVector2u window_size = sfRenderWindow_getSize(window);

    sfSprite_setPosition(title->sprite,
    (sfVector2f){((float)window_size.x - (float)window_size.x / 2) / 2,
    ((float)window_size.y - (float)window_size.y / 2) / 2});
    return title;
}

ruined_fore_t *create_ruined_fore(void)
{
    ruined_fore_t *ruined_fore = malloc(sizeof(ruined_fore_t));

    ruined_fore->sprite = sfSprite_create();
    ruined_fore->texture = sfTexture_createFromFile(RUINED_FORE, NULL);
    sfSprite_setTexture(ruined_fore->sprite, ruined_fore->texture, sfTrue);
    sfSprite_setPosition(ruined_fore->sprite, (sfVector2f){0, 0});
    return ruined_fore;
}

ruined_back_t *create_ruined_back(sfRenderWindow *window)
{
    ruined_back_t *ruined_back = malloc(sizeof(ruined_back_t));
    sfVector2u window_size = sfRenderWindow_getSize(window);

    ruined_back->sprite = sfSprite_create();
    ruined_back->texture = sfTexture_createFromFile(RUINED_BACK, NULL);
    sfSprite_setTexture(ruined_back->sprite, ruined_back->texture, sfTrue);
    sfSprite_setPosition(ruined_back->sprite,
    (sfVector2f){(float)window_size.x - RUINED_BACK_WIDTH, 0});
    return ruined_back;
}

skip_t *create_skip(sfRenderWindow *window)
{
    skip_t *skip = malloc(sizeof(skip_t));
    sfVector2u window_size = sfRenderWindow_getSize(window);

    skip->sprite = sfSprite_create();
    skip->texture = sfTexture_createFromFile(SKIP, NULL);
    sfSprite_setTexture(skip->sprite, skip->texture, sfTrue);
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
