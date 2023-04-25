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

    void set_1920_1080(app_t *app);
    void set_800_400(app_t *app);

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

    int destroy_settings_menu(settings_menu_t *sm);

    /* splash_screen */
    splash_screen_t *create_splash_screen(sfRenderWindow *window);
    int splash_screen(app_t *app, sfRenderWindow *window,
    splash_screen_t *splash_screen);
    int skip_splash_screen(app_t *app);

    int update_ruined_back(sfRenderWindow *window,
    splash_screen_t *splash_screen);
    int update_ruined_fore(sfRenderWindow *window,
    splash_screen_t *splash_screen);
    int update_title(sfRenderWindow *window, splash_screen_t *splash_screen);
    int update_skip(sfRenderWindow *window, splash_screen_t *splash_screen);

    int destroy_splash_screen(splash_screen_t *splash_screen);

    /* main_menu */
    main_menu_t *create_main_menu(sfRenderWindow *window);
    int display_main_menu(app_t *app);
    void play(app_t *app);
    void resume(app_t *app);
    void settings_b(app_t *app);
    void quit(app_t *app);

    int update_all_buttons_textures(app_t *app);
    int main_menu_buttons_actions(app_t *app);

    int destroy_main_menu(main_menu_t *mm);

    /* escape menu */
    void launch_main_menu(app_t *app);
    escape_menu_t *create_escape_menu(sfRenderWindow *window);
    int display_escape_menu(app_t *app, escape_menu_t *escape_menu);
    void launch_setting(app_t *app);

    int destroy_escape_menu(escape_menu_t *em);

#endif //MENU_H_
