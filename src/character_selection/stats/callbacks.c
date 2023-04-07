/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** callbacks
*/

#include "../../../include/prototype.h"

void stat_default_button(app_t *app)
{
    apply_default(app->player->stat);
    app->state = game;
}

void stat_strength_button(app_t *app)
{
    apply_strength(app->player->stat);
    app->state = game;
}
void stat_dexterity_button(app_t *app)
{
    apply_dexterity(app->player->stat);
    app->state = game;
}
