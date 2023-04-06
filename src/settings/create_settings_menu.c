/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_settings_menu
*/

#include "../../include/prototype.h"

void nothing(app_t *app)
{
    return;
}

settings_menu_t *create_settings_menu(sfRenderWindow *window)
{
    settings_menu_t *settings_menu = malloc(sizeof(settings_menu_t));
    object_info_t button_info;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    settings_menu->button = NULL;
    settings_menu->background = create_sprite(SETTINGS_BACKGROUND);
    sound_settings(settings_menu, button_info, window_size);
    music_settings(settings_menu, button_info, window_size);
    resolution_settings(settings_menu, button_info, window_size);
    //update_settings_menu(settings_menu, window);
    return settings_menu;
}
