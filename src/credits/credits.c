/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** credits
*/

#include "../../include/prototype.h"

static void credits_event(app_t *app)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(app->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(app->window);
    }
}

void credits(app_t *app)
{
    app->menu->state = credits_screen;
    sfRenderWindow_setView(app->window, app->default_view);
    sprite_t *credit = create_sprite(CREDITS);
    sfClock *timer = sfClock_create();
    sfVector2f pos = (sfVector2f){0.0f, 0.0f};
    while (sfRenderWindow_isOpen(app->window) && pos.y > -6500) {
        credits_event(app);
        sfRenderWindow_clear(app->window, sfBlack);
        if ((float )sfClock_getElapsedTime(timer).microseconds / TIME_DIVIDER
        > 0.02) {
            pos.y -= 3;
            sfSprite_setPosition(credit->sprite, pos);
            sfClock_restart(timer);
        }
        sfRenderWindow_drawSprite(app->window, credit->sprite, NULL);
        sfRenderWindow_display(app->window);
    }
    sfClock_destroy(timer);
    app->menu->state = main_menu;
}
