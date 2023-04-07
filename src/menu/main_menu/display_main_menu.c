/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** main_menu.c
*/

#include "../../../include/prototype.h"

int display_main_menu(app_t *app)
{
    if (app->menu->main->fade_index < 255) {
        sfSprite_setColor(app->menu->main->ruined_city->sprite,
        (sfColor){255, 255, 255, app->menu->main->fade_index});
        sfSprite_setColor(app->menu->main->title->sprite,
        (sfColor){255, 255, 255, app->menu->main->fade_index});
        app->menu->main->fade_index += 3;
    }
    sfRenderWindow_drawSprite(app->window, app->menu->main->ruined_city->sprite,
    NULL);
    sfRenderWindow_drawSprite(app->window, app->menu->main->title->sprite,
    NULL);
    display_button(app->window, app->menu->main->button);
    return 0;
}
