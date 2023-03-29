/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** main_event.c
*/

#include "../../include/prototype.h"

int main_menu_event(main_menu_t *main_menu, sfMouseButtonEvent button_event,
sfMouseMoveEvent move_event)
{
    is_button_clicked(main_menu->play, &button_event);
    is_button_released(main_menu->play, &button_event);
    is_button_hover(main_menu->play, &move_event);

    is_button_clicked(main_menu->resume, &button_event);
    is_button_released(main_menu->resume, &button_event);
    is_button_hover(main_menu->resume, &move_event);

    is_button_clicked(main_menu->settings, &button_event);
    is_button_released(main_menu->settings, &button_event);
    is_button_hover(main_menu->settings, &move_event);

    is_button_clicked(main_menu->quit, &button_event);
    is_button_released(main_menu->quit, &button_event);
    is_button_hover(main_menu->quit, &move_event);

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
        if (app->state == main_menu && (event.type == sfEvtMouseButtonPressed ||
        event.type == sfEvtMouseButtonReleased ||
        event.type == sfEvtMouseMoved))
            main_menu_event(app->main_menu, event.mouseButton, event.mouseMove);
    }
    return 0;
}
