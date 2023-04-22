/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** menu.h
*/

#include "../prototype.h"

#ifndef MENU_H_
    #define MENU_H_

    typedef struct splash_screen {
        sprite_t *ruined_back;
        sprite_t *ruined_fore;
        sprite_t *title;
        sprite_t *skip;
        int fade_index;
        int fade_index_skip;
        int increment;
        sfClock *clock;
        sfTime time;
        float seconds;
    } splash_screen_t;

    typedef struct settings_menu {
        sprite_t *background;
        sprite_t *text_sounds;
        sprite_t *text_resolution;
        sprite_t *sounds;
        sprite_t *music;
        button_t **button;
    } settings_menu_t;

    typedef struct main_menu {
        button_t **button;
        sprite_t *ruined_city;
        sprite_t *title;
        int fade_index;
    } main_menu_t;

    typedef struct escape_menu {
        button_t **button;
    } escape_menu_t;

    /* Settings */
    settings_menu_t *create_settings_menu(sfRenderWindow *window);
    void display_settings_menu(sfRenderWindow *window, settings_menu_t *menu);
    void update_settings_menu(settings_menu_t *, sfRenderWindow *);

    void toggle_windowed(app_t *app);
    void toggle_borderless(app_t *app);
    void toggle_fullscreen(app_t *app);

    void increase_music_volume(app_t *app);
    void decrease_music_volume(app_t *app);
    void increase_global_volume(app_t *app);
    void decrease_global_volume(app_t *app);

    void nothing(app_t *app);

    void sound_settings(settings_menu_t *settings_menu, object_info_t
        button_info, sfVector2u window_size);
    void music_settings(settings_menu_t *settings_menu, object_info_t
        button_info, sfVector2u window_size);
    void resolution_settings(settings_menu_t *settings_menu,
        object_info_t button_info, sfVector2u window_size);

#endif //MENU_H_
