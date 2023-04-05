/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** update_textures
*/

#include "../../include/prototype.h"

int update_all_settings_buttons_textures(app_t *app)
{
    update_buttons_textures(app->settings_menu->sounds_more);
    update_buttons_textures(app->settings_menu->sounds_less);
    update_buttons_textures(app->settings_menu->music_more);
    update_buttons_textures(app->settings_menu->music_less);
    update_buttons_textures(app->settings_menu->full_screen);
    update_buttons_textures(app->settings_menu->windowded);
    update_buttons_textures(app->settings_menu->low_resolution);
    update_buttons_textures(app->settings_menu->high_resolution);
    return 0;
}
