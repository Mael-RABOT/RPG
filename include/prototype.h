/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** prototype
*/

#ifndef BASE_REPO_PROTOTYPE_H
    #define BASE_REPO_PROTOTYPE_H

    #include "include.h"

    /* main */
    int my_rpg(const int ac, const char **av);
    int gloop(app_t *app);

    /* window */
    sfRenderWindow *create_window(sfVideoMode videomode, const char *title);

    /* app */
    app_t *create_app(sfVideoMode videomode);

    /* splash_screen */
    splash_screen_t *create_splash_screen(sfRenderWindow *window);
    int splash_screen(app_t *app, sfRenderWindow *window,
    splash_screen_t *splash_screen);
    int skip_splash_screen(app_t *app);

    /* update_splash_screen */
    int update_ruined_back(sfRenderWindow *window,
    splash_screen_t *splash_screen);
    int update_ruined_fore(sfRenderWindow *window,
    splash_screen_t *splash_screen);
    int update_title(sfRenderWindow *window, splash_screen_t *splash_screen);
    int update_skip(sfRenderWindow *window, splash_screen_t *splash_screen);

    /* clean_splash_screen */
    int clean_splash_screen(app_t *app);

    /* event */
    int main_event(app_t *app);

    /* fps */
    void show_fps(app_t *app);
    void get_fps(app_t *app);
    char *my_int_to_str(int nb);

#endif //BASE_REPO_PROTOTYPE_H
