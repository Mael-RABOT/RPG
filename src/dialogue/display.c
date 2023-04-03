/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** display
*/

#include "../../include/prototype.h"

void display_game_dialogue(app_t *app)
{
    display_background(app);
    display_map(app->window, app->maps->selected_map, app->player);
}

void display_dialogue(app_t *app, sprite_t *background)
{
    sfRenderWindow_drawSprite(app->window, background->sprite, NULL);
    update_cursor(app);
}
