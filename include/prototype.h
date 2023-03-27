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
    int splash_screen(sfRenderWindow *window, splash_screen_t *splash_screen);

    /* event */
    int main_event(app_t *app);

#endif //BASE_REPO_PROTOTYPE_H
