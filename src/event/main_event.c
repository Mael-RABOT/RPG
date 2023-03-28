/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** main_event.c
*/

#include "../../include/prototype.h"

int main_event(app_t *app)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(app->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(app->window);
        if (app->state == splash && event.type == sfEvtKeyPressed)
            skip_splash_screen(app);
    }
    return 0;
}
