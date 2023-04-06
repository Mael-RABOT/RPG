/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** character_selection
*/

#include "../../include/prototype.h"

static void event_character(app_t *app)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(app->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(app->window);
    }
}

void character_selection(app_t *app)
{
    app->state = character_stat_selection;
    while (sfRenderWindow_isOpen(app->window)
        && app->state == character_stat_selection) {
        sfRenderWindow_clear(app->window, sfBlack);
        sfRenderWindow_display(app->window);
    }
}
