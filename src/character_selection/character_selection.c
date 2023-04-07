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

static void display_character_stats(app_t *app, sprite_t *background)
{
    sfRenderWindow_drawSprite(app->window, background->sprite, NULL);
    update_cursor(app);
}

void character_selection(app_t *app)
{
    app->state = character_stat_selection;
    sprite_t *background = create_sprite("./assets/backgrounds/character_stats.png");
    while (sfRenderWindow_isOpen(app->window)
        && app->state == character_stat_selection) {
        event_character(app);
        sfRenderWindow_clear(app->window, sfBlack);
        display_character_stats(app, background);
        sfRenderWindow_display(app->window);
    }
}
