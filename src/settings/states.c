/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** display_settings_menu
*/

#include "../../include/prototype.h"

int settings_menu_click(settings_menu_t *settings_menu,
    sfMouseButtonEvent *button_event)
{
    settings_menu->sounds_more->is_clicked(settings_menu->sounds_more,
    button_event);
    settings_menu->sounds_less->is_clicked(settings_menu->sounds_less,
    button_event);
    settings_menu->music_more->is_clicked(settings_menu->music_more,
    button_event);
    settings_menu->music_less->is_clicked(settings_menu->music_less,
    button_event);
    settings_menu->full_screen->is_clicked(settings_menu->full_screen,
    button_event);
    settings_menu->windowded->is_clicked(settings_menu->windowded,
    button_event);
    settings_menu->low_resolution->is_clicked(settings_menu->low_resolution,
    button_event);
    settings_menu->high_resolution->is_clicked(settings_menu->high_resolution,
    button_event);
    return 0;
}

int settings_menu_release(settings_menu_t *settings_menu,
    sfMouseButtonEvent *button_event)
{
    settings_menu->sounds_more->is_released(settings_menu->sounds_more,
    button_event);
    settings_menu->sounds_less->is_released(settings_menu->sounds_less,
    button_event);
    settings_menu->music_more->is_released(settings_menu->music_more,
    button_event);
    settings_menu->music_less->is_released(settings_menu->music_less,
    button_event);
    settings_menu->full_screen->is_released(settings_menu->full_screen,
    button_event);
    settings_menu->windowded->is_released(settings_menu->windowded,
    button_event);
    settings_menu->low_resolution->is_released(settings_menu->low_resolution,
    button_event);
    settings_menu->high_resolution->is_released(settings_menu->high_resolution,
    button_event);
    return 0;
}

int settings_menu_hover(settings_menu_t *settings_menu,
    sfMouseMoveEvent *move_event)
{
    settings_menu->sounds_more->is_hover(settings_menu->sounds_more,
    move_event);
    settings_menu->sounds_less->is_hover(settings_menu->sounds_less,
    move_event);
    settings_menu->music_more->is_hover(settings_menu->music_more,
    move_event);
    settings_menu->music_less->is_hover(settings_menu->music_less,
    move_event);
    settings_menu->full_screen->is_hover(settings_menu->full_screen,
    move_event);
    settings_menu->windowded->is_hover(settings_menu->windowded,
    move_event);
    settings_menu->low_resolution->is_hover(settings_menu->low_resolution,
    move_event);
    settings_menu->high_resolution->is_hover(settings_menu->high_resolution,
    move_event);
    return 0;
}
