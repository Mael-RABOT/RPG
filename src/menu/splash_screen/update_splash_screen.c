/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** update_splash_screen
*/

#include "../../../include/prototype.h"

int update_ruined_back(sfRenderWindow *window, splash_screen_t *splash_screen)
{
    sfVector2f pos = sfSprite_getPosition(splash_screen->ruined_back->sprite);

    if (pos.x < 0)
        sfSprite_move(splash_screen->ruined_back->sprite, (sfVector2f){0.5, 0});
    sfRenderWindow_drawSprite(window, splash_screen->ruined_back->sprite, NULL);
    return 0;
}

int update_ruined_fore(sfRenderWindow *window, splash_screen_t *splash_screen)
{
    sfVector2f pos = sfSprite_getPosition(splash_screen->ruined_back->sprite);

    if (pos.x < 0)
        sfSprite_move(splash_screen->ruined_fore->sprite,
        (sfVector2f){-0.5, 0});
    sfRenderWindow_drawSprite(window, splash_screen->ruined_fore->sprite, NULL);
    return 0;
}

int update_title(sfRenderWindow *window, splash_screen_t *splash_screen)
{
    sfVector2f pos = sfSprite_getPosition(splash_screen->ruined_back->sprite);

    if (pos.x > -800) {
        if (splash_screen->fade_index <= 255) {
            sfSprite_setColor(splash_screen->title->sprite,
            (sfColor){255, 255, 255, splash_screen->fade_index++});
        }
        sfRenderWindow_drawSprite(window, splash_screen->title->sprite, NULL);
    }
    return 0;
}

int update_skip(sfRenderWindow *window, splash_screen_t *splash_screen)
{
    if (splash_screen->fade_index_skip == 255)
        splash_screen->increment = -1;
    else if (splash_screen->fade_index_skip == 0)
        splash_screen->increment = 1;
    splash_screen->fade_index_skip += splash_screen->increment;
    if (splash_screen->fade_index >= 255) {
        sfSprite_setColor(splash_screen->skip->sprite,
        (sfColor){255, 255, 255, splash_screen->fade_index_skip});
        sfRenderWindow_drawSprite(window, splash_screen->skip->sprite, NULL);
    }
    return 0;
}
