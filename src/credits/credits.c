/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** credits
*/

#include "../../include/prototype.h"

void credits(app_t *app)
{
    sfBool credits_playing = sfTrue;
    while (sfRenderWindow_isOpen(app->window) && credits_playing) {
        credits_playing = sfFalse;
    }
    app->state = main_menu;
}
