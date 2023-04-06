/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** buttons
*/

#include "../../include/prototype.h"

void resize_window(app_t *app)
{
    sfRenderWindow_setSize(app->window, size);
    app->settings_menu->high_resolution->state = NONE;
    app->settings_menu->low_resolution->state = NONE;
    sfRenderWindow_setPosition(app->window, (sfVector2i){0, 0});
    return;
}

void toggle_fullscreen(app_t *app, sfBool is_fullscreen)
{
    sfVideoMode mode = {1920, 1080, 32};

    sfRenderWindow_close(app->window);
    sfRenderWindow_destroy(app->window);
    if (is_fullscreen == sfFalse) {
        app->window = sfRenderWindow_create(mode, "my_rpg", sfFullscreen, NULL);
        app->settings_menu->full_screen->state = NONE;
    } else {
        app->window = sfRenderWindow_create(mode, "my_rpg", sfClose, NULL);
        app->settings_menu->windowded->state = NONE;
        sfRenderWindow_setPosition(app->window, (sfVector2i){0, 0});
    }
    sfRenderWindow_setMouseCursorVisible(app->window, sfFalse);
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
        resize_window(app, (sfVector2u){854, 480});
    if (IS_RELEASED(app->settings_menu->high_resolution->state))
        resize_window(app, (sfVector2u){1920, 1080});
    return 0;
}
