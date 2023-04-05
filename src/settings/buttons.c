/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** buttons
*/

#include "../../include/prototype.h"

void adjust_music_volume(sfMusic* music, float increment)
{
    float volume = sfMusic_getVolume(music);

    volume += increment;
    if (volume < 0.0f)
        volume = 0.0f;
    if (volume > 100.0f)
        volume = 100.0f;
    sfMusic_setVolume(music, volume);
    return;
}

void adjust_global_volume(float increment)
{
    float volume = sfListener_getGlobalVolume();

    volume += increment;
    if (volume < 0.0f)
        volume = 0.0f;
    if (volume > 100.0f)
        volume = 100.0f;
    sfListener_setGlobalVolume(volume);
    return;
}

void resize_window(sfRenderWindow* window, sfVector2u size)
{
    sfRenderWindow_setSize(window, size);
    return;
}

void toggle_fullscreen(sfRenderWindow* window)
{
    sfRenderWindow_setSize(window, (sfVector2u){1920, 1080});
    return;
}

int settings_menu_buttons_actions(app_t *app)
{
    if (IS_RELEASED(app->settings_menu->sounds_more->state))
        adjust_global_volume(5);
    if (IS_RELEASED(app->settings_menu->sounds_less->state))
        adjust_global_volume(-5);
    if (IS_RELEASED(app->settings_menu->music_more->state))
        adjust_music_volume(app->music_handler->music, 5);
    if (IS_RELEASED(app->settings_menu->music_less->state))
        adjust_music_volume(app->music_handler->music, -5);
    if (IS_RELEASED(app->settings_menu->full_screen->state))
        toggle_fullscreen(app->window);
    if (IS_RELEASED(app->settings_menu->windowded->state))
        toggle_fullscreen(app->window);
    if (IS_RELEASED(app->settings_menu->low_resolution->state))
        resize_window(app->window, (sfVector2u){800, 600});
    if (IS_RELEASED(app->settings_menu->high_resolution->state))
        resize_window(app->window, (sfVector2u){1920, 1080});
    return 0;
}
