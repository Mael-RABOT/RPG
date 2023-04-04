/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** display_settings_menu
*/

#include "../../include/prototype.h"


void update_settings_menu(settings_menu_t *settings_menu, sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    float half = window_size.x / 2;
    float quarter = window_size.x / 4;

    sfSprite_setScale(settings_menu->text_sounds->sprite, (sfVector2f){5, 5});
    sfSprite_setPosition(settings_menu->text_sounds->sprite, (sfVector2f){half - quarter - TITLE_WIDTH / 2, 120});
    sfSprite_setPosition(settings_menu->text_resolution->sprite, (sfVector2f){half + quarter - TITLE_WIDTH / 2, 120});
    sfSprite_setScale(settings_menu->text_resolution->sprite, (sfVector2f){5, 5});
    sfSprite_setScale(settings_menu->sounds->sprite, (sfVector2f){3, 3});
    sfSprite_setPosition(settings_menu->sounds->sprite, (sfVector2f){half - quarter - TEXT_BUTTON_WIDTH / 2, 420});
    sfSprite_setScale(settings_menu->music->sprite, (sfVector2f){3, 3});
    sfSprite_setPosition(settings_menu->music->sprite, (sfVector2f){half - quarter - TEXT_BUTTON_WIDTH / 2, 610});
    return;
}

void display_settings_menu(app_t *app)
{
    sfRenderWindow_drawSprite(app->window, app->settings_menu->background->sprite, NULL);
    sfRenderWindow_drawSprite(app->window, app->settings_menu->text_sounds->sprite, NULL);
    sfRenderWindow_drawSprite(app->window, app->settings_menu->text_resolution->sprite, NULL);
    sfRenderWindow_drawSprite(app->window, app->settings_menu->sounds->sprite, NULL);
    sfRenderWindow_drawSprite(app->window, app->settings_menu->music->sprite, NULL);
    sfRenderWindow_drawRectangleShape(app->window, app->settings_menu->sounds_more->rect, NULL);
    sfRenderWindow_drawRectangleShape(app->window, app->settings_menu->sounds_less->rect, NULL);
    sfRenderWindow_drawRectangleShape(app->window, app->settings_menu->music_more->rect, NULL);
    sfRenderWindow_drawRectangleShape(app->window, app->settings_menu->music_less->rect, NULL);
    sfRenderWindow_drawRectangleShape(app->window, app->settings_menu->full_screen->rect, NULL);
    sfRenderWindow_drawRectangleShape(app->window, app->settings_menu->windowded->rect, NULL);
    //sfRenderWindow_drawRectangleShape(app->window, app->settings_menu->low_resolution->rect, NULL);
    //sfRenderWindow_drawRectangleShape(app->window, app->settings_menu->high_resolution->rect, NULL);
    return ;
}
