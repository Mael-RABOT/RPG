/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** buttons
*/

#include "../../include/prototype.h"

void adjust_music_volume(app_t *app, sfMusic* music, float increment)
{
    float volume = sfMusic_getVolume(music);

    volume += increment;
    if (volume < 0.0f)
        volume = 0.0f;
    if (volume > 100.0f)
        volume = 100.0f;
    sfMusic_setVolume(music, volume);
    app->settings_menu->music_more->state = NONE;
    app->settings_menu->music_less->state = NONE;
    return;
}

void adjust_global_volume(app_t *app, float increment)
{
    float volume = sfListener_getGlobalVolume();

    volume += increment;
    if (volume < 0.0f)
        volume = 0.0f;
    if (volume > 100.0f)
        volume = 100.0f;
    sfListener_setGlobalVolume(volume);
    app->settings_menu->sounds_more->state = NONE;
    app->settings_menu->sounds_less->state = NONE;
    return;
}

void resize_window(app_t *app, sfVector2u size)
{
    sfRenderWindow_setSize(app->window, size);
    app->settings_menu->high_resolution->state = NONE;
    app->settings_menu->low_resolution->state = NONE;
    return;
}

void toggle_fullscreen(app_t *app, sfBool is_fullscreen)
{
    sfVideoMode mode = {1920, 1080, 32};

    if (!is_fullscreen) {
        sfRenderWindow_close(app->window);
        sfRenderWindow_destroy(app->window);
        app->window = sfRenderWindow_create(mode, "my_rpg", sfFullscreen, NULL);
        app->settings_menu->full_screen->state = NONE;
    } else {
        sfRenderWindow_close(app->window);
        app->window = sfRenderWindow_create(mode, "my_rpg", sfDefaultStyle,
        NULL);
        app->settings_menu->windowded->state = NONE;
    }
    return;
}

int settings_menu_buttons_actions(app_t *app)
{
    if (IS_RELEASED(app->settings_menu->sounds_more->state))
        adjust_global_volume(app, 5);
    if (IS_RELEASED(app->settings_menu->sounds_less->state))
        adjust_global_volume(app, -5);
    if (IS_RELEASED(app->settings_menu->music_more->state))
        adjust_music_volume(app, app->music_handler->music, 5);
    if (IS_RELEASED(app->settings_menu->music_less->state))
        adjust_music_volume(app, app->music_handler->music, -5);
    if (IS_RELEASED(app->settings_menu->full_screen->state))
        toggle_fullscreen(app, sfFalse);
    if (IS_RELEASED(app->settings_menu->windowded->state))
        toggle_fullscreen(app, sfTrue);
    if (IS_RELEASED(app->settings_menu->low_resolution->state))
        resize_window(app, (sfVector2u){800, 600});
    if (IS_RELEASED(app->settings_menu->high_resolution->state))
        resize_window(app, (sfVector2u){1920, 1080});
    return 0;
}
