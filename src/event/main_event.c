/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** main_event.c
*/

#include "../../include/prototype.h"

int main_menu_events(app_t *app, sfEvent event)
{
    if (app->state == main_menu && event.type == sfEvtMouseButtonPressed)
        main_menu_click(app->main_menu,  &event.mouseButton);
    if (app->state == main_menu && event.type == sfEvtMouseButtonReleased)
        main_menu_release(app->main_menu,  &event.mouseButton);
    if (app->state == main_menu && event.type == sfEvtMouseMoved)
        main_menu_hover(app->main_menu,  &event.mouseMove);
    update_all_buttons_textures(app);
    main_menu_buttons_actions(app);
    return 0;
}

int main_event(app_t *app)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(app->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(app->window);
        if (app->state == splash && event.type == sfEvtKeyPressed)
            skip_splash_screen(app);
        if (app->state == main_menu)
            main_menu_events(app, event);
    }
    return 0;
}
