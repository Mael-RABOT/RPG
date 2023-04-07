/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** main_menu.c
*/

#include "../../include/prototype.h"

int display_main_menu(app_t *app)
{
    if (app->main_menu->fade_index < 255) {
        sfSprite_setColor(app->main_menu->ruined_city->sprite,
        (sfColor){255, 255, 255, app->main_menu->fade_index});
        sfSprite_setColor(app->main_menu->title->sprite,
        (sfColor){255, 255, 255, app->main_menu->fade_index});
        app->main_menu->fade_index += 3;
    }
    sfRenderWindow_drawSprite(app->window, app->main_menu->ruined_city->sprite,
    NULL);
    sfRenderWindow_drawSprite(app->window, app->main_menu->title->sprite,
    NULL);
    display_button(app->window, app->main_menu->button);
    //launch_sound(app, 0);
    return 0;
}
