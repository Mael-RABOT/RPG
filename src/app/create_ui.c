/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** create_ui.c
*/

#include "../../include/prototype.h"

int create_ui(app_t *app)
{
    app->interact = create_sprite("./assets/interact.png");
    sfSprite_setPosition(app->interact->sprite, (sfVector2f){16, 16});
    sfSprite_setScale(app->interact->sprite, (sfVector2f){0.3, 0.3});
    return 0;
}
